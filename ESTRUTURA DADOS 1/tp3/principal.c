//caio silas de araujo amaro
//21.1.4111
//TP3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca.h"
#include <math.h>

int main(){

    /*lendo a quantidade de esculturas que serão feitas*/
    int qnt;
    scanf("%d",&qnt);
    
    /*alocando a quantidade de TEsculturas*/
    TEscultura *t = TEsculturaInicializa(qnt);

    for (int i = 0; i < qnt; i++)
    {
        /*lendo o numero de blocos o volume total do bloco e o valor do vertice*/
        scanf("%lf %lf %lf",&t[i].n,&t[i].volumeTotal,&t[i].x);

        /*fazendo a atribuição da altura do bloco*/
        t[i].altura = 3 * t[i].x;

        /*fazendo a busca binaria para saber o valor mais proximo para a altura do bloco*/
        t[i].altura = TEscultura_Binaria(&t[i],0,t[i].altura);

        // if (fabs(t[i].altura) <= 0.0000000001){
        //     printf("Impossivel definir a altura do corte\n");
        // }

        if (t[i].n == 0 || t[i].volumeTotal == 0 || t[i].x == 0){
            printf("Impossivel definir a altura do corte\n");
        }

        else if (fabs(t[i].altura - (3 * t[i].x)) < 0.0000000001){
            printf("Altura do corte igual ou maior que a camara de exposicao\n");
        }
        
        else {
            printf("%.3lf\n",t[i].altura);
        }
        
    }



    /*desalocando o vetor de TEscultura*/    
    desaloca(&t);

    return 0;
}