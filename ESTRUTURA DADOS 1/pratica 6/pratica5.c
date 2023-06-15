#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int n, k;
  TipoAluno *alunos = NULL;

	//ler as quantidades
	scanf("%d",&n);
	scanf("%d",&k);
	//alocar o vetor
	alunos = alocaAlunos(alunos,n);
	//preencher o vetor
	preeche(alunos,n);
	//ordenar
	ordena(alunos,n);
	//imprimir o resultado
	printf("%s\n",alunos[k - 1].nome);
	//desalocar o vetor
	desalocaAlunos(alunos);
  return 0;
}
