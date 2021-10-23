#pragma once

#include <string>
#include <vector>

namespace csv {
typedef std::vector<std::string> fields_t;

// parse the given string to return a vector of strings
fields_t parse_csv_fields(const std::string& record);
}  // namespace csv
