#include "cell.h"

char box[5][10] = {
            {"*-------*"},
            {"|       |"},
            {"|       |"},
            {"|       |"},
            {"*-------*"}
}; // For printing out the border of a cell

void CELL::drawBox(int level, int background)
{
    if (!isValid)
        return;

    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    switch (level) // Getting the paddings for each level
    {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }



    for (int i = 0; i < 5; i++)
    {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << box[i];
    }

    if (background != 0)
    {
        setColor(background * 16 + (character % 6) + 1);
        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else if (isSelected)
    {
        setColor(224 + (character % 6) + 1);

        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else if (isHovered)
    {
        setColor(240 + (character % 6) + 1);
        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else if (isSuggested)
    {
        setColor(144 + (character % 6) + 1);

        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else
    {
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        setColor((character % 6) + 1);
        cout << character;
    }

    setColor(15);
}

void CELL::deleteBox(int level)
{
    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    switch (level) // Getting the paddings for each level
    {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }

    for (int i = 0; i < 5; i++)
    {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << "         ";
    }
}

void SUPER_CELL::drawBox(int level, int background)
{
    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    switch (level) // Getting the paddings for each level
    {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }

    for (int i = 0; i < 5; i++)
    {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << box[i];
    }

    if (isSelected)
    {
        if (background == 0)
        {
            setColor(224 + (character % 6) + 1);
            for (int i = 1; i < 4; i++)
            {
                goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
                cout << "       ";
            }
            goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
            cout << character;
            setColor(15);
        }
        else
        {
            setColor(background * 16 + (character % 6) + 1);
            for (int i = 1; i < 4; i++)
            {
                goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
                cout << "       ";
            }
            goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
            cout << character;
            setColor(15);
        }
    }
    else if (isHovered)
    {
        setColor(240 + (character % 6) + 1);
        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else if (isSuggested)
    {
        setColor(176 + (character % 6) + 1);

        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else
    {
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        setColor((character % 6) + 1);
        cout << character;
    }

    setColor(15);
}

void SUPER_CELL::deleteBox(int level)
{
    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    switch (level) // Getting the paddings for each level
    {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }

    for (int i = 0; i < 5; i++)
    {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << "         ";
    }
}

int countNodes(SUPER_CELL *head) // Counts the number of cells left in a row
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void push(SUPER_CELL *&head, SUPER_CELL *p) // Inserts a cell at the beginning of a row
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        SUPER_CELL *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}
