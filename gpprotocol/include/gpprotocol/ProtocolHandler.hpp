#ifndef INCLUDE_PROTOCOLHANDLER_HPP_
#define INCLUDE_PROTOCOLHANDLER_HPP_

#include "gpnet/TCPHandler.hpp"

#include "gpprotocol/Packet.hpp"

#include "stde/log/log.hpp"

namespace gp {
    namespace protocol {

        class ProtocolHandler: public gp::net::TCPHandler {
        public:
            ProtocolHandler(stde::net::sock& client_socket, int id) : TCPHandler(client_socket, id), m_dis(m_is, stde::streams::endianconv::big), m_dos(m_os,
                    stde::streams::endianconv::big) {
            }

            virtual ~ProtocolHandler();

            void handle();
            void stop();

            void send(const Packet& p);
        private:
            static stde::log::log l;

            stde::streams::data_istream m_dis;
            stde::streams::data_ostream m_dos;
        };

    }
}
#endif
