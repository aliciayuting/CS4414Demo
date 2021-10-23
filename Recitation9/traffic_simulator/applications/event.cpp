#include "event.hpp"

event::event(const uint32_t controller_index, const uint32_t time)
        : controller_index(controller_index),
          time(time) {
}

bool event::operator<(const event& other) const {
    return other.time < time;
}

uint32_t event::get_index() const {
    return controller_index;
}
uint32_t event::get_time() const {
    return time;
}
