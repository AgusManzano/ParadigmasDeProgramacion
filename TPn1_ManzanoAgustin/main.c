/*
Alumno: Agustin Manzano
Legajo: 34547
Universidad de San Andrés
Paradigmas de la Programación
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tp1.h"
#include "funcionesTp1.c" 


// Bloque Principal
int main(int argc, char **argv){
    int i, j, cols=100, rows=100, n=5, maxTurns=50, mode=0, game;
    pokemons **matriz = grid_create(rows,cols);
    
    game=fParser(argc, argv, &rows, &cols, &n, &maxTurns, &mode);
    if (!game){
        initializeMatriz(matriz,rows ,cols);
        viewResults(matriz, rows, cols);
        play(matriz, rows, cols, maxTurns, n, mode);
        viewResults(matriz, rows, cols);
    }
    return 0;
}