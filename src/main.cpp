#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "get_resources.hpp"
#include "connections/connect.hpp"

const std::string contacts_path = "./resources/contacts.json";
const std::string emojis_path = "./resources/emojis.json";

json _emojis = get_emojis();
json* emojis = &_emojis;
json _contacts = get_contacts();
json* contacts = &_contacts;

int main() {
    int sock = listen_for_conn();
    char buffer[1024];

    read(sock, buffer, 1024);
    std::cout << buffer << std::endl;
    close(sock);

    return 0;
}