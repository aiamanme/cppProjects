#include <iostream> 
#include <unistd.h>
using namespace std;


// Function declaration.
void takingGeysName(string * pPlayerName);
void mainMenu(int * pMainMenuChoise);

int main() {
    int mainMenuChoise;
    string playerName = "Not defined";

    // Printing main menu and asking choise.
    mainMenu(&mainMenuChoise);

    switch (mainMenuChoise)
    {
    case 1:
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " Nice, The let's start the Game! 🎮";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        // Taking the geys name.
        takingGeysName(&playerName);

        break;

    case 2: 
        cout << "Instruction of game ha? Well let me tell you something!\n 'Thear are not instruction' 😂" << endl;
        break;

    case 3:
        cout << "Then Bye-Bye 👋" << endl;
        break;
    
    default:
        cout << "Sir, Pleas enter a correct! \n" << endl;
        main();
        break;
    }
    return 0;
}

void takingGeysName(string * pPlayerName) {
        cout << "Before the can i get to know 'you name?' : ";
        cin >> ws >> *pPlayerName;

        while ( *pPlayerName == "Ai" || *pPlayerName == "AI" || *pPlayerName == "ai" || *pPlayerName == "aI" ) {
            cout << "Sorry bro my name is 'Ai', You can't take my name!" << endl;
            cout << "Enter again! : ";
            cin >> *pPlayerName;
        };
        
        cout << "Hello " << *pPlayerName << ", welcome to the game!" << endl;
}

void mainMenu(int * pMainMenuChoise) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << " 🎊 This is main menu of the game! 🎉" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Choice one of the following 😇 :" << endl;
    cout << "1. 🎲 | Enter the game. " << endl; 
    cout << "2. 📜 | Instruction for the game. " << endl;
    cout << "3. 🗿 | Exit from Game. \n" << endl; 

    cout << "Enter You Choice 🤔 : ";
    cin >> ws >> *pMainMenuChoise;
}