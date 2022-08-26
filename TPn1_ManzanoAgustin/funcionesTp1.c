#include "tp1.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//esctructura de mi pokemon
typedef struct{
    int control;
    char type[10];
    float hp;
    float attack;
}pokemons;

//srand(time(NULL));

//prototypes
int RandInt(int lower, int upper,int count); 
void initializeMatriz(pokemons (*matriz)[ALTO]);
void viewMatriz(pokemons (*matriz)[ALTO]);
void makePPM(pokemons (*matriz)[ALTO],char *filename);
void attacks(pokemons (*matriz)[ALTO]);
void setPokemon(pokemons (*matriz)[ALTO],int i, int j, char type);
float damageBooster(char type1, char type2);
void viewResults(pokemons (*matriz)[ALTO]);


//Desarrollo de funciones
int RandInt(int lower, int upper, int count)
{
    int num = (rand() % (upper - lower + 1)) + lower;   
    
    return num;
}

void setPokemon(pokemons (*matriz)[ALTO],int i, int j, char type){
    matriz[i][j].control=1;
    if(type == 'f'){
        matriz[i][j].hp=FIRE_HP;
        matriz[i][j].attack=FIRE_ATTACK;
        strcpy(matriz[i][j].type, "fire");
    }
    if(type == 'w'){
        matriz[i][j].hp=WATER_HP;
        matriz[i][j].attack=WATER_ATTACK;
        strcpy(matriz[i][j].type, "water");
    }
    if(type == 'p'){
        matriz[i][j].hp=PSY_HP;
        matriz[i][j].attack=PSY_ATTACK;
        strcpy(matriz[i][j].type, "psychic");
    }
    if(type == 'n'){
        matriz[i][j].hp=NORMAL_HP;
        matriz[i][j].attack=NORMAL_ATTACK;
        strcpy(matriz[i][j].type, "normal");
    }
    if(type == 'g'){
        matriz[i][j].hp=GRASS_HP;
        matriz[i][j].attack=GRASS_ATTACK;
        strcpy(matriz[i][j].type, "glass");
    }
}

void initializeMatriz(pokemons (*matriz)[ALTO]){
    
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
                matriz[i][j].attack=WATER_ATTACK;
                matriz[i][j].hp=WATER_HP;
                break;
            case 2:
                strcpy(matriz[i][j].type, "fire");
                matriz[i][j].attack=FIRE_ATTACK;
                matriz[i][j].hp=FIRE_HP;
                break;
            case 3:
                strcpy(matriz[i][j].type, "grass");
                matriz[i][j].attack=GRASS_ATTACK;
                matriz[i][j].hp=GRASS_HP;
                break;
            case 4:
                strcpy(matriz[i][j].type, "normal");
                matriz[i][j].attack=NORMAL_ATTACK;
                matriz[i][j].hp=NORMAL_HP;
                break;
            case 5:
                strcpy(matriz[i][j].type, "psychic");
                matriz[i][j].attack=PSY_ATTACK;
                matriz[i][j].hp=PSY_HP;
                break;
            
            default:
                break;
            }
        }
    }
}

void viewMatriz(pokemons (*matriz)[ALTO]){
        
    int i,j;
    printf("\n");
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

void makePPM(pokemons (*matriz)[ALTO], char *filename){

        
    int i,j;
    
    FILE* fichero;
    fichero = fopen(filename, "wt");
    
    fprintf(fichero, "P3\n%d %d\n255\n", ANCHO, ALTO);
    

    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){
            switch (matriz[i][j].type[0])
            {
            case 'w':
                if (matriz[i][j].control){
                    fprintf(fichero,"0 255 255 "); //aqua
                }
                else{
                    fprintf(fichero,"0 0 0 ");
                }
                break;
            case 'f':
                if (matriz[i][j].control){
                    fprintf(fichero,"255 0 0 "); //red
                }
                else{
                    fprintf(fichero,"0 0 0 ");
                }
                break;
            case 'g':
                if (matriz[i][j].control){
                    fprintf(fichero, "0 128 0 "); //green
                }else{
                    fprintf(fichero,"0 0 0 ");
                }
                break;
            case 'n':
                if (matriz[i][j].control){
                    fprintf(fichero, "255 255 255 ");
                }
                else{
                    fprintf(fichero,"0 0 0 ");
                }
                break;
            case 'p':
                if (matriz[i][j].control){
                    fprintf(fichero,"255 0 255 "); //magenta
                }
                else{
                    fprintf(fichero,"0 0 0 ");
                }
                break;
            
            default:
                break;             
            }
        }
        fprintf(fichero, "\n");
    }
    fclose(fichero);
    printf("Archivo %s creado con exito\n", filename);
}

