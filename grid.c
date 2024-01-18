#include <stdbool.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

#include "ant.h"
#include "grid.h"


void initializeGrid(cell ***grid, int n, int m) {
        *grid = malloc(n * sizeof(cell*));
        for (int i = 0; i < n; i++) {
                (*grid)[i] = malloc(m * sizeof(cell));
                for (int j = 0; j < m; j++) {
                    (*grid)[i][j].color = true;
                }
        }
}

void printGrid(cell **grid, ant a, int n, int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("┌───");
        }
        printf("┐\n");
        for (int j = 0; j < n; j++){
            printf("│");
            if (a.n == j && a.m == i){ // Pole z mrówką
                // Wybór odpowiedniego symbolu dla mrówki
                if(grid[j][i].color){ // Białe pole
                    switch (a.direction){
                        case 'n': printf(" △ "); break;
                        case 'e': printf(" ▷ "); break;
                        case 's': printf(" ▽ "); break;
                        case 'w': printf(" ◁ "); break;
                    }
                } else { // Czarne pole
                    switch (a.direction){
                        case 'n': printf(" ▲ "); break;
                        case 'e': printf(" ▶ "); break;
                        case 's': printf(" ▼ "); break;
                        case 'w': printf(" ◀ "); break;
                    }
                }
            } else { // Puste pole
                printf("%s", grid[j][i].color ? "   " : " █ ");
            }
        }
        printf("│\n");

        for (int j = 0; j < n; j++){
            printf("└───");
        }
        printf("┘\n");
    }
}

void writeToFile(cell **grid, ant a, int n, int m, char *outputFile){   
    
    FILE *file = fopen(outputFile, "w"); 
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(file, "┌───");
        }
        fprintf(file, "┐\n");
        for (int j = 0; j < n; j++){
            fprintf(file, "│");
            if (a.n == j && a.m == i){ // Pole z mrówką
                // Wybór odpowiedniego symbolu dla mrówki
                if(grid[j][i].color){ // Białe pole
                    switch (a.direction){
                        case 'n': fprintf(file, " △ "); break;
                        case 'e': fprintf(file, " ▷ "); break;
                        case 's': fprintf(file, " ▽ "); break;
                        case 'w': fprintf(file, " ◁ "); break;
                    }
                } else { // Czarne pole
                    switch (a.direction){
                        case 'n': fprintf(file, " ▲ "); break;
                        case 'e': fprintf(file, " ▶ "); break;
                        case 's': fprintf(file, " ▼ "); break;
                        case 'w': fprintf(file, " ◀ "); break;
                    }
                }
            } else { // Puste pole
                fprintf(file, "%s", grid[j][i].color ? "   " : " █ ");
            }
        }
        fprintf(file, "│\n");

        for (int j = 0; j < n; j++){
            fprintf(file, "└───");
        }
        fprintf(file, "┘\n");
    }
    fclose(file);
}
