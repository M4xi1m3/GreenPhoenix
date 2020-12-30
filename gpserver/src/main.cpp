#include <iostream>
#include <mutex>

#include "stde/log/log.hpp"
#include "stde/net/init.hpp"

int main(int argc, char** argv) {
    stde::net::init();

    // gp::net::TCPServer<gp::protocol::ProtocolHandler<Test>> serv("127.0.0.1", 25565);
    // serv.start();

    // TODO: Proper console.
    std::string s;
    std::getline(std::cin, s);
    // client.stop();

    stde::net::deinit();
    stde::log::log::clean();
}
