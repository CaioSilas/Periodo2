#include "avl.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    TAVL avl;
    TItem aux;
    int comprimento, i;
    char string[10000];
    char *charPtr;

    // Inicializar a arvore
    TAVLInicia(&avl);

    // enquanto houver string sendo lida
    while(scanf("%s", string) == 1)
    {
        // dispensa o \n
        getchar();
        // determina o numero de caracteres da string
        comprimento = strlen(string);
        // se tiver tamanho zero, pula
        if(!comprimento)
            continue;

        // para cada um dos caracteres da string
        for (i = 0; i < comprimento; ++i)
        {
            // transforma em caracteres minúsculos
            string[i] = tolower(string[i]);
            // se o caractere não for uma letra minuscula
            if(string[i] < 'a' || string[i] > 'z')
                // atribui o codigo de espaco em branco
                string[i] = 32;
        }
        // a funcao strk divide uma string em substrings chamadas tokens
        charPtr = strtok(string, " ");

        // enquanto o ponteiro for valido
        while(charPtr != NULL)
        {
            // se o token apontado pelo ponteiro tiver comprimento maior que zero
            if(strlen(charPtr) != 0){
                // copiar o token para o TItem aux
				strcpy(aux.chave,charPtr);
				// inserir aux na arvore
				TAVLInsere(&avl,&aux);
            }
            // pega o proximo token
            charPtr = strtok(NULL, " ");
        }
    }
    // Imprimir a altura da árvore
    // Preencher aqui
    int altesq = TAVLAltura(avl);
    printf("%d\n",altesq);

    // realizar o caminhamento adequado na arvore de forma a imprimir as palavras em ordem alfabetica
    // Preencher aqui
    // Central(avl);
    // PosOrdem(avl);
    PreOrdem(avl);

    return 0;
}
