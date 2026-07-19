#include "blueprints.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
int diceRoll(void) {
    srand(time(NULL));
    int steps = rand() % 6 + 1;
    return steps;
}
int movePlayer(player Player_x, int steps) {

    Player_x.position = Player_x.position + steps;
    if (Player_x.position > 30) {
        Player_x.position -= steps;
        printf("Too high than the end point.. retry in next turn\n");
        return Player_x.position;
    }
    printf("player %c moved to square : %d \n", Player_x.name,
           Player_x.position);
    return Player_x.position;
}
int SnakeLadderCheck(player Player_x, square board[30]) {

    if (board[Player_x.position - 1].specialSquare == snakeHead) {
        int newPositionAfterSnake = board[Player_x.position - 1].teleport;
        printf("Caught by a snake  :(  \n teleporting to square %d\n",
               board[Player_x.position - 1].teleport);
        return newPositionAfterSnake;
    }
    if (board[Player_x.position - 1].specialSquare == ladderBottom) {
        int newPositionAfterLadder = board[Player_x.position - 1].teleport;
        printf("Got into a ladder :) teleporting to square %d\n",
               board[Player_x.position - 1].teleport);
        return newPositionAfterLadder;
    }
    return Player_x.position;
}
int winnerCheck(player Player_x) {
    if (Player_x.position == 30) {
        int NewStatusAfterMove = win;
        return NewStatusAfterMove;
    }
    return Player_x.playerStatus;
}
