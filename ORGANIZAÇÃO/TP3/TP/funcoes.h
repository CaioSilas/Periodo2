//Caio Silas 
//21.1.4111

#ifndef funcoes_h
#define funcoes_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mmu.h"
#include "constantes.h"
#include "cor2.h"





void montarBlocoMemoriaCheio(BlocoMemoria *bloco, int tamanho, int tipo);
void montarBlocoMemoriaVazio(BlocoMemoria *bloco, int tamanho);

void maquina(Instrucao *memoriaInstrucoes, Memoria *memoria, int interAtual, CustoPrograma *c, int tamanhoPrograma);
void montarInstrucoesProgramaAleatorio(Instrucao *memoriaInstrucoes);
void montarProgramaGerador(Instrucao *memoriaInstrucoes, int tamanhoPrograma);

//montando HD
void MontarHD();
void printar();
#endif