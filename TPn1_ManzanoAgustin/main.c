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
    int i, j, cols, rows, n, maxTurns, mode;

    for(i=0;i<argc;i++){
        if(strcmp(argv[i],"--help")==0 || strcmp(argv[i],"-h")==0){
            help();
            return 0;
        }else if(strcmp(argv[i],"--width")==0||strcmp(argv[i],"-w")==0){
            cols = atoi(argv[i+1]);
        }else if(strcmp(argv[i],"--height")==0 || strcmp(argv[i],"-H")==0){
            rows = atoi(argv[i+1]);
        }else if(strcmp(argv[i],"-n")==0){
            n = atoi(argv[i+1]);
        }else if(strcmp(argv[i],"--seed")==0 || strcmp(argv[i],"-s")==0){
            srand(atoi(argv[i+1]));
        }else if(strcmp(argv[i],"--turns")==0 || strcmp(argv[i],"-t")==0){
            maxTurns = atoi(argv[i+1]);
        }else if(strcmp(argv[i],"--mode")==0 || strcmp(argv[i],"-m")==0){
            mode = atoi(argv[i+1]);
        }
    }
    pokemons **matriz = grid_create(rows,cols);
    initializeMatriz(matriz,rows,cols);
    viewResults(matriz,rows,cols);
    play(matriz,rows, cols, maxTurns, n, mode);
    viewResults(matriz,rows,cols);

    return 0;
}