#ifndef INCLUDE_GPPROXY_PROXYHANDLER_HPP_
#define INCLUDE_GPPROXY_PROXYHANDLER_HPP_

namespace gp {
    namespace proxy {
        class ProxyPlayer;
        class TCPClient;
    }
}

#include "gpnet/TCPHandler.hpp"
#include "gpproxy/TCPClient.hpp"
#include "gpproxy/ProxyPlayer.hpp"
#include "stde/log/log.hpp"

namespace gp {
    namespace proxy {
        /**
         * Proxy TCP handler.
         */
        class ProxyHandler: public net::TCPHandler {
        public:
            /**
             * Constructor
             * @param socket
             * @param id
             */
            ProxyHandler(stde::net::sock& socket, int id) : net::TCPHandler(socket, id), m_dis(m_is, stde::streams::endianconv::big), m_dos(m_os,
                    stde::streams::endianconv::big), m_running(true) {
            }

            virtual ~ProxyHandler();
            void handle();
            void stop();

            /**
             * Socket's data input stream
             */
            stde::streams::data_istream m_dis;

            /**
             * Socket's data output stream
             */
            stde::streams::data_ostream m_dos;

            /**
             * Associated player object
             */
            ProxyPlayer *m_player = nullptr;

            /**
             * Associated TCP client.
             */
            TCPClient *m_client = nullptr;
        private:
            static stde::log::log l;
            std::atomic<bool> m_running;
        };

    }
}
#endif
