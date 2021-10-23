#include <fstream>
#include <iostream>
#include <queue>

#include "controller/traffic_controller.hpp"
#include "csv/csv_reader.hpp"
#include "event.hpp"

std::vector<controller::traffic_controller> initialize_controllers(const std::string& csv_file_name);
std::priority_queue<event> create_events(const uint32_t total_events);

void print_kml_header(std::ofstream& fout);
void print_icons(std::ofstream& fout);
void print_kml_footer(std::ofstream& fout);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Usage: ./<exec> -t=<time>" << std::endl;
        return 0;
    }

    uint32_t total_time = std::stoi(std::string(argv[1]).substr(3));

    std::vector<controller::traffic_controller> controllers
            = initialize_controllers("Traffic_Signals_SF.csv");

    std::priority_queue<event> events = create_events(controllers.size());

    while(!events.empty()) {
        const event current = events.top();
        events.pop();
        uint32_t next_time = current.get_time() + controllers[current.get_index()].transition();
        if(next_time <= total_time) {
            events.emplace(current.get_index(), next_time);
        }
    }

    {
        std::ofstream fout("myfile.csv");
        fout << "CCN,street name,color\n";
        for(const controller::traffic_controller& controller : controllers) {
            controller.print_csv(fout);
        }
    }

    {
        std::ofstream fout("myfile.kml");
        print_kml_header(fout);
        print_icons(fout);
        for(const controller::traffic_controller& controller : controllers) {
            controller.print_kml(fout);
        }
        print_kml_footer(fout);
    }
}

std::vector<controller::traffic_controller> initialize_controllers(const std::string& csv_file_name) {
    std::vector<controller::traffic_controller> controllers;

    const uint32_t CNN_INDEX = 0;
    const uint32_t TBC_INDEX = 12;
    const uint32_t STREET1_INDEX = 3;
    const uint32_t STREET2_INDEX = 4;
    const uint32_t STREET3_INDEX = 6;
    const uint32_t STREET4_INDEX = 8;
    const uint32_t SHAPE_INDEX = 34;

    std::ifstream fin(csv_file_name);
    std::string line;
    // read away the header line
    std::getline(fin, line);

    while(std::getline(fin, line)) {
        csv::fields_t fields = csv::parse_csv_fields(line);
        if(fields[TBC_INDEX] == "GPS") {
            std::vector<std::string> street_names;
            street_names.push_back(fields[STREET1_INDEX]);
            street_names.push_back(fields[STREET2_INDEX]);
            if(fields[STREET3_INDEX] != "") {
                street_names.push_back(fields[STREET3_INDEX]);
            }
            if(fields[STREET4_INDEX] != "") {
                street_names.push_back(fields[STREET4_INDEX]);
            }

            controllers.emplace_back(std::stoi(fields[CNN_INDEX]), street_names, fields[SHAPE_INDEX]);
        }
    }

    return controllers;
}

std::priority_queue<event> create_events(const uint32_t total_events) {
    std::priority_queue<event> events;

    for(uint32_t i = 0; i < total_events; ++i) {
        events.emplace(i);
    }

    return events;
}

void print_kml_header(std::ofstream& fout) {
    fout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    fout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n";
    fout << "<Document>\n";
}

void print_icons_helper(std::ofstream& fout,
                        const std::string& id, const std::string& file_name) {
    fout << "  <Style id=\"" << id << "\">\n";
    fout << "    <IconStyle id=\"" << id << "\">\n";
    fout << "      <Icon>\n";
    fout << "        <href>" << file_name << "</href>\n";
    fout << "        <scale>1.0</scale>\n";
    fout << "      </Icon>\n";
    fout << "    </IconStyle>\n";
    fout << "  </Style>\n";
}

void print_icons(std::ofstream& fout) {
    for(const std::string& color1 : controller::SHORT_COLORS) {
        for(const std::string& color2 : controller::SHORT_COLORS) {
            std::string id = "i2" + color1 + color2;
            std::string file_name = "files/i2" + color1 + color2 + ".png";
            print_icons_helper(fout, id, file_name);

            for(const std::string& color3 : controller::SHORT_COLORS) {
                std::string id = "i3" + color1 + color2 + color3;
                std::string file_name = "files/i3" + color1 + color2 + color3 + ".png";
                print_icons_helper(fout, id, file_name);

                for(const std::string& color4 : controller::SHORT_COLORS) {
                    std::string id = "i4" + color1 + color2 + color3 + color4;
                    std::string file_name = "files/i4" + color1 + color2 + color3 + color4 + ".png";
                    print_icons_helper(fout, id, file_name);
                }
            }
        }
    }
}

void print_kml_footer(std::ofstream& fout) {
    fout << "</Document>\n";
    fout << "</kml>\n";
}
