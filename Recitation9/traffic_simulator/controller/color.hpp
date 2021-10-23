#pragma once

#include <string>
#include <vector>

namespace controller {
// color possibilities for a traffic light
enum COLOR {
    RED = 0,
    GREEN,
    YELLOW
};

// list of all colors
static const std::vector<std::string> COLORS = {"RED", "GREEN", "YELLOW"};
// shorthand names for representing file and icon names
static const std::vector<std::string> SHORT_COLORS = {"r", "g", "y"};
// total number of colors
static const uint32_t num_colors = 3;
}  // namespace controller
