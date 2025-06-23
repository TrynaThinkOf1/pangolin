#include <iostream>
#include <string>
#include "sys/socket.h"
#include "netinet/in.h"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "get_resources.hpp"

#define PORT 4500

const std::string contacts_path = "./resources/contacts.json";
const std::string emojis_path = "./resources/emojis.json";

int main() {
    json emojis = get_emojis();
    json contacts = get_contacts();
    std::cout << emojis.dump(2) << std::endl; // the arg passed to .dump is the tab size
    std::cout << contacts.dump(2) << std::endl;

    return 0;
}