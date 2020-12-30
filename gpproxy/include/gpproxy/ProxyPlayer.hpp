#ifndef INCLUDE_GPPROXY_PROXYPLAYER_HPP_
#define INCLUDE_GPPROXY_PROXYPLAYER_HPP_

namespace gp {
    namespace proxy {
        class ProxyManager;
    }
}

#include "gpproxy/ProxyManager.hpp"
#include "gpprotocol/Packet.hpp"
#include "stde/log/log.hpp"
#include <mutex>

namespace gp {
    namespace proxy {

        class ProxyPlayer {
        public:
            ProxyPlayer(ProxyManager* handler);
            virtual ~ProxyPlayer();

            void sendPacket(protocol::Packet& packet);
            void sendPacket(protocol::Packet* packet);
            void kick(const std::string& reason);
            void sendChat(const std::string& message);

            void handleCS(protocol::Packet* packet);
            void handleSC(protocol::Packet* packet);
        private:
            ProxyManager *m_handler;
            static stde::log::log l;

            std::recursive_mutex m_mutex;
        };
    }
}
#endif
