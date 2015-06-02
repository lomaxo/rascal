//
//  Map.h
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#ifndef __Rascal__Map__
#define __Rascal__Map__

#include <stdio.h>
#include "Tile.h"
#include <vector>

class Room {
    int _width, _height, _x, _y, _end_x, _end_y;
    
public:
    Room(int width, int height, int x, int y);
    bool overlaps(Room other_room);
    
};


class Map {
public:
    Map(int width, int height);
    Tile * get_tile(int x, int y);
    int get_maxx();
    int get_maxy();
    bool make_room(int x, int y, int width, int height);
    void create_level();
    void make_tunnel(int start_x, int start_y, int end_x, int end_y);
    void make_h_tunnel(int start_x, int end_x, int y);
    void make_v_tunnel(int start_y, int end_y, int x);
    
private:
    std::vector< std::vector<Tile*> > _tile;
    int _width, _height;
    std::vector<Room*> _rooms;
    
    
};



#endif /* defined(__Rascal__Map__) */
