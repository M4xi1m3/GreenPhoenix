#include <iostream>

#include "stde/log/log.hpp"
#include "stde/net/init.hpp"
#include "gpnet/TCPServer.hpp"
#include "gpprotocol/ProtocolHandler.hpp"

int main(int argc, char** argv) {
    stde::net::init();

    gp::net::TCPServer<gp::protocol::ProtocolHandler> serv("127.0.0.1", 25565);
    serv.start();

    // TODO: Proper console.
    std::string s;
    std::getline(std::cin, s);
    serv.stop();

    stde::net::deinit();
    stde::log::log::clean();
}
