#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ant.h"
#include "grid.h"
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]){
    int n = 0;
    int m = 0;
    int iterations = -1;
    char *outputFile = NULL;
    char dir;
    int random = 0;
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
	    case 'r':
		random = atoi(optarg); 
		break;
            default: // Nieznana opcja
                fprintf(stderr, "Usage: %s -n num -m num -i num -o filename -d direction\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    //obsluga bledow
    if (m < 1 || n < 1){
	    printf("Wymiary siatki powinny byc podane jako liczby wieksze od 0\n");
	    return 1;
    }
    if (iterations < 0){
	    printf("Ilosc iteracji mrowki powinna byc podana jako liczba naturalna\n");
	    return 1;
    }
    if (dir != 'n' && dir != 'e' && dir != 's' && dir != 'w'){
	    printf("Kierunek mrowki powinien zostac podany jako jedna z czterech malych liter alfabetu oznaczjacych kierunki geograficzne (n - polnoc, e - wschod, s - poludnie, w - zachod)\n");
	    return 1;
    }
    if( random < 0 || random > 100){
	    printf("Wartosc procentowego zapelnienia pola powinna byc liczba z zakresu <0,100>\n");
	    return 1;
    }

    if (outputFile != NULL){
    	if (strlen(outputFile) > 250){
	    printf("Dlugosc nazwy pliku wyjsciowego powinna byc krotsza niz 250 znakow\n");
	    return 1;
    	}
    }

    bool **grid;
    ant a = initializeAnt(n, m, dir);
    initializeGrid(&grid, n, m);
    random = n * m * random / 100;
    randomizeGrid(grid, n, m, random);
    if (outputFile != NULL){
	writeToFile(grid, a, n, m, outputFile);
	for(int i = 0; i < iterations; i++){
		move(&a, &grid[a.n][a.m], n, m);
    		char str[256];
    		sprintf(str,"%s_%d", outputFile, i+1);
    		writeToFile(grid, a, n, m, str);
	}
    } else {
    	printGrid(grid, a, n, m);
	for(int i = 0; i < n; i++){
    		printf("_____");
	}
	printf("\n\n");
    	for(int i = 0; i < iterations; i++){
        	move(&a, &grid[a.n][a.m], n, m);
        	printGrid(grid, a, n, m);
		for(int j = 0; j < n; j++){
                	printf("_____");
        }
	printf("\n\n");
    	}
    }
    return 0;
}
