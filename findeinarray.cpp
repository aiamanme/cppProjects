#include <iostream>
using namespace std;

string cars[99] = {"Mustang", "12Cilindri", "Revuelto", "Chiron", "Friends"};
int carsLength = sizeof(cars) / sizeof(cars[0]);
int findecar(string request);

int main()
{
    string requested;
    int carsLengthNew;
    char choise;

    cout << "This it you current array : ";
    for (string car : cars)
    {
        cout << car << ", ";
        if (car == cars[carsLength - 1])
        {
            cout << car << ".";
        }
    }
    cout << "\n"
         << endl;

    cout << "Do you wont to change the array?" << endl;
    cout << "'Y/y' for Yess \n'N/n' for No" << endl;
    cin >> choise;

    if (choise == 'Y' || choise == 'y')
    {

        cout << "How many cars are you going to add? ";
        cin >> carsLengthNew;

        cout << "Enter cars one by one. " << endl;
        for (int i = 0; i < carsLengthNew; i++)
        {
            string newcar;
            cin >> newcar;
            // this is the problam. Finde how to add element in array
            cars[carsLength + i] = "newcar";
        }

            cout << "This it you current array : ";
    for (string car : cars)
    {
        cout << car << ", ";
        if (car == cars[carsLength - 1])
        {
            cout << car << ".";
        }
    }
    cout << "\n" << endl;
    }
    cout << "Enter the car : ";
    cin >> requested;
    int answer = findecar(requested);

    if (answer != -1)
    {
        cout << "Your result foud on index " << answer << " of the array" << endl;
    }
    else
    {
        cout << "Sorry but found nothing." << endl;
    }

    return 0;
}

int findecar(string request)
{
    for (int i = 0; i < sizeof(cars) / sizeof(string); i++)
    {
        if (cars[i] == request)
        {
            return i;
        }
    }
    return -1;
}