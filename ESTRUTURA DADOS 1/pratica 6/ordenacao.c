#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
  return alunos = malloc(n * sizeof(TipoAluno));;
}
//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
  return alunos;
}
//preenche o vetor
void preeche(TipoAluno *aluno,int n){
  int i;
  for(i = 0;i < n;i++){
		scanf("%s",aluno[i].nome);
	}
}
//compara para saber qual vem primeiro
int compara(TipoAluno x, TipoAluno y){
    //casos tudo seja igual a preferencia e por ordem alfabetica 
    if (strcmp(x.nome,y.nome) < 0){
        return 1;
    }
    return 2;
}
//ordena o vetor
void ordena(TipoAluno *alunos, int n){
	  TipoAluno aux;
    int maior = 0;
    for (int i = 0;i < n;i++){
        int flag = 0;
        for (int k = 0; k < n - 1 - i; k++)
        {
            maior = compara(alunos[k],alunos[k + 1]);
            // se maior for igual a 2 quer dizer que y e maior que x e deve ser feita uma troca
            if (maior == 2){
                aux = alunos[k];
                alunos[k] = alunos[k + 1];
                alunos[k + 1] = aux;
                flag += 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
}
