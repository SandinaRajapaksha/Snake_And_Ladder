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
int movePlayer(player Player_x ,int steps){

    Player_x.position = Player_x.position + steps;
    printf("player moved to square : %d " , Player_x.position);
    return Player_x.position;
}
int SnakeLadderCheck(player Player_x , square board[30]){

    if(board[Player_x.position - 1].specialSquare == snakeHead){
        int newPositionAfterSnake = board[Player_x.position -1].teleport;
        return newPositionAfterSnake;
    }
    if(board[Player_x.position - 1].specialSquare == ladderBottom){
        int newPositionAfterLadder = board[Player_x.position -1].teleport;
        return newPositionAfterLadder;
    }
    return  Player_x.position ;
}
int winnerCheck(player Player_x){
    if(Player_x.position == 100){
        int NewStatusAfterMove = win;
        return NewStatusAfterMove;
    }
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

    player player1 = {'A',1,playing};
    player player2= {'B',1,playing};


    printf("%d\n", diceRoll());

    return 0;
}
