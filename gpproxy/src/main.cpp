#include <iostream>

#include "gpconfig/Version.hpp"

#include "stde/net/init.hpp"
#include "stde/log/log.hpp"

#include "gpproxy/ProxyConfig.hpp"
#include "gpproxy/Proxy.hpp"

int main(int argc, char** argv) {
    boot_message("Proxy");
    stde::net::init();

    gp::proxy::Proxy::getInstance().run();

    stde::net::deinit();
    stde::log::log::clean();
}
