#include "fib.h"
#include<stdio.h>

int main()
{
    //adicionar variaveis conforme necessidade
    TADFib f;
    int casosTeste;
    f.resultado = 0;
    //fazer a leitura do numero de casos de teste dentro do main
    scanf ("%d",&casosTeste);
    //ler o caso de teste e processar antes de ler o proximo
    for (int t = 0; t < casosTeste; t++)
    {
        scanf("%lf",&f.i);
        f.chamadas = 0;
        f.resultado = fibonacci(f.i,&f);
        printf ("fib(%.0lf) = %.0lf chamadas = %.0lf\n",f.i,f.chamadas,f.resultado); 
    }
    //imprimir a resposta no formato adequado
    
    return 0;//nao remova
}