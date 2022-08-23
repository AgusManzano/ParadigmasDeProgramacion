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
    float attack;
}pokemons;


//prototypes
int RandInt(int lower, int upper,int count); 
void inicializarMatriz(pokemons (*matriz)[ALTO]);
void mostrarMatriz(pokemons (*matriz)[ALTO]);
void printPPM(pokemons (*matriz)[ALTO]);
void attacks(pokemons (*matriz)[ALTO], pokemons (*matrizAux)[ALTO]);



//Desarrollo de funciones
int RandInt(int lower, int upper,int count)
{
    int num = (rand() % (upper - lower + 1)) + lower;   
    
    return num;
}

void inicializarMatriz(pokemons (*matriz)[ALTO]){
    
    int i,j;
    int aux;

    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){
            if (RandInt(0,1,1)){
                matriz[i][j].control=1;
            }
            else{
                matriz[i][j].control=0;
            }
            
            aux=RandInt(1,5,1);
            switch (aux)
            {
            case 1:
                strcpy(matriz[i][j].type, "water");
                matriz[i][j].attack=1.0;
                matriz[i][j].hp=100;
                break;
            case 2:
                strcpy(matriz[i][j].type, "fire");
                matriz[i][j].attack=1.5;
                matriz[i][j].hp=80;
                break;
            case 3:
                strcpy(matriz[i][j].type, "grass");
                matriz[i][j].attack=1;
                matriz[i][j].hp=120;
                break;
            case 4:
                strcpy(matriz[i][j].type, "normal");
                matriz[i][j].attack=1;
                matriz[i][j].hp=100;
                break;
            case 5:
                strcpy(matriz[i][j].type, "psychic");
                matriz[i][j].attack=1.5;
                matriz[i][j].hp=80;
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
                    printf(AZUL_F"%2c"RESET_COLOR, ' ');
                }
                else{
                    printf("%2c", ' ');
                }
                break;
            case 'f':
                if (matriz[i][j].control){
                    printf(ROJO_F"%2c"RESET_COLOR, ' ');
                }
                else{
                    printf("%2c", ' ');
                }
                break;
            case 'g':
                if (matriz[i][j].control){
                    printf(VERDE_F"%2c"RESET_COLOR, ' ');
                }
                else{
                    printf("%2c", ' ');
                }
                break;
            case 'n':
                if (matriz[i][j].control){
                    printf(BLANCO_F"%2c"RESET_COLOR, ' ');
                }
                else{
                    printf("%2c", ' ');
                }
                break;
            case 'p':
                if (matriz[i][j].control){
                    printf(MAGENTA_F"%2c"RESET_COLOR, ' ');
                }
                else{
                    printf("%2c", ' ');
                }
                break;
            
            default:
                printf("%2c", ' ');
                break;             
            }
        }
        printf("\n");
    }
}

void printPPM(pokemons (*matriz)[ALTO]){

        
    int i,j;
    
    printf("P3\n%d %d\n255\n", ANCHO, ALTO);


    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){
            switch (matriz[i][j].type[0])
            {
            case 'w':
                if (matriz[i][j].control){
                    printf("0 255 255 "); //aqua
                }
                else{
                    printf("0 0 0 ");
                }
                break;
            case 'f':
                if (matriz[i][j].control){
                    printf("255 0 0 "); //red
                }
                else{
                    printf("0 0 0 ");
                }
                break;
            case 'g':
                if (matriz[i][j].control){
                    printf("0 128 0 "); //green
                }else{
                    printf("0 0 0 ");
                }
                break;
            case 'n':
                if (matriz[i][j].control){
                    printf("255 255 255 ");
                }
                else{
                    printf("0 0 0 ");
                }
                break;
            case 'p':
                if (matriz[i][j].control){
                    printf("255 0 255 ");
                }
                else{
                    printf("0 0 0 ");
                }
                break;
            
            default:
                break;             
            }
        }
        printf("\n");
    }
}

void attacks(pokemons (*matriz)[ALTO], pokemons (*matrizAux)[ALTO]){
    
    int i, j;

    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){
            matrizAux[i][j]=matriz[i][j];

            if(matriz[i][j].control){ //si es un pokemon activo
                if(matriz[i][j].type[0] == 'w'){ 
                
                }
                if(matriz[i][j].type[0] == 'f'){ 
                
                }
                if(matriz[i][j].type[0] == 'g'){ 
                
                }
                if(matriz[i][j].type[0] == 'n'){ 
                
                }
                if(matriz[i][j].type[0] == 'p'){ 
                
                }


            }
            else{ //si es un pokemon inactivo
                matrizAux[i][j].control=1;
                matrizAux[i][j].hp=matriz[i][j].hp;
                if(j<ANCHO-1)
                    strcpy(matrizAux[i][j].type, matriz[i][j+1].type);

            }
            }
    }
}