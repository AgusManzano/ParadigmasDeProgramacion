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


//prototypes
int RandInt(int lower, int upper,int count); 
void inicializarMatriz(pokemons (*matriz)[ALTO]);
void mostrarMatriz(pokemons (*matriz)[ALTO]);
void printPPM(pokemons (*matriz)[ALTO]);
void attacks(pokemons (*matriz)[ALTO]);
void setPokemon(pokemons (*matriz)[ALTO],int i, int j, char type);
void damageBooster(char type1, char type2);


//Desarrollo de funciones
int RandInt(int lower, int upper, int count)
{
    int num = (rand() % (upper - lower + 1)) + lower;   
    
    return num;
}

void setPokemon(pokemons (*matriz)[ALTO],int i, int j, char type){
    if(type == 'f'){
        matriz[i][j].hp=FIRE_HP;
        matriz[i][j].attack=FIRE_ATTACK;
        strcpy(matriz[i][j].type, "fire");
    }
    else if(type == 'w'){
        matriz[i][j].hp=WATER_HP;
        matriz[i][j].attack=WATER_ATTACK;
        strcpy(matriz[i][j].type, "water");
    }
    else if(type == 'p'){
        matriz[i][j].hp=PSY_HP;
        matriz[i][j].attack=PSY_ATTACK;
        strcpy(matriz[i][j].type, "psychic");
    }
    else if(type == 'n'){
        matriz[i][j].hp=NORMAL_HP;
        matriz[i][j].attack=NORMAL_HP;
        strcpy(matriz[i][j].type, "normal");
    }
    else if(type == 'g'){
        matriz[i][j].hp=GRASS_HP;
        matriz[i][j].attack=GRASS_ATTACK;
        strcpy(matriz[i][j].type, "glass");
    }
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
                    printf("255 0 255 "); //magenta
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

void attacks(pokemons (*matriz)[ALTO]){
    
    int i, j;

    for(i=0; i<ALTO; i++){
        for(j=0; j<ANCHO; j++){

            if(matriz[i][j].control){ //si es un pokemon activo


                if(matriz[i][j].type[0] == 'w'){ 
                    
                    if(matriz[i][j+1].control && j+1<ANCHO){
                        

                        
                        switch (matriz[i][j+1].type[0])
                        {
                        case 'f':
                            matriz[i][j].hp-=matriz[i][j+1].attack*damageBooster(matriz[i][j].type[0],);
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                            setPokemon(matriz, i, j, 'f'); 
                            break;
                        case 'g':
                            matriz[i][j].hp-=matriz[i][j+1].attack*2;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'g'); 
                            break;
                        case 'n':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'n'); 
                            break;
                        case 'p':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'p'); 
                            break;
                        case 'w':
                            matriz[i][j].hp-=matriz[i][j+1].attack*0.5;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'w'); 
                            break;
                        default:
                            break;             
                        }
                    }
                }
                if(matriz[i][j].type[0] == 'n'){ 
                    if(matriz[i][j+1].control && j+1<ANCHO){
                        switch (matriz[i][j+1].type[0])
                        {
                        case 'f':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'f'); 
                            break;
                        case 'g':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'g'); 
                            break;
                        case 'n':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'f'); 
                            break;
                        case 'p':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'p'); 
                            break;
                        case 'w':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'w'); 
                            break;
                        default:
                            break;             
                        }
                    }
                }
                if(matriz[i][j].type[0] == 'f'){ 
                    if(matriz[i][j+1].control && j+1<ANCHO){
                        switch (matriz[i][j+1].type[0])
                        {
                        case 'f':
                            matriz[i][j].hp-=matriz[i][j+1].attack*0.5;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'f'); 
                            break;
                        case 'g':
                            matriz[i][j].hp-=matriz[i][j+1].attack*0.5;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'g'); 
                            break;
                        case 'n':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'n'); 
                            break;
                        case 'p':
                            matriz[i][j].hp-=matriz[i][j+1].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'p'); 
                            break;
                        case 'w':
                            matriz[i][j].hp-=matriz[i][j+1].attack*2.0;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'w'); 
                            break;
                        default:
                            break;             
                        }
                    }
                }
                if(matriz[i][j].type[0] == 'g'){ 
                    if(matriz[i][j+1].control && j+1<ANCHO){
                        switch (matriz[i][j+1].type[0])
                        {
                        case 'f':
                            matriz[i][j].hp-=matriz[i][j].attack*2.0;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'f'); 
                            break;
                        case 'g':
                            matriz[i][j].hp-=matriz[i][j].attack*0.5;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'g'); 
                            break;
                        case 'n':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'n'); 
                            break;
                        case 'p':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'p'); 
                            break;
                        case 'w':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'w'); 
                            break;
                        default:
                            break;             
                        }
                    }
                }
                if(matriz[i][j].type[0] == 'p'){ 
                    if(matriz[i][j+1].control && j+1<ANCHO){
                        switch (matriz[i][j+1].type[0])
                        {
                        case 'f':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'f'); 
                            break;
                        case 'g':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'g'); 
                            break;
                        case 'n':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'n'); 
                            break;
                        case 'p':
                            matriz[i][j].hp-=matriz[i][j].attack*0.5;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'p'); 
                            break;
                        case 'w':
                            matriz[i][j].hp-=matriz[i][j].attack;
                            if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
                                setPokemon(matriz, i, j, 'w'); 
                            break;
                        default:
                            break;             
                        }
                    }
                }
            }else{ //si es un pokemon inactivo
                matriz[i][j].control=1;
                if(j < ANCHO-1){
                    switch (matriz[i][j+1].type[0])
                            {
                            case 'f':
                                matriz[i][j].hp=FIRE_HP;
                                matriz[i][j].attack=FIRE_ATTACK;
                                break;
                            case 'g':
                                matriz[i][j].hp=GRASS_HP;
                                matriz[i][j].attack=GRASS_ATTACK;
                                break;
                            case 'n':
                                matriz[i][j].hp=NORMAL_HP;
                                matriz[i][j].attack=NORMAL_ATTACK;
                                break;
                            case 'p':
                                matriz[i][j].hp=PSY_HP;
                                matriz[i][j].attack=PSY_ATTACK;
                                break;
                            case 'W':
                                matriz[i][j].hp=WATER_HP;
                                matriz[i][j].attack=WATER_ATTACK;
                                break;
                            default:
                            break;             
                        }
                }
                    
                }
            }
    }
}

