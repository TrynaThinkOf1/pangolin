#include "get_resources.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <iterator>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

std::string get_file_as_string(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << path << std::endl;
        exit(1);
    }

    std::string content = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    return content;
}

json get_emojis() {
    std::string emojis_file = get_file_as_string(emojis_path);

    json emojis_json = json::parse(emojis_file);
    return emojis_json;
}

json get_contacts() {
    std::string contacts_file = get_file_as_string(contacts_path);

    json contacts_json = json::parse(contacts_file);
    return contacts_json;
}