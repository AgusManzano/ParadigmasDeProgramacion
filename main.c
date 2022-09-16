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
#include "funcionesTp1.c" 


// Bloque Principal
int main(int argc, char **argv){
    int i, j, cols=100, rows=100, n=5, maxTurns=50, mode=0, cPokemons=5, game;
    
    game=fParser(argc, argv, &rows, &cols, &n, &maxTurns, &mode, &cPokemons);
    
    pokemons **matriz = grid_create(rows,cols);
    
    if (!game){
        initializeMatriz(matriz,rows ,cols, cPokemons);
        viewResults(matriz, rows, cols, cPokemons);
        play(matriz, rows, cols, maxTurns, n, mode);
        viewResults(matriz, rows, cols, cPokemons);
    }
    return 0;
}