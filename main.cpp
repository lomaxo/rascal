//
//  main.cpp
//  Rascal
//
//  Created by Lomax Oliver on 30/05/2015.
//  Copyright (c) 2015 Oliver Lomax. All rights reserved.
//

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Tile.h"
#include "Player.h"
#include "Map.h"
#include "MessageHandler.h"

int main(int argc, const char * argv[]) {

    // Set up the curses windows
    initscr();
    noecho();
    curs_set(FALSE);
    
    int screen_x, screen_y;
    getmaxyx(stdscr, screen_y, screen_x);
    WINDOW *view_win = newwin(screen_y-10, screen_x, 0,0);
    WINDOW *msg_win = newwin(10, screen_x, screen_y-10,0);
    
    int view_x, view_y;
    getmaxyx(view_win, view_y, view_x);
    
    MessageHandler msg_handler(msg_win);
    
    // Create the player and put them in the centre
    Player player;
    player.move(view_x/2, view_y/2);
    
    // Create the map
    const int map_maxx = view_x;
    const int map_maxy = view_y;
    Map * map = new Map(map_maxx, map_maxy);

    // Set up a room in the centre
    //map->make_room(map_maxx/2-5, map_maxy/2-5, 10, 10);
    map->create_level();
    char ch;
    
    // Enter the main loop
    while (ch != 'Q') {
        //mvwprintw(msg_win, 0, 0, "key pressed %c %i %i", ch, map->get_maxx(), map->get_maxy());
        std::string s = "Hello";
        s.append(" test");
        msg_handler.msg(s);
        int step_x =0 , step_y =0;
        switch (ch) {
            case 'h':
                step_x -= 1;
                break;
            case 'l':
                step_x += 1;
                break;
            case 'j':
                step_y += 1;
                break;
            case 'k':
                step_y -= 1;
                break;
            case 'y':
                step_x -= 1;
                step_y -= 1;
                break;
            case 'u':
                step_x += 1;
                step_y -= 1;
                break;
            case 'b':
                step_x -= 1;
                step_y += 1;
                break;
            case 'n':
                step_x += 1;
                step_y += 1;
                break;
                
            default:
                break;
        }
        
        // Move the player if not blocked
        if (!map->get_tile(player.x()+step_x, player.y()+step_y)->is_blocking()) {
            player.move(player.x()+step_x, player.y()+step_y);
        }
        
        // Draw Map
        for (int mx =0; mx < map_maxx; mx++) {
            for (int my = 0; my < map_maxy; my++) {
                if (map->get_tile(mx, my)->is_blocking()) mvwaddch(view_win, my, mx, '#');
                else mvwaddch(view_win, my, mx, '.');
            }
        }
        
        // Draw the player and update the windows
        mvwaddch(view_win, player.y(), player.x(), player.ch());
        wrefresh(view_win);
        wrefresh(msg_win);
        
        // Wait for next input
        ch = getch();
    }
    
    endwin();
    return 0;
}
