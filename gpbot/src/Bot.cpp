#include "gpbot/Bot.hpp"

#include "gpbot/commands/StopCommand.hpp"
#include "gpbot/commands/ConnectCommand.hpp"
#include "gpbot/commands/KillallCommand.hpp"
#include "gpbot/commands/MassconnectCommand.hpp"

#include "gpnet/TCPClient.hpp"
#include "gpprotocol/ProtocolHandler.hpp"
#include "gpbot/BotHandler.hpp"

#include <iostream>

using namespace gp::bot;

Bot::Bot() {
}

Bot::~Bot() {
}

void Bot::run() {
    console.addCommand(new commands::ConnectCommand());
    console.addCommand(new commands::KillallCommand());
    console.addCommand(new commands::MassconnectCommand());
    console.addCommand(new commands::StopCommand());
    console.run(std::cin);
}

void Bot::add_client(net::TCPClient<protocol::ProtocolHandler<BotHandler>>* client) {
    clients.push_back(client);
}

void Bot::killall() {
    for (auto it = clients.begin(); it != clients.end(); it++) {
        if ((*it)->isRunning())
            (*it)->stop();
        delete (*it);
    }

    clients.clear();
}

void Bot::stop() {
    console.stop();
    console.clean();

    killall();
}
