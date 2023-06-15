//caio silas
//21.1.4111

#include "mmu.h"
#include "constantes.h"
//faz a buscas nas caches para saber onde o conteudo esta localizado
BlocoMemoria buscarNasMemoriasAssociativo(Endereco e, BlocoMemoria *RAM, BlocoMemoria *cache1, BlocoMemoria *cache2, BlocoMemoria *cache3) {
	int posicaoCache1, posicaoCache2, posicaoCache3;
	int i;
	int custo = 0;

	//aumentando o custo em +10
	custo += CUSTO_CACHE1;
	for (i = 0; i < TAMANHO_CACHE1; i++) {
		if (cache1[i].endBloco == e.endBloco) {
			cache1[i].custo = custo;
			cache1[i].cacheHit = CACHE1;

			return cache1[i];
		}
	}

	//aumentando o custo em +100
	custo += CUSTO_CACHE2;
	for (i = 0; i < TAMANHO_CACHE2; i++) {
		if (cache2[i].endBloco == e.endBloco) {
			cache2[i].cacheHit = CACHE2;

			posicaoCache1 = buscaLRU(cache1, TAMANHO_CACHE1);
			//fazendo a troca doque esta na cache 2 para a cache 1
			return trocarmemoria(posicaoCache1, i, cache1, cache2, custo);
		}
	}

	//aumentando o custo em +1000
	custo += CUSTO_CACHE3;
	for (i = 0; i < TAMANHO_CACHE3; i++) {
		if (cache3[i].endBloco == e.endBloco) {
			cache3[i].cacheHit = CACHE3;

			posicaoCache1 = buscaLRU(cache1, TAMANHO_CACHE1);
			posicaoCache2 = buscaLRU(cache2, TAMANHO_CACHE2);
			//fazendo a troca doque esta na cache 3 para a cache 2
			trocarmemoria(posicaoCache2, i, cache2, cache3, custo);
			//fazendo a troca doque esta na cache 2 para a cache 1
			return trocarmemoria(posicaoCache1, posicaoCache2, cache1, cache2, custo);
		}
	}
	
	//aumentando o custo em +10000
	custo += CUSTO_RAM;
	
	RAM[e.endBloco].cacheHit = CRAM;

	//pegando a posição da memoria na cache
	posicaoCache1 = buscaLRU(cache1, TAMANHO_CACHE1);
	posicaoCache2 = buscaLRU(cache2, TAMANHO_CACHE2);
	posicaoCache3 = buscaLRU(cache3, TAMANHO_CACHE3);

	//verifica se a posição foi atualizada,sendo usada e preciso salvar na ram para nao perder o conteudo
	if (cache3[posicaoCache3].atualizado) {
		cache3[posicaoCache3].atualizado = 0;
		RAM[cache3[posicaoCache3].endBloco] = cache3[posicaoCache3];
	}

	cache3[posicaoCache3] = RAM[e.endBloco];
	//fazendo a troca doque esta na cache 3 para a cache 2
	trocarmemoria(posicaoCache2, posicaoCache3, cache2, cache3, custo);
	//fazendo a troca doque esta na cache 2 para a cache 1
	return trocarmemoria(posicaoCache1, posicaoCache2, cache1, cache2, custo);
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
void atualizarRAM(BlocoMemoria *RAM, BlocoMemoria *cache1, BlocoMemoria *cache2, BlocoMemoria *cache3) {
	int i;

	for (i = 0; i < TAMANHO_CACHE1; i++) {
		if (cache1[i].atualizado) {
			RAM[cache1[i].endBloco] = cache1[i];
		}
	}

	for (i = 0; i < TAMANHO_CACHE2; i++) {
		if (cache2[i].atualizado) {
			RAM[cache2[i].endBloco] = cache2[i];
		}
	}

	for (i = 0; i < TAMANHO_CACHE3; i++) {
		if (cache3[i].atualizado) {
			RAM[cache3[i].endBloco] = cache3[i];
		}
	}

}