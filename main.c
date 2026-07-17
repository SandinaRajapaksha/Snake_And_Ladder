#include <stdio.h>
#include <stdlib.h>
#include "blueprints.h"
#include "activities.c"
#include <time.h>

//funtionality
int diceRoll(void){
    srand(time(NULL));
    int steps = rand() % 6 + 1 ; 
    return steps;
}

int main(void){

    //board
    square board[30];

    //modeling the board
    board[0] = (square){1,none};
    board[1] = (square){2,none};
    board[2] = (square){3,ladderBottom,22};
    board[3] = (square){4,none};
    board[4] = (square){5,ladderBottom,8};
    board[5] = (square){6,none};
    board[6] = (square){7,none};
    board[7] = (square){8,none};
    board[8] = (square){9,none};
    board[9] = (square){10,none};
    board[10] = (square){11,ladderBottom,26};
    board[11] = (square){12,none};
    board[12] = (square){13,none};
    board[13] = (square){14,none};
    board[14] = (square){15,none};
    board[15] = (square){16,none};
    board[16] = (square){17,snakeHead,4};
    board[17] = (square){18,none};
    board[18] = (square){19,snakeHead,7};
    board[19] = (square){20,ladderBottom,29};
    board[20] = (square){21,snakeHead,9};
    board[21] = (square){22,none};
    board[22] = (square){23,none};
    board[23] = (square){24,snakeHead,1};
    board[24] = (square){25,none};
    board[25] = (square){26,none};
    board[26] = (square){27,none};
    board[27] = (square){28,none};
    board[28] = (square){29,none};
    board[29] = (square){30,none};


    // snake heads 
    // 24 to 1
    // 21 to 9
    // 17 to 4
    // 19 to 7
    //
    // ladder bottoms
    // 11 to 26
    // 3 to 22
    // 5 to 8
    // 20 to 29
    //

    // initializing players
    
    player player1 = {'A',0,playing};
    player player2= {'B',0,playing};

    printf("%d\n", diceRoll());

    return 0;
}
