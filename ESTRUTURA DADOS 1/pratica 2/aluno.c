#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[20];
    char curso[20];
    float nota;
};

struct turma
{
    // vetor de ponteiro de alunos
    // inteiro com o tamanho da turma
    int tamanhoturma;
    TAluno **al;
};

// Manter como especificado
void lerInfos(int *qtd, char *option)
{   
    // (*option) = getc(stdin);
    scanf("%c",option);
    scanf("%d", qtd);
}

// Manter como especificado
void alocaAluno(TAluno **pAluno)
{
    (*pAluno) = malloc(sizeof(TAluno));
   
}

// Manter como especificado
void alocaTurma(TTurma **pTurma, int qtd)
{
    // Use a funcao alocaAluno aqui
    (*pTurma) = malloc(sizeof(TTurma));
    (*pTurma)->tamanhoturma = qtd;
    (*pTurma)->al = calloc(qtd , sizeof(TAluno));
    for (int i = 0; i < (*pTurma)->tamanhoturma; i++)
    {
        alocaAluno((*pTurma)->al+i);
        
    }
}

// Manter como especificado
void desalocaAluno(TAluno **pAluno)
{
    free(*pAluno);
}

// Manter como especificado
void desalocaTurma(TTurma **pTurma)
{
    for (int i = 0; i < (*pTurma)->tamanhoturma; i++)
    {
        desalocaAluno(&(*pTurma)->al[i]);
    }
    free((*pTurma)->al);
}

// Manter como especificado
void lerTurma(TTurma *pTurma)
{   
    
    for (int i = 0; i < pTurma->tamanhoturma; i++)
    {
        scanf("%s %s %f", pTurma->al[i]->nome, pTurma->al[i]->curso, &pTurma->al[i]->nota);
    }
    
    
}

// Manter como especificado
float calcularMetrica(TTurma *pTurma, char *curso, char option)
{
    float resultado = 0;
    float quant = 0;
    for (int i = 0; i < pTurma->tamanhoturma; i++)
    {
        if (strcmp(curso,pTurma->al[i]->curso) == 0){
            resultado += pTurma->al[i]->nota;
            quant++;
        }
    }

    if (option == 'M'){
        resultado = resultado / quant; 
    }
    return resultado;
}

// Manter como especificado
void printMetrica(char *curso, float metrica, char option)
{
    printf("A %s no curso de %s eh %.1f\n", option == 'S' ? "soma" : "media", curso, metrica);
}
