//
//  Map.cpp
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#include "Map.h"

Map::Map(int width, int height) {
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