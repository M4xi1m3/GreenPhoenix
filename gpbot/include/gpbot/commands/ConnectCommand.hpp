#ifndef INCLUDE_GPBOT_COMMANDS_CONNECTCOMMAND_HPP_
#define INCLUDE_GPBOT_COMMANDS_CONNECTCOMMAND_HPP_

#include "gpcommands/Command.hpp"
#include "gpbot/Bot.hpp"

namespace gp {
    namespace bot {
        namespace commands {
            NEW_COMMAND(ConnectCommand, "connect", "<ip> <name>", {
                if (args.size() != 2)
                    return false;

                auto bh = new net::TCPClient<protocol::ProtocolHandler<BotHandler>>(args[0]);
                bh->getHandler()->getHandler()->name = args[1];
                bh->start();

                gp::bot::Bot::getInstance().add_client(bh);

                return true;
            })
        }
    }
}
#endif
