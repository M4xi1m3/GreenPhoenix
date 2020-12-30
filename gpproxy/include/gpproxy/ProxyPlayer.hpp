#ifndef INCLUDE_GPPROXY_PROXYPLAYER_HPP_
#define INCLUDE_GPPROXY_PROXYPLAYER_HPP_

namespace gp {
    namespace proxy {
        class ProxyHandler;
    }
}

#include <gpproxy/ProxyHandler.hpp>
#include "gpprotocol/Packet.hpp"
#include "stde/log/log.hpp"
#include <mutex>

namespace gp {
    namespace proxy {

        /**
         * Player handled by proxy.
         */
        class ProxyPlayer {
        public:
            /**
             * Constructor
             * @param handler
             */
            ProxyPlayer(ProxyHandler* handler);

            /**
             * Destructor
             */
            virtual ~ProxyPlayer();

            /**
             * Send pack to player
             * @param packet    Packet to send
             */
            void sendPacket(protocol::Packet& packet);

            /**
             * Send pack to player
             * @param packet    Packet to send
             */
            void sendPacket(protocol::Packet* packet);

            /**
             * Kick player
             * @param reason    Reason for the kick
             */
            void kick(const std::string& reason);

            /**
             * Send chat message to player
             * @param message   Chat message to send
             */
            void sendChat(const std::string& message);

            /**
             * Handle a Client to Server packet
             * @param packet    Packet to handle
             */
            void handleCS(protocol::Packet* packet);

            /**
             * Handle a Server to Client packet
             * @param packet    Packet to handle
             */
            void handleSC(protocol::Packet* packet);
        private:
            ProxyHandler *m_handler;
            static stde::log::log l;

            std::recursive_mutex m_mutex;
        };
    }
}
#endif
