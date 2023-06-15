#include "ordenacao.h"
#include <stdio.h>

int main ()
{
    int i;
    int n, k;
    TipoAluno *alunos = NULL;

    //ler as quantidades
    scanf("%d %d",&n,&k);
    //alocar o vetor
    alunos = alocaAlunos(alunos,n);
    //preencher o vetor
    for (i = 0; i < n; i++)
    {
        scanf("%s",alunos[i].nome);
    }
    //ordenar
    heapsort(alunos,n);
    //imprimir o resultado
    printf("%s\n",alunos[k - 1].nome);
    //desalocar o vetor
    desalocaAlunos(&alunos);
    
    
    
    return 0;
}
