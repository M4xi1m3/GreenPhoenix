/*
 * Types.cpp
 *
 *  Created on: Dec 28, 2020
 *      Author: maxoufox
 */

#include <gpprotocol/types/Mob.hpp>
#include <gpprotocol/types/Object.hpp>
#include "gpprotocol/types/Animation.hpp"
#include "gpprotocol/types/DigStatus.hpp"
#include "gpprotocol/types/Direction.hpp"
#include "gpprotocol/types/Status.hpp"

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
        case Animation::SITTING:
            return "SITTING";
        case Animation::NOT_SITTING:
            return "NOT_SITTING";
        case Animation::FIRE:
            return "FIRE";
        case Animation::NOT_FIRE:
            return "NOT_FIRE";
        case Animation::CROUCHING:
            return "CROUCHING";
        case Animation::NOT_CROUCHING:
            return "NOT_CROUCHING";
        default:
            return "UNKNOWN";
    }
}

std::string gp::protocol::types::objectName(Object o) {
    switch (o) {
        case Object::BOAT:
            return "BOAT";
        case Object::MINECART:
            return "MINECART";
        case Object::MINECART_CHEST:
            return "MINECART_CHEST";
        case Object::MINECART_FURNACE:
            return "MINECART_FURNACE";
        case Object::PRIMED_TNT:
            return "PRIMED_TNT";
        case Object::ARROW:
            return "ARROW";
        case Object::SNOWBALL:
            return "SNOWBALL";
        case Object::FISH:
            return "FISH";
        default:
            return "UNKNOWN";
    }
}

std::string gp::protocol::types::mobName(Mob m) {
    switch (m) {
        case Mob::CREEPER:
            return "CREEPER";
        case Mob::SKELETON:
            return "SKELETON";
        case Mob::SPIDER:
            return "SPIDER";
        case Mob::GIANT:
            return "GIANT";
        case Mob::ZOMBIE:
            return "ZOMBIE";
        case Mob::SLIME:
            return "SLIME";
        case Mob::GHAST:
            return "GHAST";
        case Mob::PIGZOMBIE:
            return "PIGZOMBIE";
        case Mob::PIG:
            return "PIG";
        case Mob::SHEEP:
            return "SHEEP";
        case Mob::COW:
            return "COW";
        case Mob::CHICKEN:
            return "CHICKEN";
        default:
            return "UNKNOWN";
    }
}

std::string gp::protocol::types::statusName(Status s) {
    switch (s) {
        case Status::DAMAGE:
            return "DAMAGE";
        case Status::DEATH:
            return "DEATH";
        case Status::PRIMED:
            return "PRIMED";
        case Status::NOT_PRIMED:
            return "NOT_PRIMED";
        default:
            return "UNKNOWN";
    }
}
