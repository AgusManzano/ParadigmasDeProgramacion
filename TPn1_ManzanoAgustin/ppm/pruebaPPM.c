#include <stdio.h>

int main(void){
    int ancho, alto;
    int i,j;

    scanf("%d %d", &ancho, &alto);
    printf("P1\n%d %d\n255\n", ancho, alto);

    for (i=0; i<ancho; i++){
        for (j=0; j<alto; j++){
            printf("127 0 255");
        }
        printf("\n");
    }
    return 0;
}
// comandos: crear el ejecutable con la sitaxis y correrlo de la siguiente forma:
//           ./imagen > imagen.ppm; eog imagen.ppm