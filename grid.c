#include <stdbool.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ant.h"
#include "grid.h"
#include <unistd.h>


void initializeGrid(bool ***grid, int n, int m) {
        *grid = malloc(n * sizeof(bool*));
        for (int i = 0; i < n; i++) {
                (*grid)[i] = malloc(m * sizeof(bool));
                for (int j = 0; j < m; j++) {
                    (*grid)[i][j] = true;
                }
        }
}

void printGrid(bool **grid, ant a, int n, int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("┌───");
        }
        printf("┐\n");
        for (int j = 0; j < n; j++){
            printf("│");
            if (a.n == j && a.m == i){ // Pole z mrówką
                // Wybór odpowiedniego symbolu dla mrówki
                if(grid[j][i]){ // Białe pole
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
                printf("%s", grid[j][i] ? "   " : " █ ");
            }
        }
        printf("│\n");

        for (int j = 0; j < n; j++){
            printf("└───");
        }
        printf("┘\n");
    }
}

void writeToFile(bool **grid, ant a, int n, int m, char *outputFile){   
    
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
                if(grid[j][i]){ // Białe pole
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
                fprintf(file, "%s", grid[j][i] ? "   " : " █ ");
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

void randomizeGrid(bool **grid, int n, int m, int r){

	int licznik = 0;
	srand((unsigned int)time(NULL));	
	for ( int i = 0; i < r; i++){
    		int rn1 = rand() % n;
		int rn2 = rand() % m;
		if( grid[rn1][rn2]){
			licznik++;
		}
		grid[rn1][rn2] = false;
	}
	int i = 0;
	int j = 0;
	if(licznik < r){
		for(int k = 0; k < 2; k++){
			for(i; i < n; i++){
				for(j=k; j < m; j+=2){
					if(grid[i][j]){
						grid[i][j] = false;
						licznik++;
					}
					if( licznik >= r){
						break;
					}
				}
				if( licznik >= r){
					break;
				}
			}
			if(licznik >= r){
				break;
			}
			i = 0;
		}
	}
}
