#include "activities.c"
#include "blueprints.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define true 1

// funtionality

int diceRoll(void) {
    srand(time(NULL));
    int steps = rand() % 6 + 1;
    return steps;
}
int movePlayer(player Player_x, int steps) {

    Player_x.position = Player_x.position + steps;
    if (Player_x.position > 30) {
        Player_x.position -= steps;
        printf("Too high than the end point.. retry in next turn");
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
}

int main(void) {

    // board
    square board[30];

    // modeling the board
    board[0] = (square){1, none};
    board[1] = (square){2, none};
    board[2] = (square){3, ladderBottom, 22};
    board[3] = (square){4, none};
    board[4] = (square){5, ladderBottom, 8};
    board[5] = (square){6, none};
    board[6] = (square){7, none};
    board[7] = (square){8, none};
    board[8] = (square){9, none};
    board[9] = (square){10, none};
    board[10] = (square){11, ladderBottom, 26};
    board[11] = (square){12, none};
    board[12] = (square){13, none};
    board[13] = (square){14, none};
    board[14] = (square){15, none};
    board[15] = (square){16, none};
    board[16] = (square){17, snakeHead, 4};
    board[17] = (square){18, none};
    board[18] = (square){19, snakeHead, 7};
    board[19] = (square){20, ladderBottom, 29};
    board[20] = (square){21, snakeHead, 9};
    board[21] = (square){22, none};
    board[22] = (square){23, none};
    board[23] = (square){24, snakeHead, 1};
    board[24] = (square){25, none};
    board[25] = (square){26, none};
    board[26] = (square){27, none};
    board[27] = (square){28, none};
    board[28] = (square){29, none};
    board[29] = (square){30, none};

    player player1 = {'A', 1, playing};
    player player2 = {'B', 1, playing};

    int player_1_steps;
    int player_2_steps;
    char winner;
    while (true) {

        // player 1 chance
        player_1_steps = 0;
        player_1_steps = diceRoll();
        player1.position = movePlayer(player1, player_1_steps);
        player1.position = SnakeLadderCheck(player1, board);
        player1.playerStatus = winnerCheck(player1);

        sleep(1);
        // player 2 chance
        player_2_steps = 0;
        player_2_steps = diceRoll();
        player2.position = movePlayer(player2, player_2_steps);
        player2.position = SnakeLadderCheck(player2, board);
        player2.playerStatus = winnerCheck(player2);

        sleep(1);

        if (player1.playerStatus == win) {
            winner = 'A';
            break;
        }
        if (player2.playerStatus == win) {
            winner = 'B';
            break;
        }
    }

    printf("Yaaay .....  Player %c win\n", winner);

    return 0;
}
