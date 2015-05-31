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

class Map {
public:
    Map(int width, int height);
    Tile * get_tile(int x, int y);
    int get_maxx();
    int get_maxy();
    
private:
    std::vector< std::vector<Tile*> > _tile;
    
    
};

#endif /* defined(__Rascal__Map__) */
