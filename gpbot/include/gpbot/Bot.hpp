#ifndef INCLUDE_GPBOT_BOT_HPP_
#define INCLUDE_GPBOT_BOT_HPP_

#include <list>

#include "gpcommands/Console.hpp"
#include "gpnet/TCPClient.hpp"
#include "gpprotocol/ProtocolHandler.hpp"
#include "gpbot/BotHandler.hpp"

namespace gp {
    namespace bot {

        /**
         * GreenPhornix's Bot. Singleton.
         */
        class Bot {
        public:

            /**
             * Destructor
             */
            virtual ~Bot();

            /**
             * Starts the bot.
             */
            void run();

            /**
             * Stops the bot.
             */
            void stop();

            /**
             * Stop all clients
             */
            void killall();

            /**
             * Add a client to the client list
             * @param client    Client to add
             */
            void add_client(net::TCPClient<protocol::ProtocolHandler<BotHandler>>* client);

            /**
             * Get instance.
             * @return  Instance of the bot.
             */
            static Bot& getInstance() {
                static Bot instance;
                return instance;
            }
            Bot(Bot const&) = delete;
            void operator=(Bot const&) = delete;
        private:
            Bot();

            gp::commands::Console console;
            std::list<net::TCPClient<protocol::ProtocolHandler<BotHandler>>*> clients;
        };

    }
}
#endif
