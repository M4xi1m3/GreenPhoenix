#ifndef INCLUDE_GPPROXY_PROXYMANAGER_HPP_
#define INCLUDE_GPPROXY_PROXYMANAGER_HPP_

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

        class ProxyManager: public net::TCPHandler {
        public:
            ProxyManager(stde::net::sock& socket, int id) : net::TCPHandler(socket, id), m_dis(m_is, stde::streams::endianconv::big), m_dos(m_os,
                    stde::streams::endianconv::big), m_running(true) {

            }
            virtual ~ProxyManager();
            void handle();
            void stop();

            stde::streams::data_istream m_dis;
            stde::streams::data_ostream m_dos;
            ProxyPlayer *m_player = nullptr;
            TCPClient *m_client = nullptr;
        private:
            static stde::log::log l;
            std::atomic<bool> m_running;
        };

    }
}
#endif
