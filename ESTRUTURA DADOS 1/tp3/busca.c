//caio silas de araujo amaro
//21.1.4111
//TP3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca.h"
#include <math.h>

/* aloca um vetor de TEscultura*/
TEscultura *TEsculturaInicializa(int qnt){
    return calloc(qnt,sizeof(TEscultura)); 
}

/* encontra o í ndice da chave x no dicionário entre esq e dir */
double TEscultura_Binaria ( TEscultura *t , double esq ,double dir) {
    double meio = ( esq + dir ) /2;
    double volume = (t->x * (t->x * 2)) * meio * t->n;
    
    // printf ("esq = %lf dir = %lf meio = %lf\n",esq,dir,meio);

    if (fabs(esq - dir) < 0.0000000001){
        return meio;      
    }

    else if(fabs(volume - t->volumeTotal) < 0.0000000001){
        return -1;
    }
    
    else if (volume > t->volumeTotal){
        return TEscultura_Binaria(t,esq,meio);
    }
    else {
        return TEscultura_Binaria(t,meio,dir);
    }
    
}

/* aloca um vetor de TEscultura*/
void desaloca(TEscultura **t){
    free(*t);
}
