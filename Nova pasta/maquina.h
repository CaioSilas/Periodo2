
#ifndef maquina_h
#define maquina_h

#include "constantes.h"
#include "mmu.h"

void montarBlocoMemoriaCheio(BlocoMemoria *bloco, int tamanho, int tipo);
void montarBlocoMemoriaVazio(BlocoMemoria *bloco, int tamanho);

void maquina(Instrucao *memoriaInstrucoes, Memoria *memoria, int interAtual, CustoPrograma *c);
void montarInstrucoesProgramaAleatorio(Instrucao *memoriaInstrucoes);
void montarProgramaGerador(Instrucao *memoriaInstrucoes, int tamanhoPrograma);

void montarHD();
void printarHD();

#endif