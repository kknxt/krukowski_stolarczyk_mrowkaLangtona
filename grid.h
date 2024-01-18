#ifndef _GRID_H
#define _GRID_H

#include <stdbool.h>

#include "ant.h"


void initializeGrid(bool ***grid, int n, int m);

void printGrid(bool **grid, ant a, int n, int m);

void writeToFile(bool **grid, ant a, int n, int m, char *outputFile);

void randomizeGrid(bool **grid, int n, int m, int r);

#endif
