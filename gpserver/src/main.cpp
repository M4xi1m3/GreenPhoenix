#include <iostream>

#include "stde/log/log.hpp"
#include "stde/net/init.hpp"
#include "gpnet/TCPServer.hpp"
#include "gpprotocol/ProtocolHandler.hpp"
#include "gpprotocol/PacketHander.hpp"
#include "gpprotocol/Packet.hpp"
#include "gpprotocol/Packets.hpp"

class Test: public gp::protocol::PacketHandler {
public:
    Test() {

    }

    virtual ~Test() {

    }

    virtual void handle(gp::protocol::Packet* packet) {
        gp::protocol::packets::PacketFFKick p;
        p.reason = "Hello world!";
        send(p);
        close();
    }

    virtual void stop() {
        gp::protocol::packets::PacketFFKick p;
        p.reason = "Server stopping!";
        send(p);
    }
};

int main(int argc, char** argv) {
    stde::net::init();

    gp::net::TCPServer<gp::protocol::ProtocolHandler<Test>> serv("127.0.0.1", 25565);
    serv.start();

    // TODO: Proper console.
    std::string s;
    std::getline(std::cin, s);
    serv.stop();

    stde::net::deinit();
    stde::log::log::clean();
}
