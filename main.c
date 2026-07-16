#include <stdio.h>
#include <stdlib.h>
#include "blueprints.h"
#include "activities.c"

int main(void){

    //board
    square board[25];

    //modeling the board
    board[0] = (square){1,none};
    board[1] = (square){2,none};
    board[2] = (square){3,none};

    return 0;
}
