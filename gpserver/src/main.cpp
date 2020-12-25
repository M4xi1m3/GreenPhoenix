#include <iostream>

#include "gpnet/TCPServer.hpp"

int main(int argc, char** argv) {
    gp::net::TCPServer serv("127.0.0.1", 12345);
    serv.start();

    std::string s;
    std::getline(std::cin, s);
    serv.stop();
}

