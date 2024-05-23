#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

// Function prototypes
void displayMainMenu(int *pMainMenuChoice);
void drawGameBoard(string gameBoard[3][3]);
char getPlayerAvatar();
bool isLineFound(string *pWinner, string gameBoard[3][3]);

int main()
{
    int mainMenuChoice;
    string gameBoard[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}}; // Initialize game board
    bool lineFound = false; // Flag to check if a winning line is found
    char playerAvatar; // Player's avatar ('X' or 'O')
    char computerAvatar; // Computer's avatar ('X' or 'O')
    string winner; // Winner of the game

    displayMainMenu(&mainMenuChoice); // Display main menu and get user's choice

    switch (mainMenuChoice)
    {
    case 1:
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " Nice, let's start the game! 🎮";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        playerAvatar = getPlayerAvatar(); // Get player's avatar choice

        cout << "Great! Your choice is '" << playerAvatar << "'." << endl;
        // Assign computer's avatar based on player's choice
        if (playerAvatar == 'x' || playerAvatar == 'X')
        {
            computerAvatar = 'o';
        }
        else
        {
            computerAvatar = 'x';
        }

        do
        {
            srand(time(0)); // Seed the random number generator
            int random_number_col = rand() % 3; // Generate random column for computer move
            srand(time(0) + 1); // Seed the random number generator again
            int random_number_row = rand() % 3; // Generate random row for computer move
            int playerCoordinates[2]; // Player's move coordinates

            drawGameBoard(gameBoard); // Draw the current game board

            // Get player's move
            cout << "Enter number of row: ";
            cin >> playerCoordinates[0];
            cout << "Enter number of column: ";
            cin >> playerCoordinates[1];
            cout << "\n"
                 << endl;

            // Check if the chosen cell is empty
            while (gameBoard[playerCoordinates[0]][playerCoordinates[1]] != " ")
            {
                cout << "Sorry, but there's already an avatar there.\nPlease enter different coordinates. \n"
                     << endl;
                cout << "Enter number of row: ";
                cin >> playerCoordinates[0];
                cout << "Enter number of column: ";
                cin >> playerCoordinates[1];
                cout << "\n"
                     << endl;
            }
            gameBoard[playerCoordinates[0]][playerCoordinates[1]] = playerAvatar; // Update board with player's move

            // Generate computer's move
            do
            {
                srand(time(0));
                random_number_col = rand() % 3;
                srand(time(0) + 1);
                random_number_row = rand() % 3;
            } while (gameBoard[random_number_row][random_number_col] != " "); // Ensure computer's move is on an empty cell
            gameBoard[random_number_row][random_number_col] = computerAvatar; // Update board with computer's move

            lineFound = isLineFound(&winner, gameBoard);

        } while (!lineFound); // Repeat until a winning line is found

        cout << "Game over!\nWinner is " << winner << endl; // Display the winner
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
        main(); // Restart the game if an invalid choice is entered
        break;
    }
    return 0;
}

// Function to display the main menu and get user's choice
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

// Function to get player's avatar choice ('X' or 'O')
char getPlayerAvatar()
{
    char userAvatarChoice;
    cout << "Which avatar would you like to play as, 'X' or 'O' character?" << endl;
    cout << "Enter 'X/x' or 'O/o': ";
    cin >> ws >> userAvatarChoice;

    // Validate user's avatar choice
    while (userAvatarChoice != 'x' && userAvatarChoice != 'X' && userAvatarChoice != 'o' && userAvatarChoice != 'O')
    {
        cout << "Please enter a correct choice!" << endl;
        cout << "Enter 'X/x' or 'O/o': ";
        cin >> ws >> userAvatarChoice;
    }

    return userAvatarChoice;
}

// Function to draw the game board
void drawGameBoard(string gameBoard[3][3])
{
    for (int r = 0; r <= 2; r++)
    {
        for (int c = 0; c <= 2; c++)
        {
            if (c == 2)
            {
                cout << gameBoard[r][c] << " ";
            }
            else
            {
                cout << gameBoard[r][c] << " | ";
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
    }
}

bool isLineFound(string *pWinner, string gameBoard[3][3]) {

            // Check for a winning line in columns and rows
            for (int i = 0; i <= 2; i++)
            {
                if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != " ")
                {
                    return true;
                    *pWinner = gameBoard[0][i];
                } else if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != " ")
                {
                    return true;
                    *pWinner = gameBoard[i][0];
                } else {
                    return false;
                    continue;
                }
            }

            // Check diagonals for a winning line
            if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != " ")
            {
                return true;
                *pWinner = gameBoard[0][0];
            }
            else if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != " ")
            {
                return true;
                *pWinner = gameBoard[0][2];
            }
            else {
                return false;
            }
}