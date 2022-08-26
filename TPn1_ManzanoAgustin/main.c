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
    initializeMatriz(matriz);
    
    //muestro la matriz
    //mostrarMatriz(matriz);
    viewResults(matriz);
    makePPM(matriz,"inicio.ppm");
    
    //ataques
    int i,j;
    for(j=0; j<100;j++)
    {
        for(i=0;i<10;i++){
            attacks(matriz);
        }
        //mostrarMatriz(matriz);
        //viewResults(matriz);
        //printf("\n");
    }
    
    viewResults(matriz);
    makePPM(matriz,"final.ppm");


    return 0;
}