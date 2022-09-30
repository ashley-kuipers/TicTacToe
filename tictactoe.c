#include <stdio.h>
#include <stdlib.h>
int printGame(char currentGame[3][3]);
int computerMove();
int checkWin(char currentGame[3][3]);

int main(void)
{
    // declare initial variables
    char name[20];
    int currentRow, currentCol, win;

    // create empty game
    char currentGame[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // print intro, prompts user for the name
    printf("*********************************\nTic Tac Toe\nComp 2131 - Fall 2022\nYou will be playing against the computer\n*********************************\n\n\nWhat is your first name?\n");
    scanf("%s", name);

    // prints empty board
    printf("\nHello %s ... Let's have fun !!! You = X | Computer = O\n\n", name);
    printGame(currentGame);

    do{
        // getting move from user
        printf("Enter row and column for your move ('#,#', from 1-3): ");
        scanf("%d,%d", &currentRow, &currentCol);

        currentGame[currentRow-1][currentCol-1] = (char) 'X';

        // getting computer move
        int validMove = 0;
        do{
            // get row, col for comp move
            int compRow = (rand() % (3));
            int compCol = (rand() % (3));

            // check if move isn't taken
            if (currentGame[compRow][compCol] != 'X' ||currentGame[compRow][compCol] != 'O'){
                currentGame[compRow][compCol] = (char) 'O';
                validMove = 1;
                printf("Computer's move is valid");
            } else {
                printf("Comp move is not valid");
            }
        }
        while (validMove = 0);


        printGame(currentGame);

        win = checkWin(currentGame);

    } while (win == 0);

    return 0;
}

int printGame(char currentGame[3][3]){

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

    return 0;
}

int computerMove(char currentGame[3][3]){
    // have computer move stuff here

    // send move to main?

}

int resetGame(){
    // clear board
    // display welcome again
}

int getUserMove(){
    // TODO: move user prompt stuff here
}

int checkWin(char currentGame[3][3]){
    // check for horizontal wins
    if (currentGame[0][0] == currentGame[0][1] == currentGame[0][2] || currentGame[1][0] == currentGame[1][1] == currentGame[1][2] || currentGame[2][0] == currentGame[2][1] == currentGame[2][2])
    {
        printf("Win!\n");
        return 1;

    }
    // check for vertical wins
    else if (currentGame[0][0] == currentGame[1][0] == currentGame[2][0] || currentGame[0][1] == currentGame[1][1] == currentGame[2][1] || currentGame[0][2] == currentGame[1][2] == currentGame[2][2])
    {
        printf("Win!\n");
        return 0;
    }
    // check for diagonal wins
    else if (currentGame[0][0] == currentGame[1][1] == currentGame[2][2] || currentGame[0][2] == currentGame[1][1] == currentGame[2][0])
    {
        printf("Win!\n");
        return 1;
    }
    // else no wins yet
    else
    {
        printf("no win yet\n");
        return 0;
    }

}


// TODO: ideally, get to the point where overall structure is:
// while(!win && !reset){
    // user prompt
    // computer move
    // print board
// }

// TODO: account for user input outside range

// TODO: current problems:
// computer only seems to go in middle row?
// computers move is replacing user move
// didn't detect the win




