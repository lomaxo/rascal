//
//  Player.cpp
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#include "Player.h"

Player::Player() {
    
}

void Player::move(int x, int y) {
    _x = x;
    _y = y;
}

bool Player::step(int x, int y) {
    return false;
}