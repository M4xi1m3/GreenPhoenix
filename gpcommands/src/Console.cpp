#include "gpcommands/Console.hpp"
#include <iterator>
#include <sstream>

using namespace gp::commands;

stde::log::log Console::l = stde::log::log::get("console");

Console::Console() : m_running(false) {
}

Console::~Console() {
}

void Console::run(std::istream& input) {
    l << stde::log::level::info << "Console started." << std::endl;
    m_running = true;

    while (m_running) {
        std::string line;
        std::getline(input, line);
        // Split the line
        std::stringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);

        try {
            std::string cmd = vstrings.at(0);
            vstrings.erase(vstrings.begin());
            Command *handler = nullptr;

            if (cmd == "help") {
                if (vstrings.size() == 0) {
                    l << stde::log::level::info << "List of commands: " << std::endl;
                    for (auto it = commands.begin(); it != commands.end(); it++) {
                        l << stde::log::level::info << "    " << (*it).second->getName() << " " << (*it).second->getUsage() << std::endl;
                    }
                    l << stde::log::level::info << "    help [command]" << std::endl;
                } else {
                    try {
                        handler = commands.at(vstrings[0]);
                    } catch (std::exception &e) {
                        l << stde::log::level::error << "Unknown command \"" << cmd << "\"!" << std::endl;
                        continue;
                    }

                    l << stde::log::level::info << "Usage of " << handler->getName() << ": " << std::endl;
                    l << stde::log::level::info << "    " << handler->getName() << " " << handler->getUsage() << std::endl;
                }
            } else {
                try {
                    handler = commands.at(cmd);
                } catch (std::exception &e) {
                    l << stde::log::level::error << "Unknown command \"" << cmd << "\"!" << std::endl;
                    continue;
                }

                if (!handler->handle(vstrings)) {
                    l << stde::log::level::error << "Usage: " << handler->getName() << " " << handler->getUsage() << std::endl;
                }
            }

        } catch (std::exception &e) {
            l << stde::log::level::error << "Error parsing command: " << e.what() << std::endl;
        }

    }
}

void Console::stop() {
    m_running = false;
}

void Console::clean() {
    for (auto it = commands.begin(); it != commands.end(); it++) {
        delete (*it).second;
        (*it).second = nullptr;
    }
    commands.clear();
}

void Console::addCommand(Command* command) {
    commands[command->getName()] = command;
}
