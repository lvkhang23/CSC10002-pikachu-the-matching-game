#include "normalGame.h"


void GAME::moveUp() // Moves cell upward
{
    for (int i = x; i <= width; i++)
    {
        for (int j = y - 1; j >= 1; j--)
        {
            if (board[j - 1][i - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = i;
                y = j;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }

    for (int i = x - 1; i >= 1; i--)
    {
        for (int j = y - 1; j >= 1; j--)
        {
            if (board[j - 1][i - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = i;
                y = j;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }
}

void GAME::moveDown() // Moves cell downward
{
    for (int i = x; i <= width; i++)
    {
        for (int j = y + 1; j <= height; j++)
        {
            if (board[j - 1][i - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = i;
                y = j;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }

    for (int i = x - 1; i >= 1; i--)
    {
        for (int j = y + 1; j <= height; j++)
        {
            if (board[j - 1][i - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = i;
                y = j;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }
}

void GAME::moveRight() // Moves cell to the right
{
    for (int i = y; i >= 1; i--)
    {
        for (int j = x + 1; j <= width; j++)
        {
            if (board[i - 1][j - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = j;
                y = i;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }

    for (int i = y + 1; i <= height; i++) {
        for (int j = x + 1; j <= width; j++) {
            if (board[i - 1][j - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = j;
                y = i;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }
}

void GAME::moveLeft() // Moves cell to the left
{
    for (int i = y; i >= 1; i--)
    {
        for (int j = x - 1; j >= 1; j--)
        {
            if (board[i - 1][j - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = j;
                y = i;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }

    for (int i = y + 1; i <= height; i++)
    {
        for (int j = x - 1; j >= 1; j--)
        {
            if (board[i - 1][j - 1].isValid)
            {
                board[y - 1][x - 1].isHovered = false;
                x = j;
                y = i;
                board[y - 1][x - 1].isHovered = true;
                PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
        }
    }
}

bool GAME::checkEmptyLine(int x1, int y1, int x2, int y2) // Check if there is an empty or unobstructed path between to cells
{
    if (y1 == y2) {
        int a, b, count = 0;

        a = min(x1, x2);
        b = max(x1, x2);

        for (int i = a; i <= b; i++)
        {
            if (board[y1 - 1][i - 1].isValid)
            {
                count++;
            }
        }
        if (count == 2)
            return false;
        if ((count == 1) && ((!board[y1 - 1][x1 - 1].isValid && board[y2 - 1][x2 - 1].isValid) || (board[y1 - 1][x1 - 1].isValid && !board[y2 - 1][x2 - 1].isValid)))
        {
            return true;
        }
        else if (count == 0) {
            return true;
        }
        return false;
    }

    if (x1 == x2) {
        int a, b, count = 0;
        if (y1 > y2) {
            a = y2;
            b = y1;
        }
        else {
            a = y1;
            b = y2;
        }
        for (int i = a; i <= b; i++)
        {
            if (board[i - 1][x1 - 1].isValid)
            {
                count++;
            }
        }
        if (count == 2)
            return false;
        if ((count == 1) && ((!board[y1 - 1][x1 - 1].isValid && board[y2 - 1][x2 - 1].isValid) || (board[y1 - 1][x1 - 1].isValid && !board[y2 - 1][x2 - 1].isValid)))
        {
            return true;
        }
        else if (count == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GAME::checkIMatching(int x1, int y1, int x2, int y2) // Checks I-shaped matching
{
    if (y1 == y2) {
        int a, b;
        a = min(x1, x2);
        b = max(x1, x2);
        for (int i = a + 1; i < b; i++)
        {
            if (board[y1 - 1][i - 1].isValid)
            {
                return false;
            }
        }
        return true;
    }

    if (x1 == x2) {
        int a, b;
        if (y1 > y2) {
            a = y2;
            b = y1;
        }
        else {
            a = y1;
            b = y2;
        }
        for (int i = a + 1; i < b; i++)
        {
            if (board[i - 1][x1 - 1].isValid)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool GAME::checkLMatching(int x1, int y1, int x2, int y2) // Checks L-shaped matching
{
    if (y1 == y2 || x1 == x2)
    {
        return false;
    }

    bool check1, check2;
    if (!board[y1 - 1][x2 - 1].isValid)
    {
        check1 = checkEmptyLine(x1, y1, x2, y1);
        check2 = checkEmptyLine(x2, y2, x2, y1);
        if (check1 && check2)
        {
            return true;
        }
    }

    if (!board[y2 - 1][x1 - 1].isValid)
    {
        check1 = checkEmptyLine(x1, y1, x1, y2);
        check2 = checkEmptyLine(x2, y2, x1, y2);
        if (check1 && check2)
        {
            return true;
        }
    }
    return false;
}

bool GAME::checkZMatching(int x1, int y1, int x2, int y2) // Checks Z-shaped matching
{
    if (y1 == y2 || x1 == x2)
    {
        return false;
    }

    bool check1, check2, check3;
    int a, b;
    a = min(x1, x2);
    b = max(x1, x2);
    for (int i = a + 1; i < b; i++) {
        check3 = checkEmptyLine(i, y1, i, y2);
        if (check3)
        {
            check1 = checkEmptyLine(x1, y1, i, y1);
            check2 = checkEmptyLine(x2, y2, i, y2);
            if (check1 && check2)
                return true;
        }
    }
    a = min(y1, y2);
    b = max(y1, y2);
    for (int i = a + 1; i < b; i++)
    {
        check3 = checkEmptyLine(x1, i, x2, i);
        if (check3)
        {
            check1 = checkEmptyLine(x1, y1, x1, i);
            check2 = checkEmptyLine(x2, y2, x2, i);
            if (check1 && check2)
                return true;
        }
    }
    return false;
}

bool GAME::checkUMatching(int x1, int y1, int x2, int y2) // Checks U-shaped matching
{
    if (((y1 == y2) && (y1 == 1 || y1 == height)) || ((x1 == x2) && (x1 == 1 || x1 == width)))
    {
        return true;
    }

    bool check1, check2, check3;
    int a, b;

    a = min(x1, x2);
    b = max(x1, x2);
    for (int i = 1; i <= width; i++)
    {
        if (i <= a || i >= b)
        {
            check3 = checkEmptyLine(i, y1, i, y2);
            if (check3)
            {
                check1 = checkEmptyLine(x1, y1, i, y1);
                check2 = checkEmptyLine(x2, y2, i, y2);

                if (check1 && check2)
                    return true;
            }
            else if (i == 1 || i == width)
            {
                check1 = checkEmptyLine(x1, y1, i, y1);
                check2 = checkEmptyLine(x2, y2, i, y2);
                if ((check1 && check2) || (check1 && x2 == i) || (x1 == i && check2))
                    return true;
            }
        }
    }

    a = min(y1, y2);
    b = max(y1, y2);
    for (int i = 1; i <= height; i++)
    {
        if (i <= a || i >= b)
        {
            check3 = checkEmptyLine(x1, i, x2, i);
            if (check3)
            {
                check1 = checkEmptyLine(x1, y1, x1, i);
                check2 = checkEmptyLine(x2, y2, x2, i);
                if (check1 && check2)
                    return true;
            }
            else if (i == 1 || i == height)
            {
                check1 = checkEmptyLine(x1, y1, x1, i);
                check2 = checkEmptyLine(x2, y2, x2, i);
                if ((check1 && check2) || (check1 && y2 == i) || (y1 == i && check2))
                    return true;
            }
        }
    }
    return false;
}

bool GAME::checkAllMatchings(int x1, int y1, int x2, int y2) // Checks all matchings
{
    if (checkIMatching(x1, y1, x2, y2))
        return true;
    if (checkLMatching(x1, y1, x2, y2))
        return true;
    if (checkZMatching(x1, y1, x2, y2))
        return true;
    if (checkUMatching(x1, y1, x2, y2))
        return true;
    return false;
}

bool GAME::checkValidPairs() // Checks whether there is any pair that can be matched
{
    char character = 'A';
    while (character >= 'A' && character <= 'Z')
    {
        int count = 0;
        int *pos = new int[remainingPairs * 2 * 2];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (board[i][j].character == character && board[i][j].isValid)
                {
                    pos[count++] = i;
                    pos[count++] = j;
                }
            }
        }

        for (int i = 0; i < count - 2; i += 2)
        {
            for (int j = i + 2; j < count; j += 2)
            {
                if (checkAllMatchings(pos[i + 1] + 1, pos[i] + 1, pos[j + 1] + 1, pos[j] + 1))
                {
                    delete[] pos;
                    return true;
                }
            }
        }
        character++;
        delete[] pos;
    }
    return false;
}

int GAME::play() // Start game
{
    system("cls");
    PlaySound(NULL, NULL, 0);
    board[0][0].isHovered = true;
    x = 1, y = 1;

    int temp, key;
    int count = 0;
    int selected = 0;
    POSITION selectedPos[2];

    printSideMenu();
    printBackground(player.level);
    player.printStatusBar();

    int initialLife = player.life;
    int initialScore = player.currentScore;

    while (true)
    {
        if (player.life == 0)
        {
            Sleep(500);

            if (youLost(player) == 1)
            {
                player.updatePlayer();
                return 1;
            }
            else
            {
                player.updatePlayer();
                return -1;
            }
        }

        if (remainingPairs == 0)
            break;

        if (!checkValidPairs())
        {
            player.life--;
            player.comboFactor = 1.0;
            player.printStatusBar();

            while (!checkValidPairs())
                shuffleBoard();

            PlaySound(TEXT("shuffle.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        if (!board[y - 1][x - 1].isValid) // Find a valid cell if the cell we are hovering on no longer exists
        {
            int delta = 1;
            while (!board[y - 1][x - 1].isValid)
            {
                for (int i = -delta; i <= delta; i++)
                {
                    for (int j = -delta; j <= delta; j++)
                    {
                        if (y + i < 1 || y + i > height || x + j < 1 || x + j > width)
                            continue;

                        if (board[y - 1 + i][x - 1 + j].isValid)
                        {
                            board[y - 1][x - 1].isHovered = false;
                            y = y + i;
                            x = x + j;
                            board[y - 1][x - 1].isHovered = true;
                            goto exitLoop;
                        }
                    }
                }
            exitLoop:
                delta++;
            }
        }

        printBoard(); // Repeatedly print out the board

        temp = _getch();
        if (temp && temp != 224)
        {
            if (temp == 'M' || temp == 'm')
            {
                player.life = initialLife;
                player.currentScore = initialScore;
                return -1;
            }
            else if (temp == 'Q' || temp == 'q')
            {
                if (player.life > 1)
                {
                    player.life--;
                    player.printStatusBar();
                    suggestMove();
                }
            }
            else if (temp == 32) //When cell is selected
            {
                board[y - 1][x - 1].isSelected = true;
                selectedPos[selected].x = x;
                selectedPos[selected].y = y;
                selected++;

                if (selected == 1)
                {
                    PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
                }

                if (selected == 2)
                {
                    if (!(selectedPos[0].x == selectedPos[1].x && selectedPos[0].y == selectedPos[1].y)) // Check if two cells are not at the same spot
                    {
                        if (board[selectedPos[0].y - 1][selectedPos[0].x - 1].character == board[selectedPos[1].y - 1][selectedPos[1].x - 1].character)
                        {
                            if (checkAllMatchings(selectedPos[0].x, selectedPos[0].y, selectedPos[1].x, selectedPos[1].y)) // They can match
                            {
                                PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);

                                board[selectedPos[0].y - 1][selectedPos[0].x - 1].drawBox(player.level, 10);
                                board[selectedPos[1].y - 1][selectedPos[1].x - 1].drawBox(player.level, 10);

                                Sleep(200);

                                board[selectedPos[0].y - 1][selectedPos[0].x - 1].deleteBox(player.level);
                                board[selectedPos[1].y - 1][selectedPos[1].x - 1].deleteBox(player.level);

                                printCellBackground(player.level, selectedPos[0].x, selectedPos[0].y);
                                printCellBackground(player.level, selectedPos[1].x, selectedPos[1].y);

                                board[selectedPos[0].y - 1][selectedPos[0].x - 1].isValid = false;
                                board[selectedPos[1].y - 1][selectedPos[1].x - 1].isValid = false;

                                turnOffSuggestions();

                                remainingPairs--;
                                player.currentScore += 10 * player.comboFactor;
                                player.comboFactor += 0.1;
                                player.printStatusBar();
                            }
                            else
                            {
                                board[selectedPos[0].y - 1][selectedPos[0].x - 1].drawBox(player.level, 12);
                                board[selectedPos[1].y - 1][selectedPos[1].x - 1].drawBox(player.level, 12);

                                Sleep(300);

                                board[selectedPos[0].y - 1][selectedPos[0].x - 1].isSelected = false;
                                board[selectedPos[1].y - 1][selectedPos[1].x - 1].isSelected = false;

                                PlaySound(TEXT("wrongMatch.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                player.life--;
                                player.comboFactor = 1.0;
                                player.printStatusBar();
                            }
                        }
                        else
                        {
                            board[selectedPos[0].y - 1][selectedPos[0].x - 1].drawBox(player.level, 12);
                            board[selectedPos[1].y - 1][selectedPos[1].x - 1].drawBox(player.level, 12);

                            Sleep(300);

                            board[selectedPos[0].y - 1][selectedPos[0].x - 1].isSelected = false;
                            board[selectedPos[1].y - 1][selectedPos[1].x - 1].isSelected = false;

                            PlaySound(TEXT("wrongMatch.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            player.life--;
                            player.comboFactor = 1.0;
                            player.printStatusBar();
                        }
                    }
                    else
                    {
                        board[selectedPos[0].y - 1][selectedPos[0].x - 1].isSelected = false;
                    }
                    selected = 0;
                }
            }
        }
        else
        {
            key = _getch();
            switch (key)
            {
                case KEY_UP:
                    moveUp();
                    break;
                case KEY_DOWN:
                    moveDown();
                    break;
                case KEY_RIGHT:
                    moveRight();
                    break;
                case KEY_LEFT:
                    moveLeft();
                    break;
            }
        }
    }


    if (player.currentScore > player.highestScore)
    {
        player.highestScore = player.currentScore;
    }

    if (player.level == 3)
    {
        player.currentScore = 0;
        player.level = 1;
        player.life = 10;
        player.comboFactor = 1.0;
    }
    else
    {
        player.level++;
        player.comboFactor = 1.0;
    }

    player.updatePlayer();

    Sleep(500);

    system("cls");
    switch (youWon(player))
    {
        case 1:
            return 1;
        case 2:
            return 2;
    }
}

void GAME::initialize() // Initializing the board
{
    switch (player.level) // Getting the number of cells based on the player's level
    {
        case 1:
            height = 4;
            width = 7;
            break;
        case 2:
            height = 5;
            width = 8;
            break;
        case 3:
            height = 6;
            width = 9;
            break;
    }



    remainingPairs = (height * width) / 2;
    board = new CELL * [height];
    for (int i = 0; i < height; i++)
    {
        board[i] = new CELL[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].i = i;
            board[i][j].j = j;
        }
    }

    int pairNum = (height * width) / 2;
    while (pairNum)
    {
        int index, cells = 2;
        char character = 65 + rand() % 26; // Getting a random character
        while (cells) // Assign a pair
        {
            index = rand() % (height * width);
            if (board[index / width][index % width].character == ' ')
            {
                board[index / width][index % width].character = character;
                cells--;
            }
        }
        pairNum--;
    }
}

void GAME::printBoard() // Prints out the game board
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].drawBox(player.level);
        }
    }
}

void GAME::shuffleBoard() // Shuffles the board when there is no valid pair left
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].character = ' ';
        }
    }

    int temp = remainingPairs;


    while (temp)
    {
        int index, cells = 2;
        char character = 'A' + rand() % 26;
        while (cells)
        {
            index = rand() % (height * width);
            if (board[index / width][index % width].character == ' ' && board[index / width][index % width].isValid)
            {
                board[index / width][index % width].character = character;
                cells--;
            }
        }
        temp--;
    }


}

void GAME::suggestMove() // Suggest a valid pair to the player, costing 1 HP
{
    char character = 'A';
    while (character >= 'A' && character <= 'Z')
    {
        int count = 0;
        int *pos = new int[remainingPairs * 2 * 2];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (board[i][j].character == character && board[i][j].isValid)
                {
                    pos[count++] = i;
                    pos[count++] = j;
                }
            }
        }

        for (int i = 0; i < count - 2; i += 2)
        {
            for (int j = i + 2; j < count; j += 2)
            {
                if (checkAllMatchings(pos[i + 1] + 1, pos[i] + 1, pos[j + 1] + 1, pos[j] + 1))
                {

                    board[pos[i]][pos[i + 1]].isSuggested = true;
                    board[pos[j]][pos[j + 1]].isSuggested = true;
                    delete[] pos;
                    return;
                }
            }
        }
        character++;
        delete[] pos;
    }
}

void GAME::turnOffSuggestions() // Turns off the suggestion if the player don't match the suggested pair
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j].isSuggested == true)
                board[i][j].isSuggested = false;
        }
    }
}