void damage(pokemons (*matriz)[ALTO], int i, int j, int iprim, int jprim){
    
    switch (matriz[iprim][jprim].type[0])
    {
    case 'f':
        if(matriz[i][j].type[0] == 'w')
            matriz[i][j].hp-=matriz[iprim][jprim].attack*0.5;
        
        if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
            setPokemon(matriz, i, j, 'f'); 
        break;
    case 'g':
        matriz[i][j].hp-=matriz[iprim][jprim].attack*2;
        if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
            setPokemon(matriz, i, j, 'g'); 
        break;
    case 'n':
        matriz[i][j].hp-=matriz[iprim][jprim].attack;
        if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
            setPokemon(matriz, i, j, 'n'); 
        break;
    case 'p':
        matriz[i][j].hp-=matriz[iprim][jprim].attack;
        if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
            setPokemon(matriz, i, j, 'p'); 
        break;
    case 'w':
        matriz[i][j].hp-=matriz[iprim][jprim].attack*0.5;
        if(matriz[i][j].hp <= 0) //caso en el que el pokemon muera al recibir el ataque
            setPokemon(matriz, i, j, 'w'); 
        break;
    default:
        break;             
    }
}

void damageBooster(char type1, char type2){
    if(type1 == 'n' && (type2=='f' || type2=='w' || type2=='n' || type2=='g' || type2=='p'))
        return 1.0;
    else if(type1 == 'w' && (type2 == 'n' || type2 == 'p'))
            return 1.0;
    else if(type1 == 'w' && (type2 == 'f' || type2 == 'w'))
            return 0.5:
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