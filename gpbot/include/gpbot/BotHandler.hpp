#ifndef INCLUDE_GPBOT_BOTHANDLER_HPP_
#define INCLUDE_GPBOT_BOTHANDLER_HPP_

#include "gpprotocol/PacketHander.hpp"

namespace gp {
    namespace bot {

        class BotHandler: public protocol::PacketHandler {
        public:
            /**
             * Constructor
             */
            BotHandler() : PacketHandler(), name(""), m_login(true) {

            }

            /**
             * Destructor
             */
            virtual ~BotHandler() {

            }

            /**
             * Handle packet
             * @param packet    Packet to handle
             */
            void handle(protocol::Packet* packet);

            /**
             * Called when server is stopping.
             */
            void stop();

            /**
             * Called when the connection with the client is closed.
             */
            void closed();

            /**
             * Called when the handler has started.
             */
            void started();

            /**
             * Name of the bot player.
             */
            std::string name;
        private:
            bool m_login;
        };

    }
}
#endif
