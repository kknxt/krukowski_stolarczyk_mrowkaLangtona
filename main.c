#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ant.h"
#include "grid.h"


int main(int argc, char* argv[]){
    int n = 0;
    int m = 0;
    int iterations = 0;
    char *outputFile = NULL;
    char dir;
    int random;
    int opt;

    while ((opt = getopt(argc, argv, "n:m:i:o:d:r:")) != -1) {
        switch (opt) {
            case 'n': // Liczba kolumn
                n = atoi(optarg);
                break;
            case 'm': // Liczba wierszy
                m = atoi(optarg);
                break;
            case 'i': // Liczba iteracji
                iterations = atoi(optarg);
                break;
            case 'o': // Nazwa pliku wyjściowego
                outputFile = optarg;
                break;
            case 'd': // Początkowy kierunek mrówki
                dir = optarg[0];
                break;
            default: // Nieznana opcja
                fprintf(stderr, "Usage: %s -n num -m num -i num -o filename -d direction\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    cell **grid;
    ant a = initializeAnt(n, m, dir);
    initializeGrid(&grid, n, m);
    printGrid(grid, a, n, m);
    printf("_____________________________________\n\n");
    for(int i = 0; i < iterations; i++){
        move(&a, &grid[a.n][a.m], n, m);
        printGrid(grid, a, n, m);
        printf("_____________________________________\n\n");
    }

    return 0;
}
