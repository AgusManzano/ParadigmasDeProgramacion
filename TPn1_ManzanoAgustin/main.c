/*
Alumno: Agustin Manzano
Legajo: 34547
Universidad de San Andrés
Paradigmas de la Programación
*/
#include <stdio.h>
#include "tp1.h" 
#include "funcionesTp1.c"

// Bloque Principal
int main(void){

    pokemons matriz[ANCHO][ALTO];
    
    //inicializo la matriz en 0
    inicializarMatriz(matriz, 'x');

    //muestro la matriz
    mostrarMatriz(matriz);

    return 0;
}