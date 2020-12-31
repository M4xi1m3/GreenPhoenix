#ifndef INCLUDE_GPCOMMANDS_CONSOLE_HPP_
#define INCLUDE_GPCOMMANDS_CONSOLE_HPP_

#include "gpcommands/Command.hpp"
#include "stde/log/log.hpp"
#include <istream>
#include <map>

namespace gp {
    namespace commands {

        /**
         * Console handler
         */
        class Console {
        public:
            /**
             * Constructor
             */
            Console();

            /**
             * Destructor
             */
            virtual ~Console();

            /**
             * Start.
             * @param input Stream to read commands from
             */
            void run(std::istream& input);

            /**
             * Stop
             */
            void stop();

            /**
             * Delete all command handlers
             */
            void clean();

            /**
             * Register a command handler
             * @param command   Handler to add
             */
            void addCommand(Command* command);
        private:
            std::map<std::string, Command*> commands;
            static stde::log::log l;
            bool m_running;
        };
    }
}
#endif
