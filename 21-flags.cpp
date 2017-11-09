/*
    21 Flags
    (c) Afaan Bilal
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int PLAYER_COMPUTER = 1;
const int PLAYER_PERSON   = 2;

int flags = 21;
int currentPlayer = PLAYER_COMPUTER;
bool hasWon = false;

void displayFlags();
void checkIfWon();

int main()
{
    cout << "\t\t\t21 Flags" << endl;
    cout << "\thttps://github.com/AfaanBilal/21-flags" << endl << endl << endl;
    cout << "\tRules:\n\t1. There are 21 flags." << endl;
    cout << "\t2. Each player can take 1, 2 or 3 flags in each turn." << endl;
    cout << "\t3. The player to take the last flag wins." << endl << endl;
    cout << "\tYou are playing against the computer." << endl;
    cout << "\tDo you want to go first? (y/n) : ";
    char choice = 'n';
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        currentPlayer = PLAYER_PERSON;

    while (!hasWon)
    {
        displayFlags();
        switch (currentPlayer)
        {
            case PLAYER_PERSON:
                {
                    int flagsToTake = 0;
                    cout << endl << "\tNumber of flags you want to take: ";
                    cin >> flagsToTake;
                    if (flagsToTake > 3 || flagsToTake < 1)
                    {
                        cout << "\tYou can only take 1, 2 or 3 flags at each turn." << endl;
                        break;
                    }
                    flags -= flagsToTake;
                    cout << "\tYou took " << flagsToTake << " flag(s)." << endl;
                    currentPlayer = PLAYER_COMPUTER;
                }
                break;

            case PLAYER_COMPUTER:
                {
                    int flagsToTake = flags % 4;
                    if (flagsToTake == 0)
                       {
                           srand(time(NULL));
                           flagsToTake = (rand() % 3) + 1  ;
                       }
                    flags -= flagsToTake;
                    cout << "\tComputer took " << flagsToTake << " flag(s)." << endl;
                    currentPlayer = PLAYER_PERSON;
                }
                break;
        }
        checkIfWon();
    }
}

void displayFlags()
{
    cout << endl;
    cout << "\t";
    for (int i = 1; i <= 21; i++)
    {
        if (i > flags)
            cout << "* | ";
        else
            cout << i << " | ";
    }
    cout << endl;
}

void checkIfWon()
{
    if (flags == 0)
    {
        hasWon = true;
        displayFlags();
        if (currentPlayer == PLAYER_COMPUTER)
            cout << endl << "\t\t\t\tCongratulations! You have won!" << endl;
        else
            cout << endl << "\t\t\t\tSorry! The computer has won!" << endl;
    }
}
