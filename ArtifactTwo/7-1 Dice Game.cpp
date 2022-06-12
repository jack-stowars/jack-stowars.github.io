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
    /*
    * rulesfile is used to access file containing game rules
    * userInput is used to navigate menu choices
    * fileText is used to display each line of the rulesfile text ti display to players
    */

    fstream rulesfile;
    char userInput;
    string fileText;


    /*
    *  RollDice is function used to roll dice for each player's turn
    *  roll is used for player input to initiate next turn/roll
    *  playerCount is used to list off each player's chips at the start of each turn
    *  turn is used to keep track of current turn's player for proper chip exchanges in RollDice function
    *  i is used for iterating through "for" loops to assign starting chips and displaying each player's chips at the start of each turn
    */

    int *RollDice(int chips[], int turn, int players);
    string roll;
    int playerCount = 0;
    int turn = 0;
    int i;


    /*
    * IsWinner is a function that determines when only one player has chips
    * winner is boolean used to end the game when a winner is determined
    */
    bool IsWinner(int chips[], int players);
    bool winner = false;
    


    /* Do while loop that runs a switch case while the user has not exited the program
    *  Case 1 is starting a game of LCR
    *  Case 2 is displaying rules to players
    *  Case 3 is terminating program
    */
    do {

        // Prints list of potential options (1 inializes game of LCR, 2 lists rules, 3 exits program)
        cout << "[1] Start game" << endl;
        cout << "[2] Read rules" << endl;
        cout << "[3] Exit" << endl << endl;
        cout << "Please select from the options above: ";

        // Gets input from user for which selection they chose
        cin >> userInput;

        // Spacer to separate input from result
        cout << "==========" << endl;

        // Switch case based on userInput
        switch (userInput) {

            // Initializes a game of LCR
            case '1':
            {

                // Prompts the user for player count until there are at least 3 players
                do {
                    cout << "Enter amount of players: ";
                    cin >> playerCount;

                    // playerCount must be at least 3 for LCR to be played
                    if (playerCount < 3) {
                        cout << "Not enough players. Please have 3 or more players." << endl;
                    }

                    else {
                        cout << playerCount << " players will be playing this round." << endl;
                    }

                } while (playerCount < 3);

                cout << "==========" << endl;

                // Generates an array to store user scores
                int* playerChips = new int[playerCount];

                // Gives each player 3 chips to start with
                for (i = 0; i < playerCount; ++i) {
                    playerChips[i] = 3;
                }

                // Do while loop that runs as long as there is an active game and no winner has been determined yet
                do {

                    // Prints each player's chip count at the beginning of each turn
                    for (i = 0; i < playerCount; ++i) {
                        cout << "Player " << i + 1 << " has " << playerChips[i] << " chips." << endl;
                    }
                    cout << "          " << endl;

                    // Prints out whose turn it is (condition: turn counter is equal to player count)
                    if (turn == playerCount) {
                        cout << "It is currently player " << turn - (playerCount - 1) << "'s turn." << endl;
                    }

                    // Prints out whose turn it is (condition: turn counter is any other value not equal to the player count)
                    else {
                    cout << "It is currently player " << turn + 1 << "'s turn." << endl;
                    }

                    // Prompts the user for input to roll the dice
                    cout << "Press '1' and enter to roll the dice: ";
                    cin >> roll;

                    // Divider between turn display and rolls
                    cout << "--------" << endl;

                    // Progresses the turn if turn counter is less than total player count
                    if (turn < playerCount) {
                        playerChips = RollDice(playerChips, turn, playerCount);
                    }

                    // Resets turn counter to 0 once last player has been reached
                    else {
                        turn = 0;
                        playerChips = RollDice(playerChips, turn, playerCount);
                    }

                    // Divider between turn display and rolls
                    cout << "--------" << endl;

                    // Checks if only one player has more than 0 chips
                    winner = IsWinner(playerChips, playerCount);

                    ++turn;
                } while (!winner);


                // Lists out the player chip counts at the end of the game
                for (i = 0; i < playerCount; ++i) {
                    cout << "Player " << i + 1 << " has " << playerChips[i] << " chips." << endl;
                }
                cout << "==========" << endl;

                // Prints out the winner & game over message
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

            // Lists off the rules of LCR to the player
            case '2':
            {

                // Opens the rulesfile to display rules to the player
                rulesfile.open("rules.txt", ios::in);

                // While loop that gets and prints out content from the file while there are still lines of text
                while (getline(rulesfile, fileText)) {
                    cout << fileText << "\n";
                }

                // Closes the file
                rulesfile.close();
            }
                break;

            // Exits the program
            case '3':
            {
                cout << "Exiting program..." << endl;
            }
                break;
        }

        // Divider for menu inputs
        cout << "==========" << endl;

    } while (userInput != '3');

}

    /* Function that rolls dice for each's players turn
    *  chips[] is array of current player's chip count
    *  turn is used to get chips from current turn's player to roll proper amount of dice
    *  players is used to properly distribute chips for players at the beginning/end of chips[] array
    */
    int *RollDice(int chips[], int turn, int players) {
        srand(time(0));

        /* 
        *  diceRolls[] stores rolls for each turn, resets to 0 every iteration
        *  rollCount is used to prevent more than 3 rolls per turn
        *  j is used in "for" loop to move chips based on rolls
        *  k is used in "for" loop to roll dice
        */

        int diceRolls[3] = {0,0,0};
        int rollCount;
        int j;
        int k;


        // If current player has 0 chips, does not roll dice and passes turn to next player
        if (chips[turn] == 0) {
            cout << "Player " << turn + 1 << " has no chips, moving to next player." << endl;
            return chips;
        }

        // If current player has 1 or more chips, initiates the dice rolling functionality
        else if (chips[turn] >= 1) {

            // Assigns 3 to rollCount if current player's chip count is greater than 3 to prevent errors
            if (chips[turn] > 3) {
                rollCount = 3;
            }

            // Assigns current chip count to rollCount in current player's chip count is 3 or less
            else {
                rollCount = chips[turn];
            }

            // Rolls dice for each iteration and assigns results to diceRolls[] array
            for (k = 0; k < rollCount; ++k) {
                diceRolls[k] = rand() % 6 + 1;
            }
        }

        // Iterates through diceRolls[] array and assigns chips based on results
        for (j = 0; j < 3; ++j) {

            // If roll was 1, passes chips to player on the left
            if (diceRolls[j] == 1) {
                chips[turn] -= 1;

                // If current player is player 1, moves chip to last player in array
                if (turn == 0) {
                    chips[players - 1] += 1;
                }

                // If current player is not player one, moves chips one player to the left in the array
                else {
                    chips[turn - 1] += 1;
                }

                // Announces roll results
                cout << "Roll #" << j + 1 << " was '1' or 'L'" << endl;
            }

            // If roll was 2, moves chip to center (removed from the game) and announces roll results
            else if (diceRolls[j] == 2) {
                chips[turn] -= 1;
                cout << "Roll #" << j + 1 << " was '2' or 'C'" << endl;
            }

            // If roll was 3, passes chips to player on the right
            else if (diceRolls[j] == 3) {
                chips[turn] -= 1;

                // If current player is last player in array, moves chip to first player in array
                if ((turn + 1) == players) {
                    chips[0] += 1;
                }

                // If current player is not last player in array, moves chips one player to the right in the array
                else {
                    chips[turn + 1] += 1;
                }

                // Announces roll results
                cout << "Roll #" << j + 1 << " was '3' or 'R'" << endl;
            }

            // If roll was 4/5/6, no chips are moved and chips[] array is unchanged
            else if (diceRolls[j] == 4 || diceRolls[j] == 5 || diceRolls[j] == 6){
                cout << "Roll #" << j + 1 << " was '4/5/6'" << endl;
            }

            // If player has 1 or 2 chips, announced unused dice rolls
            else {
                cout << "Roll #" << j + 1 << " was not rolled, as the player didn't have enough chips" << endl;
                continue;
            }

        }

        return chips;
    }


    /*
    *  IsWinner is a function that determines if only one player has chips remaining
    *  chips[] gets the current chip counts of each player to check for a winner
    *  players is used to iterate through "for" loop to check for a winner
    */
    bool IsWinner(int chips[], int players) {

        /* zeroChips is used to check against players
        *  k is used to iterate through chips[] array
        */
        int zeroChips = 0;
        int k;


        // Iterates through chips[] array to check for winner
        for (k = 0; k < players; ++k) {
            if (chips[k] == 0) {
                zeroChips += 1;
            }
        }

        // If zeroChips is 1 less than the total amount of players, IsWinner returns "true" and the winner is declared
        if (zeroChips == players - 1) {
            return true;
        }

        // If zeroChips is anything else, IsWinner returns false and the game continues
        else {
            return false;
        }
    }
    