#ifndef INCLUDE_GPPROXY_COMMANDS_STOPCOMMAND_HPP_
#define INCLUDE_GPPROXY_COMMANDS_STOPCOMMAND_HPP_

#include "gpcommands/Command.hpp"

namespace gp {
    namespace proxy {
        namespace commands {

            class StopCommand: public gp::commands::Command {
            public:
                StopCommand();
                virtual ~StopCommand();

                /**
                 * Handle the commands
                 * @param args  Arguments for the command
                 * @return  True if handled successfully, false otherwise
                 */
                virtual bool handle(std::vector<std::string> args);

                /**
                 * Get name of the command
                 * @return  The name of the command
                 */
                virtual std::string getName() {
                    return "stop";
                }

                /**
                 * Get the usage of the command
                 *
                 * @return  Usage of the command.
                 */
                virtual std::string getUsage() {
                    return "";
                }
            };

        }
    }
}
#endif
