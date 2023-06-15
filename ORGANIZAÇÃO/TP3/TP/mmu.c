//caio silas
//21.1.4111

#include <stdio.h>
#include <stdlib.h>
#include "mmu.h"
#include "constantes.h"

//faz a buscas nas caches para saber onde o conteudo esta localizado
BlocoMemoria buscarNasMemoriasAssociativo (Endereco e, Memoria *memoria) {	
	int posicaoCache1, posicaoCache2, posicaoCache3,posicaoRAM;
	int i;
	int custo = 0;

	//aumentando o custo em +10
	custo += CUSTO_CACHE1;
	for (i = 0; i < TAMANHO_CACHE1; i++) {
		if (memoria->cache1[i].endBloco == e.endBloco) {
			memoria->cache1[i].custo = custo;
			memoria->cache1[i].cacheHit = CACHE1;

			return memoria->cache1[i];
		}
	}
	posicaoCache1 = buscaLRU(memoria->cache1, TAMANHO_CACHE1);

	//aumentando o custo em +100
	custo += CUSTO_CACHE2;
	for (i = 0; i < TAMANHO_CACHE2; i++) {
		if (memoria->cache2[i].endBloco == e.endBloco) {
			memoria->cache2[i].cacheHit = CACHE2;

			// posicaoCache1 = buscaLRU(memoria->cache1, TAMANHO_CACHE1);
			//fazendo a troca doque esta na cache 2 para a cache 1
			return trocarmemoria(posicaoCache1, i, memoria->cache1, memoria->cache2, custo);
		}
	}

	posicaoCache2 = buscaLRU(memoria->cache2, TAMANHO_CACHE2);
	//aumentando o custo em +1000
	custo += CUSTO_CACHE3;
	for (i = 0; i < TAMANHO_CACHE3; i++) {
		if (memoria->cache3[i].endBloco == e.endBloco) {
			memoria->cache3[i].cacheHit = CACHE3;

			//posicaoCache1 = buscaLRU(memoria->cache1, TAMANHO_CACHE1);
			
			//fazendo a troca doque esta na cache 3 para a cache 2
			trocarmemoria(posicaoCache2, i, memoria->cache2, memoria->cache3, custo);
			//fazendo a troca doque esta na cache 2 para a cache 1
			return trocarmemoria(posicaoCache1, posicaoCache2, memoria->cache1, memoria->cache2, custo);
		}
	}

	posicaoCache3 = buscaLRU(memoria->cache3, TAMANHO_CACHE3);	
	//aumentando o custo em +10000
	custo += CUSTO_RAM;
	for (i = 0; i < TAMANHO_RAM;i++){
		if (memoria->RAM[i].endBloco == e.endBloco){
			memoria->RAM[i].cacheHit = CRAM;

			if (memoria->cache3[posicaoCache3].atualizado){
				for (int j = 0; j < TAMANHO_RAM; j++){
					if (memoria->cache3[posicaoCache3].endBloco == memoria->RAM[j].endBloco){
						memoria->RAM[j] = memoria->cache3[posicaoCache3];
					}
				}
			}
			memoria->cache3[posicaoCache3] = memoria->RAM[i];
			trocarmemoria(posicaoCache2,posicaoCache3,memoria->cache2,memoria->cache3,custo);	
			return trocarmemoria(posicaoCache1,posicaoCache2,memoria->cache1,memoria->cache2,custo);
		}
	}
	BlocoMemoria aux;
	FILE *arquivo;
	int posicaoHD = e.endBloco * sizeof(BlocoMemoria);

	posicaoRAM = buscaLRU(memoria->RAM,TAMANHO_RAM);
	//aumentando o custo em 100000
	custo += CUSTO_HD;
	
	arquivo = fopen("HD.bin","r+b");

	if (arquivo != NULL){
		fseek (arquivo,posicaoHD,SEEK_SET);
		fread(&aux,sizeof(BlocoMemoria),1,arquivo);

		if (memoria->RAM[posicaoRAM].atualizado){
			memoria->RAM[posicaoRAM].atualizado = 0;

			fseek (arquivo,memoria->RAM[posicaoRAM].endBloco * sizeof(BlocoMemoria),SEEK_SET);
			fwrite(&(memoria->RAM[posicaoRAM]),sizeof(BlocoMemoria),1,arquivo);
		}

		fclose(arquivo);
		memoria->RAM[posicaoRAM] = aux;

		if (memoria->cache3[posicaoCache3].atualizado){
			for (int j = 0; j < TAMANHO_RAM; j++){
				if (memoria->cache3[posicaoCache3].endBloco == memoria->RAM[j].endBloco){
					memoria->RAM[j] = memoria->cache3[posicaoCache3];
				}
			}
		}

		memoria->cache3[posicaoCache3] = memoria->RAM[posicaoRAM];
		trocarmemoria(posicaoCache2,posicaoCache3,memoria->cache2,memoria->cache3,custo);
		return trocarmemoria(posicaoCache1,posicaoCache2,memoria->cache1,memoria->cache2,custo);
	}
	else {
		printf("\n\n\n\t SEM HD!!!");
		exit(1);
	}
}
//troca o conteudo de cache
BlocoMemoria trocarmemoria(int posicaoBloco1, int posicaoBloco2, BlocoMemoria *bloco1, BlocoMemoria *bloco2, int custo) {
	BlocoMemoria aux = bloco1[posicaoBloco1];
	bloco1[posicaoBloco1] = bloco2[posicaoBloco2];
	bloco2[posicaoBloco2] = aux;

	bloco1[posicaoBloco1].custo = custo;

	return bloco1[posicaoBloco1];
}
//busca a posição menos utilizada para fazeer a substituição
int buscaLRU(BlocoMemoria *bloco, int tamanho) {
	int i, LRU = 0;
	
	for (i = 1; i < tamanho; i++) {
		if (bloco[i].tempoChamado < bloco[LRU].tempoChamado) {
			LRU = i;
		}
	}

	return LRU;
}
//todas a posicicoes que foram alteradas ele coloca na RAM
void atualizarHD(Memoria *memoria) {
	int i;
	FILE *arquivo;

	arquivo = fopen("HD.bin", "r+b");

	if (arquivo != NULL) {
		for (i = 0; i < TAMANHO_CACHE1; i++) {
			if (memoria->cache1[i].atualizado) {
				fseek(arquivo, memoria->cache1[i].endBloco * sizeof(BlocoMemoria), SEEK_SET);
				fwrite(&(memoria->cache1[i]), sizeof(BlocoMemoria), 1, arquivo);
			}
		}

		for (i = 0; i < TAMANHO_CACHE2; i++) {
			if (memoria->cache2[i].atualizado) {
				fseek(arquivo, memoria->cache2[i].endBloco * sizeof(BlocoMemoria), SEEK_SET);
				fwrite(&(memoria->cache2[i]), sizeof(BlocoMemoria), 1, arquivo);
			}
		}

		for (i = 0; i < TAMANHO_CACHE3; i++) {
			if (memoria->cache3[i].atualizado) {
				fseek(arquivo, memoria->cache3[i].endBloco * sizeof(BlocoMemoria), SEEK_SET);
				fwrite(&(memoria->cache3[i]), sizeof(BlocoMemoria), 1, arquivo);
			}
		}

		for (i = 0; i < TAMANHO_RAM; i++) {
			if (memoria->RAM[i].atualizado) {
				fseek(arquivo, memoria->RAM[i].endBloco * sizeof(BlocoMemoria), SEEK_SET);
				fwrite(&(memoria->RAM[i]), sizeof(BlocoMemoria), 1, arquivo);
			}
		}

		fclose(arquivo);
	} else {
		printf("\n\n\n\t\t\t	SEM HD!!!!");
		exit(1);
	}
}