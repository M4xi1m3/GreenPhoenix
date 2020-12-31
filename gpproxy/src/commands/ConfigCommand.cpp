#include "gpproxy/commands/ConfigCommand.hpp"
#include "gpproxy/ProxyConfig.hpp"

using namespace gp::proxy::commands;

ConfigCommand::ConfigCommand() {
    // TODO Auto-generated constructor stub

}

ConfigCommand::~ConfigCommand() {
    // TODO Auto-generated destructor stub
}

bool ConfigCommand::handle(std::vector<std::string> args) {
    if (args.size() == 0)
        return false;

    if (args[0] == "load") {
        ProxyConfig::load("proxy.properties");
        return true;
    }

    if (args[0] == "save") {
        ProxyConfig::save("proxy.properties");
        return true;
    }

    if (args[0] == "srv") {
        if (args.size() != 3)
            return false;

        ProxyConfig::server_list[args[1]] = args[2];
        return true;
    }

    return false;
}
