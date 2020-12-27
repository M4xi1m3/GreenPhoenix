#ifndef GPNET_INCLUDE_GPNET_TCPHANDLER_HPP_
#define GPNET_INCLUDE_GPNET_TCPHANDLER_HPP_

#include <thread>
#include <atomic>
#include "stde/net/sock.hpp"
#include "stde/streams/sock.hpp"
#include "stde/streams/data.hpp"

namespace gp {
    namespace net {
        /**
         * @brief Represents a TCP handler
         */
        class TCPHandler {
        public:
            /**
             * Constructor.
             * @param client_socket Socket of the client to handle.
             * @param id    Handler's unique ID.
             */
            TCPHandler(stde::net::sock& client_socket, int id) : m_socket(std::move(client_socket)), m_is(m_socket), m_os(m_socket), m_done(false), m_mustStop(
                    false), m_id(id) {

            }

            /**
             * Destructor
             */
            virtual ~TCPHandler() {

            }

            /**
             * Starts the handler in a new thread
             */
            void start() {
                m_thread = std::thread([this] {
                    m_done = false;
                    handle();
                    m_done = true;
                });
            }

            /**
             * Stop the handler. Called from the main server thread
             */
            virtual void stop() = 0;

            /**
             * Stop the handler and joins.
             */
            void join() {
                stop();
                m_thread.join();
            }

            /**
             * Indication for the server is it can delete the handler or not.
             * @return  True if the handler is done, false otherwise.
             */
            inline bool done() {
                return m_done;
            }

            /**
             * Handle the client. Started in a new thread.
             */
            virtual void handle() = 0;

            /**
             * Get ID of the handler. The ID is internal to the server and is unique.
             * ID generation starts at 1, and counts up for each new handler.
             *
             * @return  The ID of the handler.
             */
            inline int getID() {
                return m_id;
            }
        protected:
            /**
             * Socket of the client
             */
            stde::net::sock m_socket;

            /**
             * Socket's input stream
             */
            stde::streams::sock_istream m_is;

            /**
             * Socket's output stream
             */
            stde::streams::sock_ostream m_os;

            /**
             * Tells the handler if it must stop.
             * @return  True if the handler must stop.
             */
            inline bool mustStop() {
                return m_mustStop;
            }
        private:
            std::thread m_thread;
            std::atomic<bool> m_done;
            std::atomic<bool> m_mustStop;
            int m_id;
        };
    }
}

#endif
