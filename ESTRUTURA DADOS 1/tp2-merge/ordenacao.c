//Caio silas - Matricula : 21.1.4111
//Turmas 21-22


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

//struct que contem a quantidade de casos e os medicos de plantao
struct caso
{
    int grave;
    int medio;
    int normal;
    int plantao;
};
//struct que contem uma struc de caso e o nome das upas
struct upa
{
    Tcaso caso;
    char nome[20];
};
//alocando a struct
void alocaUpa(Tupa **upa,int qnt){
    //alocando a struc Tupa
    *upa = (Tupa*)malloc(qnt * sizeof(Tupa));
    if(*upa == NULL){
        exit(EXIT_FAILURE);
    }
}
//preenchendo as struct com o arquivo
void Completaupa(Tupa **upa,int qnt){
    //fazendo a struct aux apontar para o mesmo lugar que upa
    Tupa *aux = *upa;
    //lendo as informaçoes sobre as upas
    for (int i = 0; i < qnt;i++){
        scanf("%s",aux[i].nome);
        scanf("%d %d %d %d",&aux[i].caso.grave,&aux[i].caso.medio,&aux[i].caso.normal,&aux[i].caso.plantao);
    }
}
//compara qual tem preferencia ,essa funcao retorna 1 se x tiver preferencia e 2 caso contrario
int compara(Tupa x, Tupa y){
    //casos graves sejam maiores
    if (x.caso.grave != y.caso.grave){
        if (x.caso.grave > y.caso.grave){
            return 1;
        }
    }
    //casos  graves sejam iguais deve se comparar os casos medios
    else if(x.caso.medio != y.caso.medio){
        if (x.caso.medio > y.caso.medio){
            return 1;
        }
    }
    //casos grave e medios sejam iguais, deve-se comparar os normais
    else if (x.caso.normal != y.caso.normal){
        if (x.caso.normal > y.caso.normal){
            return 1;
        }
    }
    //casos todos sejam iguais, a preferencia e da upa que tem menos medicos de plantao
    else if (x.caso.plantao != y.caso.plantao){
        if (x.caso.plantao < y.caso.plantao){
            return 1;
        }
    }
    //casos tudo seja igual a preferencia e por ordem alfabetica 
    else if (strcmp(x.nome,y.nome) < 0){
        return 1;
    }
    return 2;
}
//ordenando o vetor
void merge(Tupa **v,int l,int m, int r){
    int tamE = m - l + 1;
    int i,j;
    int tamD = r - m;
    Tupa *vetorE = malloc((tamE)*sizeof(Tupa));
    Tupa *vetorD= malloc((tamD)*sizeof(Tupa));
    for (i = 0; i < tamE; i++){
        vetorE[i] = (*v)[i + l]; 
    }
    for (j = 0; j < tamD; j++)
    {
        vetorD[j] = (*v)[m + j + 1];
    }
    i = 0;
    j = 0;
    int k;
    for (k = l; k <= r; k++)
    {
        if (i == tamE){
            (*v)[k] = vetorD[j++];
        }
        else if (j == tamD){
            (*v)[k] = vetorE[i++];
        }
        else if (compara(vetorE[i],vetorD[j]) == 1){
            (*v)[k] = vetorE[i++];
        }
        else {
            (*v)[k] = vetorD[j++];
        }
        
    }
    free(vetorE);
    free(vetorD);
}
//ordena por merge
int mergeint(Tupa **v, int l, int r,int n){
    int b;
    int esq,dir;
    b = 1;
    while (b < n){
        esq = 0;
        while ((esq + b) < n)
        {
            dir = esq + (2 * b);
            if (dir > n){
                dir = n;
            }
            merge(v,esq,(esq + b) - 1,dir - 1);
            esq = esq + (2 * b);
        }
        b = b * 2;
    }
    return 0;
}
//essa funcao apenas printando as upas
void printupa(Tupa **upa,int qnt){
    for (int i = 0; i < qnt;i++){
        printf("%s %d %d %d %d\n",(*upa)[i].nome,(*upa)[i].caso.grave,(*upa)[i].caso.medio,(*upa)[i].caso.normal,(*upa)[i].caso.plantao);
    }
}