void attacks(pokemons (*matriz)[ALTO]){
    
    int i, j;

    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){

            if(matriz[i][j].control){ //si es un pokemon activo
                if(matriz[i][j+1].control && (j<ANCHO && i<ALTO)){ //right
                    matriz[i][j].hp-=matriz[i][j+1].attack*damageBooster(matriz[i][j].type[0],matriz[i][j+1].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i][j+1].type[0]); 
                    }
                        
                }
                if(matriz[i+1][j+1].control && (j<ANCHO && i<ALTO)){ //right down
                    matriz[i][j].hp-=matriz[i+1][j+1].attack*damageBooster(matriz[i][j].type[0],matriz[i+1][j+1].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i+1][j+1].type[0]); 
                    }
                        
                }
                if(matriz[i+1][j].control && (j<ANCHO && i<ALTO)){ //down
                    matriz[i][j].hp-=matriz[i+1][j].attack*damageBooster(matriz[i][j].type[0],matriz[i+1][j].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i+1][j].type[0]); 
                    }
                        
                }
                if(matriz[i+1][j-1].control && (j<ANCHO && i<ALTO)){ //down left
                    matriz[i][j].hp-=matriz[i+1][j-1].attack*damageBooster(matriz[i][j].type[0],matriz[i+1][j-1].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i+1][j-1].type[0]); 
                    }
                        
                }
                if(matriz[i][j-1].control && (j<ANCHO && i<ALTO)){ //left
                    matriz[i][j].hp-=matriz[i][j-1].attack*damageBooster(matriz[i][j].type[0],matriz[i][j-1].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i][j-1].type[0]); 
                    }
                        
                }
                if(matriz[i-1][j-1].control && (j<ANCHO && i<ALTO)){ //up left
                    matriz[i][j].hp-=matriz[i-1][j-1].attack*damageBooster(matriz[i][j].type[0],matriz[i-1][j-1].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i-1][j-1].type[0]); 
                    }
                        
                }
                if(matriz[i-1][j].control && (j<ANCHO && i<ALTO)){ //up
                    matriz[i][j].hp-=matriz[i-1][j].attack*damageBooster(matriz[i][j].type[0],matriz[i-1][j].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i-1][j].type[0]); 
                    }
                        
                }
                if(matriz[i-1][j+1].control && (j<ANCHO && i<ALTO)){ //up right
                    matriz[i][j].hp-=matriz[i-1][j+1].attack*damageBooster(matriz[i][j].type[0],matriz[i-1][j+1].type[0]);
                    if(matriz[i][j].hp <= 0){
                        matriz[i][j].control = 0;
                        setPokemon(matriz, i, j, matriz[i-1][j+1].type[0]); 
                    }
                        
                }
            }else{
                setPokemon(matriz, i, j, matriz[i][j].type[0]);
            }
        }
    }
}

float damageBooster(char type1, char type2){
    if(type1 == 'n' && (type2=='f' || type2=='w' || type2=='n' || type2=='g' || type2=='p'))
        return 1.0;
    else if(type1 == 'w' && (type2 == 'n' || type2 == 'p'))
            return 1.0;
    else if(type1 == 'w' && (type2 == 'f' || type2 == 'w'))
            return 0.5;
    else if(type1 == 'w' && type2 == 'g')
            return 2.0;
    else if(type1 == 'f' && (type2 == 'n' || type2 == 'p'))
            return 1.0;
    else if(type1 == 'f' && (type2 == 'w' || type2 == 'g'))
            return 2.0;
    else if(type1 == 'f' && type2 == 'f')
            return 0.5;
    else if(type1 == 'g' && (type2 == 'g' || type2 == 'w'))
            return 0.5;
    else if(type1 == 'g' && (type2 == 'p' || type2 == 'n'))
            return 1.0;
    else if(type1 == 'g' && type2 == 'f')
            return 2.0;
    else if(type1 == 'p' && (type2 == 'g' || type2 == 'w' || type2 == 'n' || type2 == 'f'))
            return 1.0;
    else if(type1 == 'p' && type2 == 'p')
            return 0.5;
}

void viewResults(pokemons (*matriz)[ALTO]){
    int i,j;
    int contFire=0, contWater=0, contGrass=0, contNormal=0, contPoison=0;
    for(i=0;i<ALTO;i++){
        for(j=0;j<ANCHO;j++){
            if(matriz[i][j].control){
                if(matriz[i][j].type[0] == 'f')
                    contFire++;
                else if(matriz[i][j].type[0] == 'w')
                    contWater++;
                else if(matriz[i][j].type[0] == 'g')
                    contGrass++;
                else if(matriz[i][j].type[0] == 'n')
                    contNormal++;
                else if(matriz[i][j].type[0] == 'p')
                    contPoison++;
            }
        }
    }
    printf("\nStatus:");
    printf("| Fire: %d | Water: %d | Grass: %d | Normal: %d | Psychic: %d |\n",contFire,contWater,contGrass,contNormal,contPoison);
}