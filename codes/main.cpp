#include "utility.h"
#include "normalGame.h"
#include "slidingGame.h"
#include "menuAndControl.h"

int main()
{
    srand(time(0)); // For initializing the cells' characters

    playBackgroundMusic(); // Plays background music
    SetConsoleTitle(TEXT("Pikachu")); // Sets the console title to "Pikachu"
    hideCursor(); // Hides the mouse cursor
    zoomScreen(); // Zooms the console

    printIntro(); // Prints out the Intro screen

    PLAYER leaderboard[MAX_PLAYERS]; // Array to store the leaderboard
    PLAYER P;
    GAME normalGame;
    SUPER_GAME slidingGame;

    bool exit = false;
    while (true)
    {
        switch (P.printMenu(leaderboard))
        {
            case 1: // Sign in
                switch (P.signIn())
                {
                    case 3:
                        if (P.mode == "normal")
                        {
                            system("cls");
                            normalGame.player = P;
                            do
                            {
                                normalGame.initialize();
                            } while (normalGame.play() == 1);
                        }

                        if (P.mode == "sliding")
                        {
                            system("cls");
                            slidingGame.player = P;
                            do
                            {
                                slidingGame.initialize();
                            } while (slidingGame.play() == 1);
                        }
                        break;
                }
                break;
            case 2: // Sign up
                P.signUp();
                break;
            case 3: // Show leaderboard
                showLeaderboard(leaderboard);
                break;
            case 4: // Show tutorial
                printTutorial();
                break;
            default:
                return 0;

        }
        if (exit)
            break;
    }

    return 0;
}
