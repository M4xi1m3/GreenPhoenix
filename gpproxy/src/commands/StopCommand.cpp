#include "gpproxy/commands/StopCommand.hpp"
#include "gpproxy/Proxy.hpp"

using namespace gp::proxy::commands;

StopCommand::StopCommand() {
    // TODO Auto-generated constructor stub

}

StopCommand::~StopCommand() {
    // TODO Auto-generated destructor stub
}

bool StopCommand::handle(std::vector<std::string> args) {
    if (args.size() != 0)
        return false;

    gp::proxy::Proxy::getInstance().stop();

    return true;
}
