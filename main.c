#include "blueprints.h"
#include <stdio.h>
#include <unistd.h>
#define true 1

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
        if (player1.playerStatus == win) {
            winner = 'A';
            break;
        }
        sleep(1);
        // player 2 chance
        player_2_steps = 0;
        player_2_steps = diceRoll();
        player2.position = movePlayer(player2, player_2_steps);
        player2.position = SnakeLadderCheck(player2, board);
        player2.playerStatus = winnerCheck(player2);

        if (player2.playerStatus == win) {
            winner = 'B';
            break;
        }
        sleep(1);
    }

    printf("Yaaay .....  Player %c win\n", winner);

    return 0;
}
