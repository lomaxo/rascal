//
//  Map.cpp
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#include "Map.h"
#include <cstdlib>
#include <algorithm>    // std::max
#include <iostream>
#include "MessageHandler.h"


extern MessageHandler msg_handler;

using namespace std;

Room::Room(int width, int height, int x, int y) {
    _x = x;
    _y = y;
    width = _width;
    height = _height;
    _end_x = _x + _width;
    _end_y = _y + _height;
    
}

bool Room::overlaps(Room other_room) {
    if (_x <= other_room._end_x && _end_x >= other_room._x && _y <= other_room._end_y && _end_y >= other_room._y) return true;
    return false;
}


Map::Map(int width, int height) {
    
    _width = width;
    _height = height;
    
    for (int y = 0; y < height; y++) {
        std::vector<Tile*> row;
        for (int x = 0; x < width; x++) {
            row.push_back(new Tile());
        }
        _tile.push_back(row);
    }
}

Tile * Map::get_tile(int x, int y) {
    return _tile[y][x];
}

int Map::get_maxx() {
    return _tile[0].size();
    
}

int Map::get_maxy() {
    return _tile.size();
    
}

bool Map::make_room(int x, int y, int width, int height) {
    vector<Room*>::iterator room_it;
    Room * new_room = new Room(x,y,width,height);
    
    for (room_it = _rooms.begin(); room_it < _rooms.end(); room_it++) {
        if (new_room->overlaps(*(*room_it))) {
            return false;
        }
    }
    for (int mx = x; mx < x+ width; mx++) {
        for (int my = y; my < y+width; my++) {
            _tile[my][mx]->set_blocking(false);
        }
    }
    _rooms.push_back(new_room);
    return true;

}

void Map::make_h_tunnel(int start_x, int end_x, int y) {
    for (int x = std::min(start_x, end_x); x < std::max(start_x, end_x); x++) {
        _tile[y][x]->set_blocking(false);
    }
}

void Map::make_v_tunnel(int start_y, int end_y, int x) {
    for (int y = std::min(start_y, end_y); y < std::max(start_y, end_y); y++) {
        _tile[y][x]->set_blocking(false);
    }
    
}

void Map::make_tunnel(int start_x, int start_y, int end_x, int end_y) {
    make_h_tunnel(start_x, end_x, start_y);
    make_v_tunnel(start_y, end_y, end_x);
}

void Map::create_level() {
    srand(2);
    msg_handler.msg("Hello, is this working?");
    //make_room(_width/2-5, _height/2-5, 10, 10);
    //make_tunnel(_width/2, _height/2, 2, 2);
    int last_x=_width/2;
    int last_y=_height/2;
    for (int i = 0; i < 4; i++) {
        int x = rand()%(_width-5);
        int y = rand()%(_height-5);
        make_room(x, y, 5, 5);
        //make_tunnel(last_x, last_y, x, y);
        last_x = x;
        last_y = y;
    }
}