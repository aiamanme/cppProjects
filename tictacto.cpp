#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

// Function declaration.
void displayMainMenu(int *pMainMenuChoice);
char getPlayerAvatar();

int main()
{
    // Variable declaration
    int mainMenuChoice;
    string gameBord[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
    bool lineFound = false;
    char playerAvatar;
    char computerAvatar;

    // Displaying main menu and asking choice.
    displayMainMenu(&mainMenuChoice);

    switch (mainMenuChoice)
    {
    case 1:
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " Nice, let's start the game! 🎮";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        // Getting the player's info.
        playerAvatar = getPlayerAvatar();
        cout << "Great! Your choice is '" << playerAvatar << "'." << endl;
        if (playerAvatar == 'x' || playerAvatar == 'X') {
            computerAvatar = 'o';
        } else {
            computerAvatar = 'x';
        }
        // Main gameplay.
        do
        {
            srand(time(0));
            int random_number_colom = rand() % 3;
            srand(time(0)+1);
            int random_number_row = rand() % 3;
            int playerCoordinates[2];
            // Drowing game bord.
            for (int r = 0; r <= 2; r++)
            {
                for (int c = 0; c <= 2; c++)
                {
                    if (c == 2)
                    {
                        cout << gameBord[r][c] << " ";
                    }
                    else
                    {

                        cout << gameBord[r][c] << " | ";
                    }
                    if (c == 2)
                    {
                        if (r != 2)
                        {
                            cout << "\n----------";
                            cout << '\n';
                        }
                        else
                        {
                            cout << '\n';
                        }
                    }
                }
            };
            // Takign user input.
            cout << "Enter number of row: ";
            cin >> playerCoordinates[0];
            cout << "Enter number of column: ";
            cin >> playerCoordinates[1];
            cout << "\n"
                 << endl;

            // sitting pleayr's character on board.
            while (gameBord[playerCoordinates[0]][playerCoordinates[1]] != " ") {
                cout << "Sorry, but there's already an avatar there.\nPlease Enter different Coordinates. \n" << endl;
                cout << "Enter number of row: ";
                cin >> playerCoordinates[0];
                cout << "Enter number of column: ";
                cin >> playerCoordinates[1];
                cout << "\n"
                    << endl;
            };
            gameBord[playerCoordinates[0]][playerCoordinates[1]] = playerAvatar;
            // computer's turn
            
            do {
                srand(time(0));
                random_number_colom = rand() % 3;
                srand(time(0)+1);
                random_number_row = rand() % 3;
            } while (gameBord[random_number_row][random_number_colom] != " ");
            gameBord[random_number_row][random_number_colom] = computerAvatar;            

            //**** Decide the winner of the game ****//
            bool lineInRow;

            
        } while (lineFound == false);

        break;

    case 2:
        cout << "Instructions for the game? Well, let me tell you something!\n 'There are no instructions' 😂" << endl;
        break;

    case 3:
        cout << "Goodbye 👋" << endl;
        break;

    default:
        cout << "Please enter a correct choice! \n"
             << endl;
        main();
        break;
    }
    return 0;
}

void displayMainMenu(int *pMainMenuChoice)
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << " 🎊 Welcome to the main menu of the game! 🎉" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Choose one of the following options 😇 :" << endl;
    cout << "1. 🎲 | Enter the game." << endl;
    cout << "2. 📜 | Instructions for the game." << endl;
    cout << "3. 🗿 | Exit from the game. \n"
         << endl;

    cout << "Enter your choice 🤔 : ";
    cin >> ws >> *pMainMenuChoice;
}

char getPlayerAvatar()
{
    char userAvatarChoice;
    cout << "Which avatar would you like to play as, 'X' or 'O' character?" << endl;
    cout << "Enter 'X/x' or 'O/o': ";
    cin >> ws >> userAvatarChoice;

    while (userAvatarChoice != 'x' && userAvatarChoice != 'X' && userAvatarChoice != 'o' && userAvatarChoice != 'O')
    {
        cout << "Please enter a correct choice!" << endl;
        cout << "Enter 'X/x' or 'O/o': ";
        cin >> ws >> userAvatarChoice;
    }

    return userAvatarChoice;
}
