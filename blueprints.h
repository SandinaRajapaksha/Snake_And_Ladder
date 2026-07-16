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
} square;


#endif
