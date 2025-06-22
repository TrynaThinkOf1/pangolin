#include <iostream>
#include "sys/socket.h"
#include "netinet/in.h"

#include "get_resources.cpp"

#define PORT 4500
#define contacts_path = "./resources/contacts.json"
#define emojis_path = "./resources/emojis.json"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);


    return 0;
}