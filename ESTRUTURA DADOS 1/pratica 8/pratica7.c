#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
	TLista lista;

	// ler as quantidades
	scanf("%d %d",&n,&k);
	lista.tamanho = 0;
	// criar a lista encadeada
	TListaCria(&lista);
	// preencher a lista encadeada
	TAluno aluno;
	for (i = 0; i < n;i++){
		scanf("%s",aluno.nome);
		TListaInsereInicio(&lista,aluno);	
	}
	// ordenar a lista
	ordena(&lista,n);
	// imprimir o resultado
	TCelula *aux;
	aux = apontadorPosicao(&lista,k - 1);
	printf("%s\n",aux->item.nome);
	// desalocar o vetor
	TListaDestroi(&lista);

  	return 0;
}
