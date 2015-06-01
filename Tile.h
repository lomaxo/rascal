//
//  Tile.h
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#ifndef __Rascal__Tile__
#define __Rascal__Tile__

#include <stdio.h>

class Tile {
public:
    Tile();
    bool is_blocking() { return _is_blocking; }
    void set_blocking(bool b) { _is_blocking = b; }
private:
    bool _is_blocking = true;
    //int x, y;
 
};

#endif /* defined(__Rascal__Tile__) */
