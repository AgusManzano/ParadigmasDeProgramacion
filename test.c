#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "funcionesTp1.c"


void testCreateGrid();
void testSetPokemon();
void testRellenarMapa();



void main(){
    testCreateGrid();
    
}


void testCreateGrid(){
    int rows = 800;
    int cols = 500;
    pokemons **matriz = grid_create(rows,cols);
    initializeMatriz(matriz,rows,cols);
    viewMatriz(matriz,rows,cols);
    viewResults(matriz,rows,cols);
}

void testSetPokemon(){
    int rows = 3;
    int cols = 4;
    pokemons **matriz = grid_create(rows,cols);
    initializeMatriz(matriz,rows,cols);
    setPokemon(matriz,rows,cols, 'f');
    viewMatriz(matriz,rows,cols);
    viewResults(matriz,rows,cols);
}

void testRellenarMapa(){
    int rows = 3;
    int cols = 4;
    pokemons **matriz = grid_create(rows,cols);
    initializeMatriz(matriz,rows,cols);
    rellenarMapa(matriz,rows,cols);
    viewMatriz(matriz,rows,cols);
    viewResults(matriz,rows,cols);
}
