#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "funcionesTp1.c"

void testSetPokemon();
void testSetPokemon2();
void testRellenarMapa();
void testAttack();
void testDamageBooster();

void main(){
    //testSetPokemon(); OK
    //testRellenarMapa(); OK 
    //testAttack(); OK
    //testDamageBooster(); OK
    //testSetPokemon2(); OK
}

void testSetPokemon(){
    pokemons matriz[ALTO][ANCHO];
    initializeMatriz(matriz);
    viewMatriz(matriz);
    for(int i=0; i<ALTO; i++){
        for(int j=0; j<ANCHO; j++){
            if(i<10)
                setPokemon(matriz,i,j,'f');
            else if(i<20)
                setPokemon(matriz,i,j,'w');
            else if(i<30)
                setPokemon(matriz,i,j,'g');
            else if(i<40)
                setPokemon(matriz,i,j,'p');
        }
    }
    viewMatriz(matriz);
}

void testRellenarMapa(){
    pokemons matriz[ALTO][ANCHO];
    initializeMatriz(matriz);
    viewMatriz(matriz);
    for(int i=0; i<ALTO; i++){
        for(int j=0; j<ANCHO; j++){
          if(matriz[i][j].control==0)
            setPokemon(matriz,i,j,matriz[i][j+1].type[0]);
        }
    }
    viewMatriz(matriz);
}

void testAttack(){
    pokemons matriz[ALTO][ANCHO];
    initializeMatriz(matriz);
    viewMatriz(matriz);
    for(int i=0; i<ALTO; i++){
        for(int j=0; j<ANCHO; j++){
          if(matriz[i][j].control==0)
            setPokemon(matriz,i,j,matriz[i][j+1].type[0]);
        }
    }
    viewMatriz(matriz);
    for(int i=0; i<10;i++){
        attacks(matriz);
    }

    viewMatriz(matriz);
}

void testDamageBooster(){
    pokemons matriz[ALTO][ANCHO];
    initializeMatriz(matriz);
    
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][1].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[1][0].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[1][1].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][2].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][3].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][4].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][5].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][6].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][7].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][8].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][9].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][10].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][11].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][12].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][13].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][14].type[0]));
    printf(" %f ", damageBooster(matriz[0][0].type[0],matriz[0][15].type[0]));

}

void testSetPokemon2(){
    pokemons matriz[ALTO][ANCHO];
    initializeMatriz(matriz);
    viewMatriz(matriz);
    viewResults(matriz);
    for(int i=0; i<ALTO; i++){
        for(int j=0; j<ANCHO; j++){
            setPokemon(matriz,i,j,matriz[RandInt(0,ALTO,1)][RandInt(0,ANCHO,1)].type[0]);
        }
    }
    viewMatriz(matriz);
    viewResults(matriz);
    attacks(matriz);
    viewMatriz(matriz);
    viewResults(matriz);
    
}