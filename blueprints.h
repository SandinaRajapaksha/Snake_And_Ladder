#ifndef BLUEPRINTS_H
#define BLUEPRINTS_H

//square
typedef enum{
    none,
    snakeHead,
    ladderBottom
} speciality;

typedef struct{
    int squareNumber;
    speciality specialSquare;
    int teleport;
} square;

// player
typedef enum{
    win,
    playing
} status;

typedef struct{
    char name;
    int position;
    status playerStatus;
} player;


#endif
