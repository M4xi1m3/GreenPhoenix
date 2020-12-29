#ifndef INCLUDE_GPNET_TCPCLIENT_HPP_
#define INCLUDE_GPNET_TCPCLIENT_HPP_

#include <thread>

#include "gpnet/TCPHandler.hpp"

#include "stde/net/net.hpp"
#include "stde/log/log.hpp"

namespace gp {
    namespace net {
        /**
         * @brief Simple TCP client
         */
        template<class T, typename = std::enable_if<std::is_base_of<TCPHandler, T>::value>>
        class TCPClient {
        public:
            /**
             * Initializes a TCP client
             * @param ip    IP to connect to
             * @param port  Port to connect to
             */
            TCPClient(std::string ip, int port) : m_address(ip, std::to_string(port)), m_socket(m_address), m_handler(nullptr) {

            }

            /**
             * Destructor
             */
            virtual ~TCPClient() {
            }

            /**
             * Check if server is running
             * @return  True if server is running
             */
            inline bool isRunning() const {
                return m_handler != nullptr;
            }

            /**
             * Starts the server.
             *
             * The server starts in another thread, binds and listen, then start accepting.
             * It checks every 500ms if it should close.
             *
             * @see #stop
             */
            void start() {
                if (m_handler != nullptr)
                    throw std::runtime_error("Client already running!");

                run();
            }

            /**
             * Tells the server to stop and joins the server thread.
             *
             * This is not instant, as the server checks if it should stop every 500ms.
             */
            void stop() {
                if (m_handler == nullptr)
                    throw std::runtime_error("Client not running!");

                l << stde::log::level::info << "Stopping TCP client..." << std::endl;
                m_handler->join();

                delete m_handler;
                m_handler = nullptr;
            }

            T* getHandler() {
                return m_handler;
            }

        private:
            /**
             * Internal method running in a separate thread
             */
            void run() {
                l << stde::log::level::info << "Connecting TCP client to " << m_address << "..." << std::endl;

                m_socket.keep_alive(true);
                m_socket.connect();

                m_handler = new T(m_socket, 0);
                m_handler->start();
            }

            stde::net::sock_address m_address;
            stde::net::sock m_socket;
            stde::log::log l = stde::log::log::get("tcp-client");

            T *m_handler;
        };
    }
}

#endif
