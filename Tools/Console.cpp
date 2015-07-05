//
//  Console.cpp
//  TankGame
//
//  Created by Jacob Gonzalez on 11/04/2015.
//  Copyright (c) 2015 Jacob Gonzalez. All rights reserved.
//

#include <unistd.h>
#include <sys/ioctl.h>
#include <cstdlib>

#include "Console.h"

namespace Tools
{

bool Console::audio = true;
bool Console::replay = false;

std::string Console::get_line()
{
    std::string input;
    getline(std::cin, input);
    return input;
}

void Console::set_title(char const *title)
{
    printf("\x1b]2;%s\x07", title);
}

void Console::set_fcolor(Console::Color color)
{
    printf("\033[%dm", color);
}

void Console::set_bcolor(Console::Color color)
{
   printf("\033[%dm", color+10);
}

void Console::set_color(Console::Color fcolor, Console::Color bcolor)
{
    printf("\033[%d;%dm", fcolor, bcolor+10);
}

void Console::end_color()
{
    printf("\033[%dm", endc);
}

void Console::hide_text()
{
    printf("\033[8m");
}

void Console::reverse_color()
{
    printf("\033[7m");
}

void Console::clear_screen()
{
    printf("\033[2J");
    set_cursor(0, 0);
}

void Console::clear_line()
{
    printf("\033[K");
}

void Console::set_cursor(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

void Console::set_cursor(Point<int> pos)
{
    printf("\033[%d;%dH", pos.y, pos.x);
}

void Console::move_cursor(Console::Direction dir, int dist)
{
    printf("\033[%d%c", dist, static_cast<char>(dir));
}

Point<int> Console::get_terminal_size()
{
    winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    Point<int> p(win.ws_col, win.ws_row);
    return p;
}

void Console::stop_music()
{
    if (audio == false)
    {
        return;
    }

    #ifdef __APPLE__
            system("killall afplay");
    #elif __linux__
            system("killall aplay");
    #endif
}

void Console::play_music(std::string filename)
{
    if (audio == false)
    {
        return;
    }

    std::ifstream file(filename.c_str(), std::ios::binary);
    if (file.good() == true)
    {
        #ifdef __APPLE__
            system(std::string("afplay " + filename + "&").c_str());
        #elif __linux__
            system(std::string("aplay -q " + filename + " &").c_str());
        #endif
    }
    else
    {
        audio = false;
    }
    file.close();
}

} // Tools
