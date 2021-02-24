#ifndef INCLUDE_GPBOT_COMMANDS_KILLALLCOMMAND_HPP_
#define INCLUDE_GPBOT_COMMANDS_KILLALLCOMMAND_HPP_

#include "gpcommands/Command.hpp"
#include "gpbot/Bot.hpp"

namespace gp {
    namespace bot {
        namespace commands {
            NEW_COMMAND(KillallCommand, "killall", "", {
                if (args.size() != 0)
                    return false;

                gp::bot::Bot::getInstance().killall();

                return true;
            })
        }
    }
}
#endif
