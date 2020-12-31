#ifndef INCLUDE_GPPROXY_COMMANDS_CONFIGCOMMAND_HPP_
#define INCLUDE_GPPROXY_COMMANDS_CONFIGCOMMAND_HPP_

#include "gpcommands/Command.hpp"

namespace gp {
    namespace proxy {
        namespace commands {
            /**
             * Command to manage configuration
             */
            class ConfigCommand: public gp::commands::Command {
            public:
                ConfigCommand();
                virtual ~ConfigCommand();

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
                    return "config";
                }

                /**
                 * Get the usage of the command
                 *
                 * @return  Usage of the command.
                 */
                virtual std::string getUsage() {
                    return "<load/save/srv> [name] [address]";
                }
            };

        }
    }
}
#endif
