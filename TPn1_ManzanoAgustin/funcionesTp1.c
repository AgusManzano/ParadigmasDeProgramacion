#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "tp1.h"
#include <unistd.h>
//esctructura de mi pokemon

typedef struct{
    int control;
    char type[10];
    float hp;
    float attack;
}pokemons;

//prototypes
int RandInt(int lower, int upper,int count); 
void initializeMatriz(pokemons **matriz, int rows, int cols);
void viewMatriz(pokemons **matriz, int rows, int cols);
void makePPM(pokemons **matriz, int rows, int cols, int turn);
void attacks(pokemons **matriz, int rows, int cols);
void setPokemon(pokemons **matriz, int rows, int cols, char type);
float damageBooster(char type1, char type2);
void viewResults(pokemons **matriz, int rows, int cols);
void help(void);
pokemons **grid_create(int rows, int cols);
int validatePosicion(int rows, int cols, int i, int j);
void subAttack(pokemons **matriz, int actualRow, int actualCol, int attackRow, int attackCol);


//Desarrollo de funciones
int RandInt(int lower, int upper, int count)
{
    
    int num = (rand() % (upper - lower + 1)) + lower;   
    
    return num;
}

void setPokemon(pokemons **matriz,int i, int j, char type){
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

void initializeMatriz(pokemons **matriz, int rows, int cols){
    
    int i,j;
    int aux;

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
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

void viewMatriz(pokemons **matriz, int rows, int cols){
        
    int i,j;
    printf("\n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
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

void makePPM(pokemons **matriz, int rows, int cols, int turn){

        
    int i,j;
    char filename[20];
    sprintf(filename, "turn%d.ppm", turn);

    FILE* fichero;
    fichero = fopen(filename, "wt");
    
    fprintf(fichero, "P3\n%d %d\n255\n", cols, rows);
    

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
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
    printf(".File %s created successfully.\n", filename);
}

void attacks(pokemons **matriz, int rows, int cols){
    
    int i, j;

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            if(matriz[i][j].control && validatePosicion(rows, cols, i, j)){ //si es un pokemon activo
                subAttack(matriz, i, j, i, j+1);
                subAttack(matriz, i, j, i+1, j+1);   
                subAttack(matriz, i, j, i+1, j);
                subAttack(matriz, i, j, i+1, j-1);            
                subAttack(matriz, i, j, i, j-1);  
                subAttack(matriz, i, j, i-1, j-1);
                subAttack(matriz, i, j, i-1, j);
                subAttack(matriz, i, j, i-1, j+1);
            }else{
                setPokemon(matriz, i, j, matriz[i][j+1].type[0]);
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

void viewResults(pokemons **matriz, int rows, int cols){

    int i,j;
    int contFire=0, contWater=0, contGrass=0, contNormal=0, contPoison=0;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
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

pokemons **grid_create(int rows, int cols){

    pokemons **m = malloc(sizeof(pokemons *) * rows);

    if (NULL == m) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        m[i] = malloc(cols * sizeof(pokemons));
        if (NULL == m[i]) {
            while (i--) {
                free(m[i]);
            }
            free(m);
            return NULL;
        }
    }
    return m;
}

void help(void){
    printf("Entering...\n");
    printf("--width  (-w)   Number of columns in the matrix.\n");
    printf("--height  (-H)  Number of rows in the matrix.\n");
    printf("--seed  (-s)    Seed for the random number generator.\n");
    printf("-n              Number of iterations.(0 = only final)\n");
    printf("--help  (-h)    Show this help.\n");
    printf("--turns  (-t)   Number of turns.\n");
    printf("--mode (-m)    Mode of the game: \n\t\t\t\t1--Display by console (max 100x100)\n\t\t\t\t Different--Display PPM\n");
}

int validatePosicion(int rows, int cols, int i, int j){
    if(i<1 || i>=rows-1 || j<1 || j>=cols-1)
        return 0;
    else
        return 1;
}

void subAttack(pokemons **matriz, int actualRow, int actualCol, int attackRow, int attackCol){
    if(matriz[attackRow][attackCol].control){ //up right
        matriz[actualRow][actualCol].hp-=matriz[attackRow][attackCol].attack*damageBooster(matriz[actualRow][actualCol].type[0],matriz[attackRow][attackCol].type[0]);
        if(matriz[actualRow][actualCol].hp <= 0){
            matriz[actualRow][actualCol].control = 0;
            setPokemon(matriz, actualRow, actualCol, matriz[attackRow][attackCol].type[0]); 
        }             
    }
}

void play(pokemons **matriz, int rows, int cols, int maxTurns, int n, int mode){
    int j=0;
    if (n==0)
        makePPM(matriz, rows, cols, 0);
    for(j=0; j<maxTurns;j++)
    {
        if (n != 0){
            if(j % n == 0)
                if (mode==1){
                    viewMatriz(matriz, rows, cols);
                    sleep(1);
                }else{
                    makePPM(matriz,rows,cols, j);
                }
                
        }
        attacks(matriz,rows,cols);
        
    }
    makePPM(matriz,rows,cols, j);
}