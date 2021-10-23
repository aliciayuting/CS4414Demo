#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "traffic_light.hpp"

namespace controller {
// models an intersection
class traffic_controller {
public:
    // constructor
    traffic_controller(const uint32_t cnn,
                       const std::vector<std::string>& names,
                       const std::string& location, bool sync);

    void initialization(int start_time);

    // change the street lights according to the circular logic
    uint32_t transition();

    // print csv info
    void print_csv(std::ofstream& fout) const;
    // print kml info
    void print_kml(std::ofstream& fout) const;

private:
    // identifier for the controller
    const uint32_t cnn;

    // list of all lights at the controller
    std::vector<traffic_light> lights;
    // current light to operate on
    // for changing colors
    int cur_light = 0;

    bool sync = false;

    // coordinates given in the CSV file
    const std::string location;
};
}  // namespace controller
