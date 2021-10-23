#include "traffic_controller.hpp"

#include "color.hpp"

namespace controller {
traffic_controller::traffic_controller(const uint32_t cnn,
                                       const std::vector<std::string>& names,
                                       const std::string& location)
        : cnn(cnn),
          location(location) {
    for(const std::string& name : names) {
        lights.emplace_back(name);
    }
}

uint32_t traffic_controller::transition() {
    COLOR color = lights[cur_light].next_color();

    switch(color) {
        case COLOR::RED:
            cur_light = (cur_light + 1) % lights.size();
            lights[cur_light].next_color();
            return lights[cur_light].get_green_time();
        case COLOR::GREEN:
            return lights[cur_light].get_green_time();
        default:
            return traffic_light::yellow_time;
    }
}

void traffic_controller::print_csv(std::ofstream& fout) const {
    for(const traffic_light& light : lights) {
        fout << cnn << ",";
        light.print_csv(fout);
    }
}

void traffic_controller::print_kml(std::ofstream& fout) const {
    fout << "  <Placemark>\n";
    fout << "    <name>" << cnn << "</name>\n";

    std::string description;
    std::string icon_name = "i" + std::to_string(lights.size());
    for(uint32_t i = 0; i < lights.size() - 1; ++i) {
        description += lights[i].get_name() + " and ";
        icon_name += SHORT_COLORS[lights[i].get_color()];
    }
    description += lights.back().get_name();
    icon_name += SHORT_COLORS[lights.back().get_color()];

    fout << "    <description>" << description << "</description>\n";
    fout << "    <styleUrl>#" << icon_name << "</styleUrl>\n";

    size_t pos = location.find_first_of(' ', 7);
    std::string coord1 = location.substr(7, pos - 7);
    std::string coord2 = location.substr(pos + 1,
                                         location.find_first_of(')') - pos - 1);
    fout << "    <Point>\n";
    fout << "      <coordinates>" << coord1 << "," << coord2 << "</coordinates>\n";
    fout << "    </Point>\n";

    fout << "  </Placemark>\n";
}

}  // namespace controller
