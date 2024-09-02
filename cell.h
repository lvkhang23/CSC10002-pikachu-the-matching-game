#pragma once

#include "utility.h"

struct CELL // Cell struct for normal mode
{
    int i, j;
    char character = ' ';
    bool isValid = true, isHovered = false, isSelected = false, isSuggested = false;

    void drawBox(int level, int background = 0);
    void deleteBox(int level);
};

struct SUPER_CELL // Cell struct for sliding mode
{
    int i, j;
    char character = ' ';
    bool isHovered = false, isSelected = false, isSuggested = false;
    SUPER_CELL *next;

    void drawBox(int level, int background = 0);
    void deleteBox(int level);
};

int countNodes(SUPER_CELL *head);

void push(SUPER_CELL *&head, SUPER_CELL *p);
