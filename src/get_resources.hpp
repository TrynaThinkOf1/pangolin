#ifndef _GET_RESOURCES_HPP
#define _GET_RESOURCES_HPP
#include <string>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

extern const std::string contacts_path, emojis_path;

std::string get_file_as_string(const std::string& path);
json get_emojis();
json get_contacts();

#endif