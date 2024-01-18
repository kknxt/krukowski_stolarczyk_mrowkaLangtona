#ifndef _ANT_H
#define _ANT_H

#include <stdbool.h>


typedef struct ant{
    int n;
    int m;
    char direction;
    // 'n' - north, 'e' - east, 's' - south, 'w' - west
} ant;

typedef struct cell{
    bool color; // true - white, false - black
} cell;


ant initializeAnt(int n, int m, char direction);

void move(ant* a, cell* c, int n, int m);

#endif
