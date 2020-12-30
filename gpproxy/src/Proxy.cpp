#include "gpproxy/Proxy.hpp"
#include "gpproxy/ProxyConfig.hpp"

using namespace gp::proxy;

Proxy::Proxy() {
}

Proxy::~Proxy() {
}

void Proxy::run() {
    ProxyConfig::load("proxy.properties");
    server = new net::TCPServer<ProxyHandler>(ProxyConfig::ip, ProxyConfig::port);
    server->start();

    // TODO: True console.
    std::string a;
    std::getline(std::cin, a);

    server->stop();
    ProxyConfig::save("proxy.properties");
}
