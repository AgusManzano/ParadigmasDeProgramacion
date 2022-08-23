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
    pokemons matrizAux[ANCHO][ALTO];
    
    //inicializo la matriz en 0
    inicializarMatriz(matriz);
    //muestro la matriz
    mostrarMatriz(matriz);

    
    //ataques
    attacks(matriz, matrizAux);

    mostrarMatriz(matrizAux);    
    
    //imprimo el ppm
    //printPPM(matriz);

    return 0;
}