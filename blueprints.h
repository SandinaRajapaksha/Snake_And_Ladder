#ifndef BLUEPRINTS_H
#define BLUEPRINTS_H

// square
typedef enum { none, snakeHead, ladderBottom } speciality;

typedef struct {
    int squareNumber;
    speciality specialSquare;
    int teleport;
} square;

// player
typedef enum {
    win,
    playing,
} status;

typedef struct {
    char name;
    int position;
    status playerStatus;
} player;

// functionality
int diceRoll(void);
int movePlayer(player Player_x, int steps);
int SnakeLadderCheck(player Player_x, square board[30]);
int winnerCheck(player Player_x);
// int diceRoll(void);
#endif
