#include "connect.hpp"

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 4500

int listen_for_conn() {
    int sockfd, new_sock;
    struct sockaddr_in addr;
    int opt = 1;
    int addrlen = sizeof(addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        std::cout << "ERROR opening socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cout << "ERROR on binding" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 1) < 0) {
        std::cout << "ERROR on listening" << std::endl;
        exit(EXIT_FAILURE);
    }

    new_sock = accept(sockfd, (struct sockaddr *)&addr, (socklen_t*)&addrlen);
    if (new_sock < 0) {
        std::cout << "ERROR on accept" << std::endl;
        exit(EXIT_FAILURE);
    }

    return new_sock;
}