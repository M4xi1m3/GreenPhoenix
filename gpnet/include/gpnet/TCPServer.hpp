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
         * Simple multi-threaded TCP server.
         */
        template<class T, typename = std::enable_if<std::is_base_of<TCPHandler, T>::value>>
        class TCPServer {
        public:
            /**
             * Initializes a TCP server.
             * @param ip    IP to bind
             * @param port  Port to bind
             */
            TCPServer(std::string ip, int port) : m_address(ip, std::to_string(port)), m_socket(m_address), m_running(false), m_mustStop(true), m_handlers(), m_lastId(
                    1) {
            }

            /**
             * Destructor
             */
            virtual ~TCPServer() {
            }

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
            void start() {
                if (m_running)
                    throw std::runtime_error("Server already running!");

                m_mustStop = false;

                m_thread = std::thread(&TCPServer<T>::run, this);
            }

            /**
             * Tells the server to stop and joins the server thread.
             *
             * This is not instant, as the server checks if it should stop every 500ms.
             */
            void stop() {
                if (!m_running)
                    throw std::runtime_error("Server not running!");

                l << stde::log::level::info << "Stopping TCP server..." << std::endl;

                m_mustStop = true;
                m_thread.join();
            }

        private:
            /**
             * Internal method running in a separate thread
             */
            void run() {
                l << stde::log::level::info << "Starting TCP server on " << m_address << "..." << std::endl;

                m_socket.reuse_address(true);
                m_socket.blocking(false);
                m_socket.bind();
                m_socket.listen();

                m_running = true;

                // Run until we must stop
                while (!m_mustStop) {
                    try {
                        // Accept as much as we can before EWOULDBLOCK.
                        while (!m_mustStop) {
                            stde::net::sock client_socket = m_socket.accept();
                            T *handler = new T(client_socket, m_lastId++);
                            l << stde::log::level::debug << "Handler#" << handler->getID() << " added." << std::endl;
                            m_handlers.push_back(handler);
                            handler->start();
                        }
                    } catch (const std::system_error &e) {
                        if (e.code().value() != EAGAIN && e.code().value() != EWOULDBLOCK)
                            l << stde::log::level::error << e.what() << std::endl;
                    }
                    try {
                        // Remove and delete handlers which are done.
                        for (auto i = m_handlers.begin(); i != m_handlers.end();) {
                            if ((*i)->done()) {
                                (*i)->join();
                                l << stde::log::level::debug << "Handler#" << (*i)->getID() << " removed." << std::endl;
                                delete (*i);
                                (*i) = nullptr;
                                i = m_handlers.erase(i);
                            } else {
                                i++;
                            }
                        }
                    } catch (std::exception &e) {
                        l << stde::log::level::error << e.what() << std::endl;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }

                // Stop running handlers
                for (auto i = m_handlers.begin(); i != m_handlers.end();) {
                    l << stde::log::level::debug << "Handler#" << (*i)->getID() << " removed." << std::endl;
                    (*i)->join();
                    delete (*i);
                    (*i) = nullptr;
                    i = m_handlers.erase(i);
                }

                m_running = false;
            }

            stde::net::sock_address m_address;
            stde::net::server_sock m_socket;
            std::atomic<bool> m_running;
            std::atomic<bool> m_mustStop;
            stde::log::log l = stde::log::log::get("tcp-server");

            std::list<T*> m_handlers;

            std::thread m_thread;
            int m_lastId;

        };
    }
}

#endif
