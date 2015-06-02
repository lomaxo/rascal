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

void Map::make_room(int x, int y, int width, int height) {
    for (int mx = x; mx < x+ width; mx++) {
        for (int my = y; my < y+width; my++) {
            _tile[my][mx]->set_blocking(false);
        }
    }

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
    make_room(_width/2-5, _height/2-5, 10, 10);
    make_tunnel(_width/2, _height/2, 2, 2);
    int last_x=_width/2;
    int last_y=_height/2;
    for (int i = 0; i < 10; i++) {
        int x = rand()%(_width-5);
        int y = rand()%(_height-5);
        make_room(x, y, 5, 5);
        make_tunnel(last_x, last_y, x, y);
        last_x = x;
        last_y = y;
    }
}