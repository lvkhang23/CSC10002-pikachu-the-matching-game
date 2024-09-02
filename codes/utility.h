#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <thread>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 13

using namespace std;

const int MAX_PLAYERS = 200; // Maximum number of players

struct POSITION
{
    int x, y;
};

void setColor(int colorCode);

void goTo(short x, short y);

void hideCursor();

void zoomScreen();

void zoomScreen2();

void playBackgroundMusic();



















