#include <iostream>

#include "stde/net/init.hpp"
#include "stde/log/log.hpp"

#include "gpconfig/Version.hpp"

#include "gpbot/Bot.hpp"

int main(int argc, char** argv) {
    boot_message("Bot");
    stde::net::init();

    gp::bot::Bot::getInstance().run();

    stde::net::deinit();
    stde::log::log::clean();
    return 0;
}
