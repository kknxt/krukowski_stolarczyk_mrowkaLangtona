#include <stdbool.h>

#include "ant.h"
#include "grid.h"


ant initializeAnt(int n, int m, char direction){
    ant a;
    a.n = n / 2;
    a.m = m / 2;
    a.direction = direction;
    return a;
}

void move(ant* a, cell* c, int n, int m){
    if(c->color == true){
        c->color = false;
        switch (a->direction)
        {
        case 'n':
            a->direction = 'e';
            a->n = (++a->n) % n;
            break;
        case 'e':
            a->direction = 's';
            a->m = (++a->m) % m;
            break;
        case 's':
            a->direction = 'w';
            if(a->n == 0){
                a->n = n - 1;
            } else {
                --a->n;
            }
            break;
        case 'w':
            a->direction = 'n';
            if(a->m == 0){
                a->m = m - 1;
            } else {
                --a->m;
            }
            break;
        }
    } else {
        c->color = true;
        switch (a->direction)
        {
        case 'n':
            a->direction = 'w';
            if(a->n == 0){
                a->n = n - 1;
            } else {
                --a->n;
            }
            break;
        case 'e':
            a->direction = 'n';
            if(a->m == 0){
                a->m = m - 1;
            } else {
                --a->m;
            }
            break;
        case 's':
            a->direction = 'e';
            a->n = (++a->n) % n;
            break;
        case 'w':
            a->direction = 's';
            a->m = (++a->m) % m;
            break;
        }
    }
}