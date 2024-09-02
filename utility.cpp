#include "utility.h"

void setColor(int colorCode) // Sets color of a specific text
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, colorCode);
}

void goTo(short x, short y) // Move the cursor to a specified coordinate
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coord;
    Coord.X = x;
    Coord.Y = y;
    SetConsoleCursorPosition(hStdout, Coord);
}

void hideCursor() // Hides the mouse cursor
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void zoomScreen() // Zooms the console window
{
    HWND Hwnd = GetForegroundWindow();
    ShowWindow(Hwnd, SW_MAXIMIZE);
}

void zoomScreen2() // Zooms the console to full screen
{
    HWND Hwnd = GetForegroundWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);
    SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(Hwnd, HWND_TOP, 0, 0, x, y, 0);

}

void playBackgroundMusic() // Plays background music
{
    PlaySound(TEXT("backgroundMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
