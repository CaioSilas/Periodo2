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
int ordena(Tupa **upa, int qnt){
    Tupa aux;
    int maior = 0;
    for (int i = 0;i < qnt;i++){
        int flag = 0;
        for (int k = 0; k < qnt - 1 - i; k++)
        {
            maior = compara((*upa)[k],(*upa)[k + 1]);
            // se maior for igual a 2 quer dizer que y e maior que x e deve ser feita uma troca
            if (maior == 2){
                aux = (*upa)[k];
                (*upa)[k] = (*upa)[k + 1];
                (*upa)[k + 1] = aux;
                flag += 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
    return 0;
}
// int insertion(Tupa **upa,int qnt){
//     int i,j;
//     Tupa aux;
//     printf("100\n");
//     for (i = 0; i < qnt;i++){
//         aux = (*upa)[i];
//         j = 1;
//         while (j >= 0 && compara((*upa)[i],(*upa)[j]) == 2){
//             (*upa)[i] = (*upa)[j]; 
//             j++;
//         }
//         (*upa)[i + 1] = aux;
//     }
//     return 0;
// }


//essa funcao apenas printando as upas
void printupa(Tupa **upa,int qnt){
    for (int i = 0; i < qnt;i++){
        printf("%s %d %d %d %d\n",(*upa)[i].nome,(*upa)[i].caso.grave,(*upa)[i].caso.medio,(*upa)[i].caso.normal,(*upa)[i].caso.plantao);
    }
}