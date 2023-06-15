//Caio Silas 
//21.1.4111

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mmu.h"
#include "constantes.h"
#include "final.h"



int main (){
    Instrucao memoriaInstrucao [TAMANHO_PROGRAMA];
    BlocoMemoria RAM[TAMANHO_RAM], Cache1[TAMANHO_CACHE1], Cache2[TAMANHO_CACHE2], Cache3[TAMANHO_CACHE3];
    //montando a RAM
    montarBlocoMemoriaCheio(RAM,TAMANHO_RAM,CRAM);
    //montando a cache1
    montarBlocoMemoriaVazio(Cache1,TAMANHO_CACHE1);
    //montando a cache2
    montarBlocoMemoriaVazio(Cache2,TAMANHO_CACHE2);
    //montando a cache3
    montarBlocoMemoriaVazio(Cache3,TAMANHO_CACHE3);

    montarProgramaGerador(memoriaInstrucao);
    maquina(memoriaInstrucao, RAM , Cache1, Cache2, Cache3);
    return 0;
}