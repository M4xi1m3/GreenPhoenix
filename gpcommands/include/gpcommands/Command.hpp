#ifndef INCLUDE_GPCOMMANDS_COMMAND_HPP_
#define INCLUDE_GPCOMMANDS_COMMAND_HPP_

#include "stde/log/log.hpp"
#include <vector>
#include <string>

namespace gp {
    namespace commands {
        /**
         * A command
         */
        class Command {
        public:
            /**
             * Constructor
             */
            Command();

            /**
             * Destructor
             */
            virtual ~Command();

            /**
             * Handle the commands
             * @param args  Arguments for the command
             * @return  True if handled successfully, false otherwise
             */
            virtual bool handle(std::vector<std::string> args) = 0;

            /**
             * Get name of the command
             * @return  The name of the command
             */
            virtual std::string getName() = 0;

            /**
             * Get the usage of the command
             *
             * @return  Usage of the command.
             */
            virtual std::string getUsage() = 0;
        protected:
            /**
             * Logger
             */
            static stde::log::log l;
        };

    }
}

#define NEW_COMMAND(CLASSNAME, NAME, USAGE, ...) \
            class CLASSNAME: public gp::commands::Command { \
            public: \
                CLASSNAME() : gp::commands::Command() {} \
                virtual ~CLASSNAME() {} \
                virtual bool handle(std::vector<std::string> args) { __VA_ARGS__ } \
                virtual std::string getName() { return NAME; } \
                virtual std::string getUsage() { return USAGE; } \
            };

#endif
