#include "duende.h"
#include<stdio.h>

int main()
{
    int qtd;
    TADduende *D;
    TADtime *T;

    lerQuantidade(&qtd);
    D = alocaDuendes(qtd);
    T = alocaTimes(qtd/3);
    lerDuendes(D, qtd);
    escalarTimes(D, T, qtd);
    printTimes(T, qtd/3);
    desalocaDuendes(&D);
    desalocaTimes(&T);
    /*complexidade
    proximomaisvelho -> n
    escalartime -> n^2
    */

    return 0;//nao remova
}
