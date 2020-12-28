/*
 * Types.cpp
 *
 *  Created on: Dec 28, 2020
 *      Author: maxoufox
 */

#include <gpprotocol/types/Animation.hpp>
#include "gpprotocol/types/DigStatus.hpp"
#include "gpprotocol/types/Direction.hpp"

using namespace gp::protocol::types;

std::string gp::protocol::types::digStatusName(DigStatus d) {
    switch (d) {
        case DigStatus::START:
            return "START";
        case DigStatus::DIG:
            return "DIG";
        case DigStatus::STOP:
            return "STOP";
        case DigStatus::BREAK:
            return "BREAK";
        default:
            return "UNKNOWN";
    }
}

std::string gp::protocol::types::directionName(Direction d) {
    switch (d) {
        case Direction::DOWN:
            return "DOWN";
        case Direction::UP:
            return "UP";
        case Direction::NORTH:
            return "NORTH";
        case Direction::SOUTH:
            return "SOUTH";
        case Direction::WEST:
            return "WEST";
        case Direction::EAST:
            return "EAST";
        default:
            return "UNKNOWN";
    }
}

std::string gp::protocol::types::animationName(Animation a) {
    switch (a) {
        case Animation::NONE:
            return "NONE";
        case Animation::SWING:
            return "SWING";
        case Animation::DEATH:
            return "DEATH";
        case Animation::UNK100:
            return "UNK100";
        case Animation::UNK101:
            return "UNK101";
        case Animation::UNK102:
            return "UNK102";
        case Animation::UNK103:
            return "UNK103";
        case Animation::UNK104:
            return "UNK104";
        case Animation::UNK105:
            return "UNK105";
        default:
            return "UNKNOWN";
    }
}
