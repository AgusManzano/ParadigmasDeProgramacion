#include "tp1.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//esctructura de mi pokemon
typedef struct{
    int control;
    char type[10];
    int hp;
    char alive_face;
    char death_face;
}pokemons;


//prototypes
int RandInt(int lower, int upper,int count); 
void inicializarMatriz(pokemons (*matriz)[ALTO], char value);
void mostrarMatriz(pokemons (*matriz)[ALTO]);



//Desarrollo de funciones
int RandInt(int lower, int upper,int count)
{
    int num = (rand() % (upper - lower + 1)) + lower;   
    
    return num;
}

void inicializarMatriz(pokemons (*matriz)[ALTO], char value){
    
    int i,j;
    int aux;

    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){
            if (RandInt(0,1,1)){
                matriz[i][j].control=1;
            }
            matriz[i][j].alive_face='0';
            matriz[i][j].death_face=' ';
            matriz[i][j].hp=100;
            
            aux=RandInt(1,5,1);
            switch (aux)
            {
            case 1:
                strcpy(matriz[i][j].type, "water");
                break;
            case 2:
                strcpy(matriz[i][j].type, "fire");
                break;
            case 3:
                strcpy(matriz[i][j].type, "grass");
                break;
            case 4:
                strcpy(matriz[i][j].type, "normal");
                break;
            case 5:
                strcpy(matriz[i][j].type, "psychic");
                break;
            
            default:
                break;
            }
        }
    }
}

void mostrarMatriz(pokemons (*matriz)[ALTO]){
        
    int i,j;
    
    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){
            switch (matriz[i][j].type[0])
            {
            case 'w':
                if (matriz[i][j].control){
                    printf(AZUL_F"%2c"RESET_COLOR, matriz[i][j].alive_face);
                }
                else{
                    printf("%2c", matriz[i][j].death_face);
                }
                break;
            case 'f':
                if (matriz[i][j].control){
                    printf(ROJO_F"%2c"RESET_COLOR, matriz[i][j].alive_face);
                }
                else{
                    printf("%2c", matriz[i][j].death_face);
                }
                break;
            case 'g':
                if (matriz[i][j].control){
                    printf(VERDE_F"%2c"RESET_COLOR, matriz[i][j].alive_face);
                }
                else{
                    printf("%2c", matriz[i][j].death_face);
                }
                break;
            case 'n':
                if (matriz[i][j].control){
                    printf(BLANCO_F"%2c"RESET_COLOR, matriz[i][j].alive_face);
                }
                else{
                    printf("%2c", matriz[i][j].death_face);
                }
                break;
            case 'p':
                if (matriz[i][j].control){
                    printf(MAGENTA_F"%2c"RESET_COLOR, matriz[i][j].alive_face);
                }
                else{
                    printf("%2c", matriz[i][j].death_face);
                }
                break;
            
            default:
                break;             
            }
        }
        printf("\n");
    }
}