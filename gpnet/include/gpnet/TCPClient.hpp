#ifndef GPNET_SRC_TCPSERVER_HPP_
#define GPNET_SRC_TCPSERVER_HPP_

#include <string>
#include <thread>
#include <list>
#include <atomic>

#include "gpnet/TCPHandler.hpp"

#include "stde/net/net.hpp"
#include "stde/log/log.hpp"

namespace gp {
    namespace net {
        /**
         * @brief Simple multi-threaded TCP server.
         */
        template<class T, typename = std::enable_if<std::is_base_of<TCPHandler, T>::value>>
        class TCPClient {
        public:
            /**
             * Initializes a TCP client.
             * @param ip    IP to bind
             * @param port  Port to bind
             */
            TCPClient(std::string ip, int port) : m_address(ip, std::to_string(port)), m_socket(m_address), m_running(false), m_handler(nullptr) {
                m_handler = new T(m_socket, 0);
            }
            /**
             * Initializes a TCP client.
             * @param ip    IP to bind
             */
            TCPClient(std::string ip) : m_address(ip), m_socket(m_address), m_running(false), m_handler(nullptr) {
                m_handler = new T(m_socket, 0);
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
                return m_running;
            }

            /**
             * Starts the client.
             *
             * The client connects then starts in another thread.
             *
             * @see #stop
             */
            void start() {
                if (m_running)
                    throw std::runtime_error("Client already running!");

                l << stde::log::level::info << "Connecting TCP client to " << m_address << "..." << std::endl;
                m_handler->m_socket.connect();

                m_thread = std::thread(&TCPClient<T>::run, this);
            }

            /**
             * Tells the client to stop and joins the client thread.
             *
             * This is not instant, as the server checks if it should stop every 500ms.
             */
            void stop() {
                if (!m_running)
                    throw std::runtime_error("Client not running!");

                l << stde::log::level::info << "Stopping TCP client..." << std::endl;

                m_handler->stop();
                m_thread.join();
            }

            /**
             * Get the handler
             * @return  The handler
             */
            T* getHandler() {
                return m_handler;
            }

        private:
            /**
             * Internal method running in a separate thread
             */
            void run() {
                m_running = true;

                m_handler->handle();
                delete m_handler;

                m_running = false;
            }

            stde::net::sock_address m_address;
            stde::net::sock m_socket;
            std::atomic<bool> m_running;
            stde::log::log l = stde::log::log::get("tcp-client");
            T *m_handler;

            std::thread m_thread;
        };
    }
}

#endif
