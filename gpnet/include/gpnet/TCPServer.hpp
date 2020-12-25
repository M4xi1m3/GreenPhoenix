#ifndef GPNET_SRC_TCPSERVER_HPP_
#define GPNET_SRC_TCPSERVER_HPP_

#include <string>
#include <thread>

#include "stde/net/net.hpp"
#include "stde/log/log.hpp"

namespace gp {
    namespace net {

        class TCPServer {
        public:
            /**
             * Initializes a TCP server.
             * @param ip    IP to bind
             * @param port  Port to bind
             */
            TCPServer(std::string ip, int port);
            virtual ~TCPServer();

            /**
             * Check if server is running
             * @return  True if server is running
             */
            inline bool isRunning() const {
                return m_running;
            }

            /**
             * Starts the server.
             *
             * The server starts in another thread, binds and listen, then start accepting.
             * It checks every 500ms if it should close.
             *
             * @see #stop
             */
            void start();

            /**
             * Tells the server to stop and joins the server thread.
             *
             * This is not instant, as the server checks if it should stop every 500ms.
             */
            void stop();

        private:
            /**
             * Internal method running in a separate thread
             */
            void run();

            stde::net::sock_address m_address;
            stde::net::server_sock m_socket;
            bool m_running;
            bool m_mustStop;

            std::thread m_thread;

            static stde::log::log l;
        };

    }
}

#endif
