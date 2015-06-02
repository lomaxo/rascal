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

MessageHandler::MessageHandler() {
    
}

void MessageHandler::init(WINDOW * win) {
    _win = win;
}


void MessageHandler::msg(std::string str) {
    _msg_list.push_back(str);
    wclear(_win);
    std::vector<std::string>::reverse_iterator it;
    int i = 10;
    for (it = _msg_list.rbegin(); it < _msg_list.rend(); it++) {
        mvwprintw(_win, i, 0, it->c_str());
        i--;
    }
    wrefresh(_win);
}
