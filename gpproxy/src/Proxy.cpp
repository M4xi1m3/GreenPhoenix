#include "gpproxy/Proxy.hpp"
#include "gpproxy/ProxyConfig.hpp"

using namespace gp::proxy;

Proxy::Proxy() {
}

Proxy::~Proxy() {
}

void Proxy::run() {
    ProxyConfig::load("server.properties");
    server = new net::TCPServer<ProxyManager>(ProxyConfig::getStringOrDefault("ip", "0.0.0.0"), ProxyConfig::getIntOrDefault("port", 25565));
    server->start();

    // TODO: True console.
    std::string a;
    std::getline(std::cin, a);

    server->stop();
}
