#include "gpproxy/Proxy.hpp"
#include "gpproxy/ProxyConfig.hpp"

#include "gpproxy/commands/StopCommand.hpp"
#include "gpproxy/commands/ConfigCommand.hpp"
#include "gpproxy/commands/ServersCommand.hpp"

using namespace gp::proxy;

Proxy::Proxy() {
}

Proxy::~Proxy() {
}

void Proxy::run() {
    ProxyConfig::load("proxy.properties");
    server = new net::TCPServer<ProxyHandler>(ProxyConfig::ip, ProxyConfig::port);
    server->start();

    console.addCommand(new commands::StopCommand());
    console.addCommand(new commands::ConfigCommand());
    console.addCommand(new commands::ServersCommand());
    console.run(std::cin);
}

void Proxy::stop() {
    server->stop();
    ProxyConfig::save("proxy.properties");
    console.stop();
    console.clean();
}
