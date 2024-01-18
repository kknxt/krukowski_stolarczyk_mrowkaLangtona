#ifndef _GRID_H
#define _GRID_H

#include <stdbool.h>

#include "ant.h"


void initializeGrid(cell ***grid, int n, int m);

void printGrid(cell **grid, ant a, int n, int m);

void writeToFile(cell **grid, ant a, int n, int m, char *outputFile);

#endif
