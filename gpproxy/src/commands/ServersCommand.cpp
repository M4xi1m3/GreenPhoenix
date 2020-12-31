#include "gpproxy/commands/ServersCommand.hpp"
#include "gpproxy/ProxyConfig.hpp"
#include "gpproxy/Proxy.hpp"

using namespace gp::proxy::commands;

ServersCommand::ServersCommand() {
    // TODO Auto-generated constructor stub

}

ServersCommand::~ServersCommand() {
    // TODO Auto-generated destructor stub
}

bool ServersCommand::handle(std::vector<std::string> args) {
    if (args.size() != 0)
        return false;

    l << stde::log::level::info << "Server list:" << std::endl;
    for(auto it = ProxyConfig::server_list.begin(); it != ProxyConfig::server_list.end(); it++) {
        l << stde::log::level::info << "    " << (*it).first << ": " << (*it).second << std::endl;;
    }

    return true;
}
