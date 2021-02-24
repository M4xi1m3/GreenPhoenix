#ifndef INCLUDE_GPBOT_COMMANDS_MASSCONNECTCOMMAND_HPP_
#define INCLUDE_GPBOT_COMMANDS_MASSCONNECTCOMMAND_HPP_

#include "gpcommands/Command.hpp"
#include "gpbot/Bot.hpp"

namespace gp {
    namespace bot {
        namespace commands {
            NEW_COMMAND(MassconnectCommand, "mconnect", "<ip> <prefix> <number>", {
                if (args.size() != 3)
                    return false;

                int num = std::stoi(args[2]);
                for(int i = 0; i < num; i++) {
                    auto bh = new net::TCPClient<protocol::ProtocolHandler<BotHandler>>(args[0]);
                    bh->getHandler()->getHandler()->name = args[1] + std::to_string(i);
                    bh->start();

                    gp::bot::Bot::getInstance().add_client(bh);
                }

                return true;
            })
        }
    }
}

#endif
