#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// explicit declaration of functions
int printGame(char currentGame[3][3]);
int getCompMove(char currentGame[3][3]);
int checkUserWin(char currentGame[3][3]);
int checkCompWin(char currentGame[3][3]);
int getUserMove(char currentGame[3][3]);
int numSpacesLeft(char currentGame[3][3]);
int validMove(int row, int col, char currentGame[3][3]);

int main(void) {
    // declare initial variables
    char name[20];
    int win = 0;

    // create empty game
    char currentGame[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // print intro, prompts user for the name
    printf("*********************************\nTic Tac Toe\nComp 2131 - Fall 2022\nYou will be playing against the computer\n*********************************\n\nWhat is your first name?\n");
    scanf("%s", name);

    // prints empty board
    printf("\nHello %s ... Let's have fun !!! You = X | Computer = O\n\n", name);
    printGame(currentGame);

    // play game
    while (win == 0) {
        getUserMove(currentGame);

        getCompMove(currentGame);

        printGame(currentGame);

        // check if the game needs to end for any reason (draw or win)
        if(numSpacesLeft(currentGame) == 0) {
            // if no spaces left, game is a draw
            printf("Computer cannot make a move.\n");
            printf("The game is a draw!\n");
            win = 1;
        } else {
            // check if user wins
            if (checkUserWin(currentGame) == 1) {
                printf("You win! Congratulations!\n");
                win = 1;
            } else {
                // check if computer wins (doing this inside the other if so that if they both win at the same time, user's win is counted)
                if (checkCompWin(currentGame) == 1) {
                    printf("Sorry, you lose. Please try again!\n");
                    win = 1;
                }
            }
        }

    }

    printf("Thank you for playing!\n");

}

// the function prints the current game board to the screen
int printGame(char currentGame[3][3]) {

    printf("\n");
    // row 1
    printf(" %c | %c | %c ", currentGame[0][0], currentGame[0][1], currentGame[0][2]);
    printf("\n---|---|---\n");

    // row 2
    printf(" %c | %c | %c ", currentGame[1][0], currentGame[1][1], currentGame[1][2]);
    printf("\n---|---|---\n");

    // row 3
    printf(" %c | %c | %c ", currentGame[2][0], currentGame[2][1], currentGame[2][2]);
    printf("\n\n");

}

// the function generates a random move for computer and adds it to the game array
int getCompMove(char currentGame[3][3]) {
    // random generator
    srand(time(NULL));

    // initial variables
    int validMoveVar = 0;

    // checks if there are still spaces left for the computer to go, if so, comp randomly picks a move
    if(numSpacesLeft(currentGame)>0) {
        do{
            // get row, col for comp move
            int compRow = (rand() % (3));
            int compCol = (rand() % (3));

            // check if spot isn't taken
            if (currentGame[compRow][compCol] != 'X' && currentGame[compRow][compCol] != 'O') {
                currentGame[compRow][compCol] = (char) 'O';
                validMoveVar = 1;
            }

        } while (validMoveVar == 0); // continue loop until valid move is selected
    }

}

// the function prompts the user to pick a move and adds it to the game array
int getUserMove(char currentGame[3][3]) {
    // initial variables
    int currentRow, currentCol, validMoveVar = 0;

    // validating the user entry
    do{
        printf("Enter row and column for your move ('#,#', from 1-3): ");
        scanf("%d,%d", &currentRow, &currentCol);

        if (validMove(currentRow-1, currentCol-1, currentGame)==0) {
            printf("That is not a valid move. Please enter a move within the range and that isn't already taken.\n");
        } else {
            validMoveVar = 1;
        }

    } while (validMoveVar == 0); // loop continues until a valid move is chosen

    currentGame[currentRow-1][currentCol-1] = (char) 'X';

}

// the function checks if the current move is valid
int validMove(int row, int col, char currentGame[3][3]) {
    // initial variables
    int validMove = 1;

    // validate input
    if (row < 0 || row > 2 || col < 0 || col > 2 || currentGame[row][col] == 'X' || currentGame[row][col] == 'O') {
        // not valid move
        validMove = 0;
    }

    return validMove;

}

// the function checks if the user (player X) has won
int checkUserWin(char currentGame[3][3]) {
    // initial variables
    int win=0;

    // check for horizontal wins
    if ((currentGame[0][0] == currentGame[0][1] && currentGame[0][1] == currentGame[0][2] && currentGame[0][2] == 'X') ||
        (currentGame[1][0] == currentGame[1][1] && currentGame[1][1] == currentGame[1][2] && currentGame[1][2] == 'X') ||
        (currentGame[2][0] == currentGame[2][1] && currentGame[2][1] == currentGame[2][2] && currentGame[2][2] == 'X')) {
        win = 1;
    }
    // check for vertical wins
    else if ((currentGame[0][0] == currentGame[1][0] && currentGame[1][0] == currentGame[2][0] && currentGame[2][0] == 'X') ||
        (currentGame[0][1] == currentGame[1][1] && currentGame[1][1] == currentGame[2][1] && currentGame[2][1] == 'X') ||
        (currentGame[0][2] == currentGame[1][2] && currentGame[1][2] == currentGame[2][2] && currentGame[2][2] == 'X')) {
        win = 1;
    }
    // check for diagonal wins
    else if ((currentGame[0][0] == currentGame[1][1] && currentGame[1][1] == currentGame[2][2] && currentGame[2][2] == 'X') ||
        (currentGame[0][2] == currentGame[1][1] && currentGame[1][1] == currentGame[2][0] && currentGame[2][0] == 'X')) {
        win = 1;
    }

    return win;

}

// the function checks if the computer (player O) has won
int checkCompWin(char currentGame[3][3]) {
    // initial variables
    int win = 0;

    // check for horizontal wins
    if ((currentGame[0][0] == currentGame[0][1] && currentGame[0][1] == currentGame[0][2] && currentGame[0][2] == 'O') ||
        (currentGame[1][0] == currentGame[1][1] && currentGame[1][1] == currentGame[1][2] && currentGame[1][2] == 'O') ||
        (currentGame[2][0] == currentGame[2][1] && currentGame[2][1] == currentGame[2][2] && currentGame[2][2] == 'O')){
        win = 1;

    }
    // check for vertical wins
    else if ((currentGame[0][0] == currentGame[1][0] && currentGame[1][0] == currentGame[2][0] && currentGame[2][0] == 'O') ||
        (currentGame[0][1] == currentGame[1][1] && currentGame[1][1] == currentGame[2][1] && currentGame[2][1] == 'O') ||
        (currentGame[0][2] == currentGame[1][2] && currentGame[1][2] == currentGame[2][2] && currentGame[2][2] == 'O')) {
        win = 1;
    }
    // check for diagonal wins
    else if ((currentGame[0][0] == currentGame[1][1] && currentGame[1][1] == currentGame[2][2] && currentGame[2][2] == 'O') ||
        (currentGame[0][2] == currentGame[1][1] && currentGame[1][1] == currentGame[2][0] && currentGame[2][0] == 'O')) {
        win = 1;
    }

    return win;

}

// checks the number of empty spaces on the baord
int numSpacesLeft(char currentGame[3][3]) {
    // initial variables
    int numSpaces=0;

    // loops through the 2D array and checks how many contain spaces
    for (int i = 0 ; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (currentGame[i][j] == ' ') {
                numSpaces++;
            }
        }
    }

    return numSpaces;

}
