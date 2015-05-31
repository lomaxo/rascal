//
//  Player.h
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#ifndef __Rascal__Player__
#define __Rascal__Player__

#include <stdio.h>
#include "Object.h"

class Player : public Object {
public:
    Player();
    //int _x, _y;
    //char ch = '@';
    void move(int x, int y);
    bool step(int x, int y);
    
};

#endif /* defined(__Rascal__Player__) */
