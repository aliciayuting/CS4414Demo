#pragma once

#include <fstream>
#include <string>

#include "color.hpp"

namespace controller {
// models a street light at any intersection
class traffic_light {
public:
    // initialize with the name of the street
    traffic_light(const std::string& name);

    // red -> green, green -> yellow, yellow -> red
    // return the new color
    COLOR next_color();
    // retrun green_time
    uint32_t get_green_time() const;

    // return name
    std::string get_name() const;
    // return color
    COLOR get_color() const;

    // print to csv file
    void print_csv(std::ofstream& fout) const;

    // time for which any light will be yellow
    static const uint32_t yellow_time;
    // total number of lights
    // used to determine the green time
    static uint32_t total_lights;

private:
    // name of the street
    const std::string name;
    // color of the light
    COLOR color = COLOR::RED;
    // time for which the light will be green
    uint32_t green_time;
};

}  // namespace controller
