//Caio Silas 
//21.1.4111

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mmu.h"
#include "constantes.h"
#include "funcoes.h"



int main (){
    Instrucao memoriaInstrucao [TAMANHO_PROGRAMA];
    Memoria memoria;
    CustoPrograma c;
    //colocando zero nas variaveis 
    c.hitC1 = 0;
    c.missC1 = 0;
    c.hitC1 = 0; 
    c.missC1 = 0;
	c.hitC2 = 0; 
    c.missC2 = 0;
	c.hitC3 = 0; 
    c.missC3 = 0;
	c.hitR = 0; 
    c.missR = 0;
	c.hitHD = 0; 
    c.custo = 0;

    MontarHD();
    montarBlocoMemoriaVazio(memoria.RAM, TAMANHO_RAM);
	montarBlocoMemoriaVazio(memoria.cache1, TAMANHO_CACHE1);
	montarBlocoMemoriaVazio(memoria.cache2, TAMANHO_CACHE2);
	montarBlocoMemoriaVazio(memoria.cache3, TAMANHO_CACHE3);
   

    montarProgramaGerador(memoriaInstrucao, TAMANHO_PROGRAMA);
    maquina(memoriaInstrucao, &memoria , 0 , &c, TAMANHO_PROGRAMA);
    return 0;
}