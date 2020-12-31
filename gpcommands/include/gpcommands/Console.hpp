#ifndef INCLUDE_GPCOMMANDS_CONSOLE_HPP_
#define INCLUDE_GPCOMMANDS_CONSOLE_HPP_

#include "gpcommands/Command.hpp"
#include "stde/log/log.hpp"
#include <istream>
#include <map>

namespace gp {
    namespace commands {

        class Console {
        public:
            Console();
            virtual ~Console();

            void run(std::istream& input);
            void stop();
            void clean();

            void addCommand(Command* command);
        private:
            std::map<std::string, Command*> commands;
            static stde::log::log l;
            bool m_running;
        };
    }
}
#endif
