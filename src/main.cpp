#include <iostream>
#include <string>
#include "sys/socket.h"
#include "netinet/in.h"

#include <Metal/Metal.hpp>
//#include <Appkit/Appkit.hpp>
//#include <Metalkit/Metalkit.hpp>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "get_resources.hpp"

#define PORT 4500

const std::string contacts_path = "./resources/contacts.json";
const std::string emojis_path = "./resources/emojis.json";

json emojis = get_emojis();
json contacts = get_contacts();

int main() {
    return 0;
}