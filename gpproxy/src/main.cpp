#include <iostream>
#include <mutex>

#include "stde/net/init.hpp"
#include "stde/log/log.hpp"

#include "gpproxy/ProxyConfig.hpp"
#include "gpproxy/Proxy.hpp"

void printIntro() {
    std::cout << std::endl;
    std::cout << "     ,,,     ,,                                                                       " << std::endl;
    std::cout << "   .;;'        ';      _____                     _____  _                      _      " << std::endl;
    std::cout << "  /((,  ,//;'`  ,,    / ____|                   |  __ \\| |                    (_)     " << std::endl;
    std::cout << "  (((( ,;//     ,,.  | |  __ _ __ ___  ___ _ __ | |__) | |__   ___   ___ _ __  ___  __" << std::endl;
    std::cout << "  (((( ;///\\   ,,,,  | | |_ | '__/ _ \\/ _ \\ '_ \\|  ___/| '_ \\ / _ \\ / _ \\ '_ \\| \\ \\/ /" << std::endl;
    std::cout << "  \\(((////////,,,,   | |__| | | |  __/  __/ | | | |    | | | | (_) |  __/ | | | |>  < " << std::endl;
    std::cout << "   `((////////;;,     \\_____|_|  \\___|\\___|_| |_|_|    |_| |_|\\___/ \\___|_| |_|_/_/\\_\\" << std::endl;
    std::cout << "      ``'^^^'``                                         - Proxy v1.0.1 - AGPLv3       " << std::endl;
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    printIntro();
    stde::net::init();

    gp::proxy::Proxy::getInstance().run();

    stde::net::deinit();
    stde::log::log::clean();
}
