#include <string>
#include "player.h"

void Player::set_name(std::string new_name) {
    name = new_name;
}

std::string Player::get_name() {
    return name;
}

void Player::set_health(int new_health) {
    health = new_health;
}

int Player::get_health() {
    return health;
}

void Player::set_xp(int new_xp) {
    xp = new_xp;
}

int Player::get_xp() {
    return xp;
}
