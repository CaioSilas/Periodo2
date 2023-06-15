#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende{
  //preencher
  int idade;
  char nome[25];
  int escalado;
};

struct time{
  //preencher
  char piloto[25];
  char lider[25];
  char entregador[25];
  int idadepiloto;
  int idadelider;
  int idadeentregador;
};

void lerQuantidade(int *qtd){
  scanf ("%d",qtd);
}
//Manter como especificado

TADduende *alocaDuendes(int qtd){
  TADduende *vetorDuende;
  vetorDuende = malloc(qtd * sizeof(TADduende));

  return vetorDuende;
}

//Manter como especificado
TADtime *alocaTimes(int qtd){
  TADtime *vetorTime;
  vetorTime = malloc(qtd * sizeof(TADtime));
  return vetorTime;
}

//Manter como especificado
void desalocaDuendes(TADduende **D){
  free(*D);
}

//Manter como especificado
void desalocaTimes(TADtime **T){
  free(*T);
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  //ler nome e idade de cada duente
  //aproveitar para colocar o valor 0 no campo escalado
  for ( i = 0; i < qtd; i++)
  {
    scanf("%s %d",D[i].nome,&D[i].idade);
    D[i].escalado = 0;
  }
  
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;
  //lider
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1;
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].lider, D[indice].nome);
    //copiar a idade
    T[i].idadelider = D[indice].idade;
  }

  //entregador
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1;
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].entregador, D[indice].nome);
    //copiar a idade
    T[i].idadeentregador = D[indice].idade;
  }

  //piloto
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1;
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].piloto, D[indice].nome);
    //copiar a idade
    T[i].idadepiloto = D[indice].idade;

  }
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice;
  //determinar o indice do duende mais velho nao escalado ainda
  //variaveis adicionais podem ser criadas
  int maisvelho = 0;
  for (int i = 0; i< qtd;i++){
    if (D[i].idade > maisvelho && D[i].escalado == 0){
      maisvelho = D[i].idade;
      indice = i;
    }
  }
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
  for (int i = 0; i < qtd; i++)
  {
    printf("Time %d\n",i + 1);
    printf("%s %d\n",T[i].lider,T[i].idadelider);
    printf("%s %d\n",T[i].entregador,T[i].idadeentregador);
    printf("%s %d\n",T[i].piloto,T[i].idadepiloto);
    printf("\n");
  }
}
