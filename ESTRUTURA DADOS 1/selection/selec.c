#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define Tamanho 10

int main (){
    int caio[] = {15,2,3,14,2,6,97,8,9,10};

    int trocar = 0;
    int indice = 0;
    for (int i = 0; i < Tamanho ;i++){
        indice = i;
        for (int j = i + 1;j <Tamanho;j++){
            if (caio[j] < caio[indice]){
                indice = j;
            }
        }
        trocar = caio[indice];
        caio[indice] = caio[i];
        caio[i] = trocar;
    }

    for (int i = 0; i < Tamanho; i++){
        printf(" %d = %d\n",i+1,caio[i]);
    }
    
    return 0;
}