//
//  MessageHandler.h
//  Rascal
//
//  Created by Lomax Oliver on 02/06/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#ifndef __Rascal__MessageHandler__
#define __Rascal__MessageHandler__

#include <stdio.h>
#include <vector>
#include <ncurses.h>
#include <string>

class MessageHandler {
    std::vector<std::string> _msg_list;
    WINDOW * _win;

public:
    MessageHandler(WINDOW * win);
    MessageHandler();
    void init(WINDOW * win);
    void msg(std::string);
};

#endif /* defined(__Rascal__MessageHandler__) */
