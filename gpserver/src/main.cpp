#include <iostream>

#include "stde/log/log.hpp"
#include "stde/net/init.hpp"
#include "gpnet/TCPServer.hpp"
#include "gpnet/TCPClient.hpp"
#include "gpprotocol/ProtocolHandler.hpp"
#include "gpprotocol/PacketHander.hpp"
#include "gpprotocol/Packet.hpp"
#include "gpprotocol/Packets.hpp"

class Test;

class Test2: public gp::protocol::PacketHandler {
public:
    Test2() : client_handler(nullptr) {

    }

    virtual ~Test2() {

    }

    void handle(gp::protocol::Packet* packet);

    void stop();

    Test *client_handler;
};

class Test: public gp::protocol::PacketHandler {
public:
    Test() : client("127.0.0.1", 25566) {
        client.start();
        client.getHandler()->getHandler()->client_handler = this;
    }

    virtual ~Test() {

    }

    void handle(gp::protocol::Packet* packet);

    void stop();
private:
    gp::net::TCPClient<gp::protocol::ProtocolHandler<Test2>> client;
};

void Test2::handle(gp::protocol::Packet* packet) {
    l << stde::log::level::debug << "[S->C] " << packet << std::endl;
    client_handler->send(packet);
}

void Test2::stop() {
    gp::protocol::packets::PacketFFKick p;
    p.reason = "Proxy stopped.";
    send(p);
}

void Test::handle(gp::protocol::Packet* packet) {

    // l << stde::log::level::debug << "[C->S] " << packet << std::endl;
    client.getHandler()->getHandler()->send(packet);
}

void Test::stop() {
    gp::protocol::packets::PacketFFKick p;
    p.reason = "Proxy stopping!";
    client.stop();
    send(p);
}

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
