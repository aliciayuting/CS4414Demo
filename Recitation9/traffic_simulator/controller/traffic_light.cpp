#include "traffic_light.hpp"

namespace controller {
uint32_t compute_green_time(const uint32_t counter);

const uint32_t traffic_light::yellow_time = 10;
uint32_t traffic_light::total_lights = 0;

traffic_light::traffic_light(const std::string& name)
        : name(name),
          green_time(compute_green_time(total_lights)) {
    total_lights++;
}

COLOR traffic_light::next_color() {
    return color = (COLOR)((color + 1) % num_colors);
}

uint32_t traffic_light::get_green_time() const {
    return green_time;
}

std::string traffic_light::get_name() const {
    return name;
}

COLOR traffic_light::get_color() const {
    return color;
}

uint32_t compute_green_time(const uint32_t counter) {
    if(counter % 25 == 0) {
        return 90;
    }
    if(counter % 25 < 15) {
        return 60;
    }
    return 30;
}

void traffic_light::print_csv(std::ofstream& fout) const {
    fout << name << "," << COLORS[color] << "\n";
}
}  // namespace controller
