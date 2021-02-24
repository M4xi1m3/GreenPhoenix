#ifndef INCLUDE_GPBOT_COMMANDS_STOPCOMMAND_HPP_
#define INCLUDE_GPBOT_COMMANDS_STOPCOMMAND_HPP_

#include "gpcommands/Command.hpp"
#include "gpbot/Bot.hpp"

namespace gp {
    namespace bot {
        namespace commands {
            NEW_COMMAND(StopCommand, "stop", "", {
                if (args.size() != 0)
                    return false;

                gp::bot::Bot::getInstance().stop();

                return true;
            })
        }
    }
}
#endif
