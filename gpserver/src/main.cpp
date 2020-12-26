#include <iostream>

#include "stde/log/log.hpp"
#include "stde/net/init.hpp"
#include "gpnet/TCPServer.hpp"
#include "TestHandler.hpp"

int main(int argc, char** argv) {
    stde::net::init();

    gp::net::TCPServer<TestHandler> serv("127.0.0.1", 12345);
    serv.start();

    std::string s;
    std::getline(std::cin, s);
    serv.stop();

    stde::net::deinit();
    stde::log::log::clean();
}
