#pragma once

#include "utility.h"

struct PLAYER
{
    string username, password, mode;
    int currentScore, highestScore, life, level;
    float comboFactor;

    int getInfo();
    int signIn();
    int signUp();
    int chooseMode();


    int printMenu(PLAYER leaderboard[]);
    void printStatusBar();
    void updatePlayer();
};

void readAndPrintDecor(const string &fileName, int x, int y);

void printBackground(int level);

void printCellBackground(int level, int x, int y);

void printIntro();

void printMenuDecor();

void printSideMenu();

void printTutorial();

int youWon(PLAYER &p);

int youLost(PLAYER &p);

bool comparePlayerScores(PLAYER p1, PLAYER p2);

void sortLeaderboard(PLAYER leaderboard[], int n);

void showLeaderboard(PLAYER leaderboard[]);