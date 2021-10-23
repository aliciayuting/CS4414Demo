#include "csv_reader.hpp"

#include <regex>

namespace csv {
fields_t parse_csv_fields_regex(const std::string& record);
fields_t parse_csv_fields_string(const std::string& record);

fields_t parse_csv_fields(const std::string& record) {
    return parse_csv_fields_regex(record);
}

fields_t parse_csv_fields_regex(const std::string& record) {
    fields_t fields;

    // source https://stackoverflow.com/questions/35085680/regex-pattern-to-extract-empty-field-from-csv-file
    const std::regex field_regex("(\"([^\"]*)\"|([^,]*))(,|$)");

    for(std::sregex_iterator iter = std::sregex_iterator(record.begin(), record.end(), field_regex); iter != std::sregex_iterator(); ++iter) {
        std::smatch match = *iter;
        fields.push_back(match[2].length() ? match[2].str() : match[3].str());
        if(match[4].length() == 0) {
            break;
        }
    }
    return fields;
}

fields_t parse_csv_fields_string(const std::string& record) {
    fields_t fields;

    size_t cur_pos = 0;
    while(cur_pos < record.size()) {
        if(record[cur_pos] == '"') {
            size_t next_pos = record.find_first_of('"', cur_pos + 1);
            fields.push_back(record.substr(cur_pos + 1, next_pos - 1 - cur_pos));
            cur_pos = next_pos + 2;
        } else {
            size_t next_pos = record.find_first_of(',', cur_pos);
            if(next_pos == std::string::npos) {
                fields.push_back(record.substr(cur_pos));
                break;
            } else {
                fields.push_back(record.substr(cur_pos, next_pos - cur_pos));
                cur_pos = next_pos + 1;
            }
        }
    }
    return fields;
}
}  // namespace csv
