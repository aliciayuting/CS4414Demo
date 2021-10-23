#pragma once

#include <compare>
#include <cstdint>

// the event type for the simulator
class event {
public:
    // constructor
    event(const uint32_t controller_index, const uint32_t time = 0);

    // operator to compare events
    std::strong_ordering operator<=>(const event& other) const;

    // return index
    uint32_t get_index() const;
    // return time
    uint32_t get_time() const;

private:
    // index in the vector of all controller objects
    uint32_t controller_index;
    // time when the event will take place
    uint32_t time;
};
