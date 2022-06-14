// 7-1 Dice Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    JACK STOWARS
    12/4/2021
    IT-312-J2237
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //Initializes the variables for reading the rules.txt file and displaying it to the player(s)
    fstream rulesfile;
    char userInput;
    string fileText;

    //Initializes the RollDice function and variables relevant to the function
    int *RollDice(int chips[], int turn, int players);
    string roll;
    int playerCount = 0;
    int turn = 0;
    int i;

    //Initializes the IsWinner function and the variable relevant to it
    bool IsWinner(int chips[], int players);
    bool winner = false;
    

    //Do while loop that runs while the user has not exited the program
    do {

        //Prints list of potential options (1 not implemented, 2 lists rules, 3 exits program)
        cout << "[1] Start game" << endl;
        cout << "[2] Read rules" << endl;
        cout << "[3] Exit" << endl << endl;
        cout << "Please select from the options above: ";

        //Gets input from user for which selection they chose
        cin >> userInput;

        //Spacer to separate input from result
        cout << "==========" << endl;

        //Switch case based on userInput
        switch (userInput) {

            //Initializes a game of LCR
            case '1':
            {

                //Prompts the user for player count until there are at least 3 players
                do {
                    cout << "Enter amount of players: ";
                    cin >> playerCount;

                    if (playerCount < 3) {
                        cout << "Not enough players. Please have 3 or more players." << endl;
                    }

                    else {
                        cout << playerCount << " players will be playing this round." << endl;
                    }

                } while (playerCount < 3);

                cout << "==========" << endl;

                //Generates an array to store user scores
                int* playerChips = new int[playerCount];

                //Gives each player 3 chips to start with
                for (i = 0; i < playerCount; ++i) {
                    playerChips[i] = 3;
                }

                //Do while loop that runs as long as there is an active game and no winner has been determined yet
                do {
                    //Prints each player's chip count at the beginning of each turn
                    for (i = 0; i < playerCount; ++i) {
                        cout << "Player " << i + 1 << " has " << playerChips[i] << " chips." << endl;
                    }
                    cout << "          " << endl;

                    //Prints out whose turn it is (condition: turn counter is equal to player count)
                    if (turn == playerCount) {
                        cout << "It is currently player " << turn - (playerCount - 1) << "'s turn." << endl;
                    }

                    //Prints out whose turn it is (condition: turn counter is any other value not equal to the player count)
                    else {
                    cout << "It is currently player " << turn + 1 << "'s turn." << endl;
                    }

                    //Prompts the user for input to roll the dice
                    cout << "Press '1' and enter to roll the dice: ";
                    cin >> roll;

                    //Divider between turn display and rolls
                    cout << "--------" << endl;

                    //Progresses the turn if turn counter is less than total player count
                    if (turn < playerCount) {
                        playerChips = RollDice(playerChips, turn, playerCount);
                    }

                    //Resets turn counter to 0 once last player has been reached
                    else {
                        turn = 0;
                        playerChips = RollDice(playerChips, turn, playerCount);
                    }

                    //Divider between turn display and rolls
                    cout << "--------" << endl;

                    //Checks if only one player has more than 0 chips
                    winner = IsWinner(playerChips, playerCount);

                    ++turn;
                } while (!winner);


                //Lists out the player chip counts at the end of the game
                for (i = 0; i < playerCount; ++i) {
                    cout << "Player " << i + 1 << " has " << playerChips[i] << " chips." << endl;
                }
                cout << "==========" << endl;

                //Prints out the winner, game over message, and end game message
                for (i = 0; i < playerCount; ++i) {
                    if (playerChips[i] == 0) {
                        continue;
                    }

                    else {
                        cout << "Player " << i + 1 << " has won the game!" << endl;
                    }
                }
                cout << "=====GAME OVER=====" << endl;
            }
                break;

            //Lists off the rules of LCR to the player
            case '2':
            {

                //Opens the file to display rules to the player
                rulesfile.open("rules.txt", ios::in);

                //While loop that gets and prints out content from the file while there are still lines of text
                while (getline(rulesfile, fileText)) {
                    cout << fileText << "\n";
                }

                //Closes the file
                rulesfile.close();
            }
                break;

            //Exits the program
            case '3':
            {
                cout << "Exiting program..." << endl;
            }
                break;
        }

        cout << "==========" << endl;

    } while (userInput != '3');

}

    
    int *RollDice(int chips[], int turn, int players) {
        srand(time(0));

        int diceRolls[3] = {0,0,0};
        int j;


        if (chips[turn] == 0) {
            cout << "Player " << turn + 1 << " has no chips, moving to next player." << endl;
            return chips;
        }

        else if (chips[turn] == 1) {
            diceRolls[0] = rand() % 6 + 1;
        }

        else if (chips[turn] == 2) {
            diceRolls[0] = rand() % 6 + 1;
            diceRolls[1] = rand() % 6 + 1;
        }

        else {
            diceRolls[0] = rand() % 6 + 1;
            diceRolls[1] = rand() % 6 + 1;
            diceRolls[2] = rand() % 6 + 1;
        }

        for (j = 0; j < 3; ++j) {
            if (diceRolls[j] == 1) {
                chips[turn] -= 1;

                if (turn == 0) {
                    chips[players - 1] += 1;
                }

                else {
                    chips[turn - 1] += 1;
                }
                cout << "Roll #" << j + 1 << " was '1' or 'L'" << endl;
            }

            else if (diceRolls[j] == 2) {
                chips[turn] -= 1;
                cout << "Roll #" << j + 1 << " was '2' or 'C'" << endl;
            }

            else if (diceRolls[j] == 3) {
                chips[turn] -= 1;

                if ((turn + 1) == players) {
                    chips[0] += 1;
                }

                else {
                    chips[turn + 1] += 1;
                }
                cout << "Roll #" << j + 1 << " was '3' or 'R'" << endl;
            }

            else if (diceRolls[j] == 4 || diceRolls[j] == 5 || diceRolls[j] == 6){
                cout << "Roll #" << j + 1 << " was '4/5/6'" << endl;
            }

            else {
                cout << "Roll #" << j + 1 << " was not rolled, as the player didn't have enough chips" << endl;
                continue;
            }

        }

        return chips;
    }

    bool IsWinner(int chips[], int players) {
        int zeroChips = 0;
        int k;

        for (k = 0; k < players; ++k) {
            if (chips[k] == 0) {
                zeroChips += 1;
            }
        }

        if (zeroChips == players - 1) {
            return true;
        }

        else {
            return false;
        }
    }
    