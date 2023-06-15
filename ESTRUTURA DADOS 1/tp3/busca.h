//caio silas de araujo amaro
//21.1.4111
//TP3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# ifndef busca_h
# define busca_h

typedef double Tchave;

typedef struct
{
    double x;
    double volumeTotal;
    Tchave altura;
    double n;
}TEscultura;

/*aloca um vetor de TEscultura*/
TEscultura *TEsculturaInicializa(int qnt);

/* encontra o í ndice da chave x no dicionário entre esq e dir */
double TEscultura_Binaria ( TEscultura *t , double esq ,double dir);

/* desaloca o vetor de TEscultura*/
void desaloca(TEscultura **t);

#endif