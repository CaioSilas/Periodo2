#ifndef constantes_h
#define constantes_h

#define TAMANHO_RAM 1000 // quantidade de blocos => 4k palavras
#define TAMANHO_CACHE1 8 // quantidade de blocos => na cache1 
#define TAMANHO_CACHE2 16 // quantidade de blocos =>  na cache2
#define TAMANHO_CACHE3 32 // quantidade de blocos =>  na cache3
#define TAMANHO_PROGRAMA 10001 //quantidade de instruçoes
#define QDE_PALAVRAS_BLOCO 4

#define CRAM 0
#define CACHE1 1
#define CACHE2 2
#define CACHE3 3

#define CUSTO_RAM 10000
#define CUSTO_CACHE1 10
#define CUSTO_CACHE2 100
#define CUSTO_CACHE3 1000

#define HALT -1
#define SOMA 0
#define SUBTRACAO 1
#define ESCREVER 2
#define LER 3

#endif