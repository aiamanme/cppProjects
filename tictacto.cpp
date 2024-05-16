#include <iostream>
#include <unistd.h>
using namespace std;

// Function declaration.
void getPlayerName(string* pPlayerName);
void displayMainMenu(int* pMainMenuChoice);
char getPlayerAvatar();

int main() {
    // Variable declaration
    int mainMenuChoice;
    char playerAvatar;
    string playerName = "Not defined";

    // Displaying main menu and asking choice.
    displayMainMenu(&mainMenuChoice);

    switch (mainMenuChoice) {
    case 1:
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " Nice, let's start the game! 🎮";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        // Getting the player's info.
        getPlayerName(&playerName);
        playerAvatar = getPlayerAvatar();
        cout << "Great! Your choice is '" << playerAvatar << "'." << endl;
        break;

    case 2:
        cout << "Instructions for the game? Well, let me tell you something!\n 'There are no instructions' 😂" << endl;
        break;

    case 3:
        cout << "Goodbye 👋" << endl;
        break;

    default:
        cout << "Please enter a correct choice! \n" << endl;
        main();
        break;
    }
    return 0;
}

void getPlayerName(string* pPlayerName) {
    cout << "Before we start, can I get to know your name? : ";
    cin >> ws >> *pPlayerName;

    while (*pPlayerName == "Ai" || *pPlayerName == "AI" || *pPlayerName == "ai" || *pPlayerName == "aI") {
        cout << "Sorry, my name is 'AI'. You can't use my name!" << endl;
        cout << "Enter again: ";
        cin >> *pPlayerName;
    };

    cout << "Hello " << *pPlayerName << ", welcome to the game!" << endl;
}

void displayMainMenu(int* pMainMenuChoice) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << " 🎊 Welcome to the main menu of the game! 🎉" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Choose one of the following options 😇 :" << endl;
    cout << "1. 🎲 | Enter the game." << endl;
    cout << "2. 📜 | Instructions for the game." << endl;
    cout << "3. 🗿 | Exit from the game. \n" << endl;

    cout << "Enter your choice 🤔 : ";
    cin >> ws >> *pMainMenuChoice;
}

char getPlayerAvatar() {
    char userAvatarChoice;
    cout << "Which avatar would you like to play as, 'X' or 'O' character?" << endl;
    cout << "Enter 'X/x' or 'O/o': ";
    cin >> ws >> userAvatarChoice;

    while (userAvatarChoice != 'x' && userAvatarChoice != 'X' && userAvatarChoice != 'o' && userAvatarChoice != 'O') {
        cout << "Please enter a correct choice!" << endl;
        cout << "Enter 'X/x' or 'O/o': ";
        cin >> ws >> userAvatarChoice;
    }

    return userAvatarChoice;
}
