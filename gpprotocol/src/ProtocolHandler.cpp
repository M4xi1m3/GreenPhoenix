#include "gpprotocol/ProtocolHandler.hpp"
#include "gpprotocol/Packets.hpp"
#include "stde/streams/exceptions.hpp"
#include <iostream>

using namespace gp::protocol;
using namespace gp::protocol::packets;

stde::log::log ProtocolHandler::l = stde::log::log::get("protocol");

ProtocolHandler::~ProtocolHandler() {
}

void ProtocolHandler::handle() {

    while (!mustStop()) {
        try {
            Packet *p = Packet::parse(m_dis);
            l << stde::log::level::debug << "[C->S] " << p << std::endl;
            delete p;

            PacketFFKick *ret = new PacketFFKick();
            ret->reason = "Hello, world!";
            send(ret);
            delete ret;
        } catch (stde::streams::eof_exception &e) {
            break;
        } catch (std::exception &e) {
            l << stde::log::level::error << e.what() << std::endl;
            break;
        }
    }
    m_socket.close();
}

void ProtocolHandler::send(Packet* p) {
    l << stde::log::level::debug << "[S->C] " << p << std::endl;
    m_dos.write_byte(p->getID());
    p->write(m_dos);
    m_dos.flush();
}

void ProtocolHandler::stop() {
    if (!done()) {
        PacketFFKick *ret = new PacketFFKick();
        ret->reason = "Server closing!";
        send(ret);
        delete ret;
    }

    m_socket.shutdown();
    m_socket.close();
}
