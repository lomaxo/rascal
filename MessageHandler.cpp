//
//  MessageHandler.cpp
//  Rascal
//
//  Created by Lomax Oliver on 02/06/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#include "MessageHandler.h"

MessageHandler::MessageHandler(WINDOW * win) {
    _win = win;
}


void MessageHandler::msg(std::string str) {
    mvwprintw(_win, 0, 0, str.c_str());
}
