#include "gpproxy/Proxy.hpp"
#include "gpproxy/ProxyConfig.hpp"

#include "gpproxy/commands/StopCommand.hpp"

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
    console.run(std::cin);
}

void Proxy::stop() {
    server->stop();
    ProxyConfig::save("proxy.properties");
    console.stop();
    console.clean();
}
