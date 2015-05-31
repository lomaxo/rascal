//
//  Object.h
//  Rascal
//
//  Created by Lomax Oliver on 31/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#ifndef __Rascal__Object__
#define __Rascal__Object__

#include <stdio.h>

class Object {
public:
    Object();
    int x() { return _x; }
    int y() { return _y; }
    int ch() { return _ch; }
    void set_x(int x) { _x = x; }
    void set_y(int y) { _y = y; }
    void set_ch(int ch) { _ch = ch; }
protected:
    int _x, _y;
    char _ch = '@';
};


#endif /* defined(__Rascal__Object__) */
