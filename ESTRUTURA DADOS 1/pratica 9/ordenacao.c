#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *aluno, int n) {
   //preencher
  return aluno = calloc(n,sizeof(TipoAluno));
}

//Manter como especificado
void desalocaAlunos(TipoAluno **alunos) {
  //preencher
  free(*alunos);
}

void heapsort(TipoAluno *alunos, int n) {
  heapcontroi(alunos,n);
    TipoAluno aux;
    while (n > 1)
    {
        strcpy(aux.nome ,alunos[n - 1].nome);
        strcpy(alunos[n - 1].nome,alunos[0].nome);
        strcpy(alunos[0].nome,aux.nome);
        n = n - 1;
        heapRefaz(alunos,0,n-1);
    }
}

void heapRefaz(TipoAluno *v,int esq,int dir){
    int i = esq;
    int j = i * 2 + 1;
    TipoAluno aux;
    strcpy(aux.nome,v[i].nome);

    while (j <= dir){
        if (j < dir && strcmp(v[j].nome,v[j+1].nome) < 0){
            j = j + 1;
        }
        if (strcmp(aux.nome,v[j].nome) >= 0){
            break;
        }
        strcpy(v[i].nome,v[j].nome);
        i = j;
        j = i * 2 + 1;
    }
    strcpy(v[i].nome, aux.nome);
}

void heapcontroi(TipoAluno *v,int n){
    int esq = (n/2) - 1;
    while (esq >= 0)
    {
        heapRefaz(v,esq,n - 1);
        esq--;
    }
    
}