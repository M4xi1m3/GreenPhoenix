#ifndef INCLUDE_GPPROXY_TCPCLIENT_HPP_
#define INCLUDE_GPPROXY_TCPCLIENT_HPP_

#include "gpproxy/ProxyPlayer.hpp"
#include "stde/net/sock.hpp"
#include "stde/net/sockaddress.hpp"
#include "stde/streams/data.hpp"

#include "gpprotocol/Packet.hpp"

#include <mutex>

namespace gp {
    namespace proxy {

        class TCPClient {
        public:
            TCPClient(ProxyPlayer* player, const std::string& ip, int port);
            virtual ~TCPClient();

            void sendPacket(protocol::Packet& p);
            void sendPacket(protocol::Packet* p);
            void close();
            void start();
        private:
            ProxyPlayer* m_player;
            stde::net::sock m_socket;

            stde::streams::sock_istream m_is;
            stde::streams::sock_ostream m_os;
            stde::streams::data_istream m_dis;
            stde::streams::data_ostream m_dos;

            std::recursive_mutex m_mutex;
            std::atomic<bool> m_running;
            std::thread m_thread;

            void run();
        };

    }
}
#endif
