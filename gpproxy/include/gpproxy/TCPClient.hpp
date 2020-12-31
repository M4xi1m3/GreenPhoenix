#ifndef INCLUDE_GPPROXY_TCPCLIENT_HPP_
#define INCLUDE_GPPROXY_TCPCLIENT_HPP_

#include "gpproxy/ProxyPlayer.hpp"
#include "stde/net/sock.hpp"
#include "stde/net/sockaddress.hpp"
#include "stde/streams/data.hpp"
#include "stde/log/log.hpp"

#include "gpprotocol/Packet.hpp"

#include <mutex>

namespace gp {
    namespace proxy {

        /**
         * Proxy TCP client
         */
        class TCPClient {
        public:
            /**
             * Constructor
             * @param player
             * @param ip
             * @param port
             */
            TCPClient(ProxyPlayer* player, const std::string& ip, int port);

            /**
             * Constructor
             * @param player
             * @param ip
             */
            TCPClient(ProxyPlayer* player, const std::string& ip);

            /**
             * Destructor
             */
            virtual ~TCPClient();

            /**
             * Send packet to server
             * @param p Packet to send
             */
            void sendPacket(protocol::Packet& p);

            /**
             * Send packet to server
             * @param p Packet to send
             */
            void sendPacket(protocol::Packet* p);

            /**
             * Close connection and joins client thread.
             */
            void close();

            /**
             * Start client in new thread.
             */
            void start();
        private:
            ProxyPlayer *m_player;
            stde::net::sock m_socket;

            stde::streams::sock_istream m_is;
            stde::streams::sock_ostream m_os;
            stde::streams::data_istream m_dis;
            stde::streams::data_ostream m_dos;

            std::recursive_mutex m_mutex;
            std::atomic<bool> m_running;
            std::thread m_thread;

            static stde::log::log l;

            void run();
        };

    }
}
#endif
