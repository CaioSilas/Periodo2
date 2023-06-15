#include "funcoes.h"
#include "mmu.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cor2.h"


//função que monta a RAM, colocando i para o end e um numero aleatorio para a palavra
void montarBlocoMemoriaCheio(BlocoMemoria *bloco, int tamanho, int tipo){
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++){
        bloco[i].tempoChamado = 0;
        bloco[i].atualizado = 0;
        bloco[i].cacheHit = 0;
        if (tipo ==  CRAM){
            bloco[i].endBloco = i;
        }
        else {
            bloco[i].endBloco = -1;
        }
        for (int j = 0; j < QDE_PALAVRAS_BLOCO;j++){
            bloco[i].palavra[j] = rand() % 1000000;
        }
    }
}
//função que monta os caches
void montarBlocoMemoriaVazio(BlocoMemoria *bloco, int tamanho){
    for (int i = 0; i < tamanho; i++){
        bloco[i].endBloco = -1;
        bloco[i].tempoChamado = 0;
        bloco[i].atualizado = 0;
        bloco[i].cacheHit = CRAM;
    }
}
//maquina
void maquina(Instrucao *memoriaInstrucoes, Memoria *memoria, int interAtual,CustoPrograma *c, int tamanhoPrograma){
    int PC = 0, opcode = 0, tempoEx = 1;

    while(opcode != HALT){
        Instrucao umaIstrucao = memoriaInstrucoes[PC];
        opcode = umaIstrucao.opcode;
        
        if (opcode != HALT){
            BlocoMemoria dadoMemoria1 = buscarNasMemoriasAssociativo(umaIstrucao.end1,memoria);
            dadoMemoria1.tempoChamado = tempoEx;
            for (int i = 0; i < TAMANHO_CACHE1; i++)
            {
                if (dadoMemoria1.endBloco == memoria->cache1[i].endBloco){
                    memoria->cache1[i] = dadoMemoria1;
                    break;
                }
            }

            BlocoMemoria dadoMemoria2 = buscarNasMemoriasAssociativo(umaIstrucao.end2,memoria);
            dadoMemoria2.tempoChamado = tempoEx;
            for (int i = 0; i < TAMANHO_CACHE1; i++)
            {
                if (dadoMemoria2.endBloco == memoria->cache1[i].endBloco){
                    memoria->cache1[i] = dadoMemoria2;
                    break;
                }
            }

            BlocoMemoria dadoMemoria3 = buscarNasMemoriasAssociativo(umaIstrucao.end3,memoria);
            dadoMemoria3.tempoChamado = tempoEx;
            for (int i = 0; i < TAMANHO_CACHE1; i++)
            {
                if(dadoMemoria3.endBloco == memoria->cache1[i].endBloco){
                    memoria->cache1[i] = dadoMemoria3;
                    break;
                }
            }   

            //aumentando o custo da maquina
            c->custo += dadoMemoria1.custo;
            c->custo += dadoMemoria2.custo;
            c->custo += dadoMemoria3.custo;

            switch (dadoMemoria1.cacheHit)
            {
                case CACHE1:
                    c->hitC1++;
                    break;
                
                case CACHE2:
                    c->missC1++;
                    c->hitC2++;
                    break;
                
                case CACHE3:
                    c->missC1++;
                    c->missC2++;
                    c->hitC3++;
                    break;
                case CRAM:
                    c->missC1++;
                    c->missC2++;
                    c->missC3++;
                    c->hitR++;
                    break;
                case HD:
                    c->missC1++;
                    c->missC2++;
                    c->missC3++;
                    c->missR++;
                    c->hitHD++;
                    break;
            }

            switch (dadoMemoria2.cacheHit)
            {
                 case CACHE1:
                    c->hitC1++;
                    break;
                
                case CACHE2:
                    c->missC1++;
                    c->hitC2++;
                    break;
                
                case CACHE3:
                    c->missC1++;
                    c->missC2++;
                    c->hitC3++;
                    break;
                case CRAM:
                    c->missC1++;
                    c->missC2++;
                    c->missC3++;
                    c->hitR++;
                    break;
                case HD:
                    c->missC1++;
                    c->missC2++;
                    c->missC3++;
                    c->missR++;
                    c->hitHD++;
                    break;
            }

            switch (dadoMemoria3.cacheHit)
            {
                 case CACHE1:
                    c->hitC1++;
                    break;
                
                case CACHE2:
                    c->missC1++;
                    c->hitC2++;
                    break;
                
                case CACHE3:
                    c->missC1++;
                    c->missC2++;
                    c->hitC3++;
                    break;
                case CRAM:
                    c->missC1++;
                    c->missC2++;
                    c->missC3++;
                    c->hitR++;
                    break;
                case HD:
                    c->missC1++;
                    c->missC2++;
                    c->missC3++;
                    c->missR++;
                    c->hitHD++;
                    break;
            }

			// printf("\n\nCusto ate o momento do programa em execucao: %I64lld\n", c->custo);
			// printf("\tHits e Misses ate o momento:\n");
			// printf("\tHit C1 | Miss C1 | Hit C2 | Miss C2 | Hit C3 | Miss C3 | Hit RAM | Miss RAM | Hit HD\n");
			// printf("\t%6d | %7d | %6d | %7d | %6d | %7d | %7d | %8d | %6d\n\n", c->hitC1, c->missC1, c->hitC2, c->missC2, c->hitC3, c->missC3, c->hitR, c->missR, c->hitHD);


            int conteudo1,conteudo2, resut;

            switch (opcode)
            {
                case SOMA:
                    conteudo1 = dadoMemoria1.palavra[umaIstrucao.end1.endPalavra];
                    conteudo2 = dadoMemoria2.palavra[umaIstrucao.end1.endPalavra];
                    resut = conteudo1 + conteudo2;

                    dadoMemoria3.palavra[umaIstrucao.end3.endPalavra] = resut;
                    dadoMemoria3.atualizado = 1;

                    // printf("\t\tSomando %d + %d = %d\n",conteudo1,conteudo2,resut);
                    break;
                
                case SUBTRACAO:
                    conteudo1 = dadoMemoria1.palavra[umaIstrucao.end1.endPalavra];
                    conteudo2 = dadoMemoria2.palavra[umaIstrucao.end1.endPalavra];
                    resut = conteudo1 - conteudo2;

                    dadoMemoria3.palavra[umaIstrucao.end3.endPalavra] = resut;
                    dadoMemoria3.atualizado = 1;

                    // printf("\t\tSubtraindo %d - %d = %d\n",conteudo1,conteudo2,resut);
                    break;

                case ESCREVER:
                    // printf(BOLD(RED("\n\t\tNAO FOI POSSIVEL REALIZAR A ACAO DE ESCREVER NA MEMORIA. \n")));

                    break;
                case LER:
                    // printf(BOLD(RED("\n\t\tNAO FOI POSSIVEL REALIZAR A ACAO DE LEITURA DA MEMORIA.\n")));
                    break;
            }

            for (int i = 0; i < TAMANHO_CACHE1;i++){
                if (dadoMemoria1.endBloco == memoria->cache1[i].endBloco) {
					memoria->cache1[i] = dadoMemoria1;
				}

				if (dadoMemoria2.endBloco == memoria->cache1[i].endBloco) {
					memoria->cache1[i] = dadoMemoria2;
				}

				if (dadoMemoria3.endBloco == memoria->cache1[i].endBloco) {
					memoria->cache1[i] = dadoMemoria3;
				}
            }            
        }

        if (interAtual < INTERRUPCAO_MAX){
			srand(time(NULL));
			int chance = rand() % (CHANCE_INTERRUPCAO * (interAtual+1));
			int tamanhoInterrupcao = rand() % 10001;
            
            printf("PC = %d\n",PC);
			
			if (chance == 0) {
				printf("\nINICIO - TRATADOR DE INTERRUPCAO - CAMADA %d\n\n", interAtual+1);
				montarProgramaGerador(memoriaInstrucoes, tamanhoInterrupcao);
                
				maquina(memoriaInstrucoes, memoria, interAtual+1, c, tamanhoInterrupcao);
				printf("\nFIM - TRATADOR DE INTERRUPCAO - CAMADA %d\n\n", interAtual+1);
				montarProgramaGerador(memoriaInstrucoes, tamanhoPrograma);
                printf("PC = %d\n",PC);
            }
		}


        PC++;
        tempoEx++;
    }

    atualizarHD(memoria);
    printf("\n\n%d Custo total do programa: %I64lld\n",interAtual,c->custo);
	printf("\tHits e Misses do programa:\n");
	printf("\tHit C1 | Miss C1 | Hit C2 | Miss C2 | Hit C3 | Miss C3 | Hit RAM | Miss RAM | Hit HD\n");
	printf("\t%6d | %7d | %6d | %7d | %6d | %7d | %7d | %8d | %6d\n\n", c->hitC1, c->missC1, c->hitC2, c->missC2, c->hitC3, c->missC3, c->hitR, c->missR, c->hitHD);

}
//gerador
void montarProgramaGerador(Instrucao *memoriaInstrucoes, int tamanhoPrograma){
    FILE *arquivo;
    char aux[100], *token;

    arquivo = fopen("programa.txt","r");
    if (arquivo != NULL){
        for (int i = 0; i < tamanhoPrograma - 1; i++){
            fgets (aux,100,arquivo);

            token = strtok(aux, ":");
            memoriaInstrucoes[i].opcode = atoi(token);

            token = strtok(NULL, ":");
            memoriaInstrucoes[i].end1.endBloco = atoi(token);
            token = strtok(NULL, ":");
            memoriaInstrucoes[i].end1.endPalavra = atoi(token) % QDE_PALAVRAS_BLOCO;

            token = strtok(NULL, ":");
            memoriaInstrucoes[i].end2.endBloco = atoi(token);
            token = strtok(NULL, ":");
            memoriaInstrucoes[i].end2.endPalavra = atoi(token) % QDE_PALAVRAS_BLOCO;

            token = strtok(NULL, ":");
            memoriaInstrucoes[i].end3.endBloco = atoi(token);
            token = strtok(NULL, ":");
            memoriaInstrucoes[i].end3.endPalavra = atoi(token) % QDE_PALAVRAS_BLOCO;
        }
        memoriaInstrucoes[tamanhoPrograma - 1].opcode = -1;
        fclose(arquivo);
    }
    else {
        printf("NAO FOI POSSIVEL ABRIR O ARQUIVO");
        exit(1);
    }

}
//montando o HD
void MontarHD(){
    FILE *arquivo;
    BlocoMemoria aux;

    arquivo = fopen("HD.bin","rb");
    
    if (arquivo == NULL){

        arquivo = fopen("HD.bin","wb");
        srand(time(NULL));

        for(int i = 0;i < TAMANHO_PROGRAMA; i++){
            aux.tempoChamado = 0;
            aux.cacheHit = HD;
            aux.atualizado = 0;
            aux.endBloco = i;
            for (int j = 0; j < QDE_PALAVRAS_BLOCO;j++){
                aux.palavra[j] = rand() % 1000000; 
            }

            fwrite (&aux,sizeof(BlocoMemoria),1,arquivo);
        }

        fclose(arquivo);
    }
}

void printar() {
	FILE *arquivo;
	BlocoMemoria aux;

	arquivo = fopen("hd.bin", "rb");

	printf("\n\n");
	if (arquivo != NULL) {

		for (int i = 0; i < TAMANHO_HD; i++) {
			fread(&aux, sizeof(BlocoMemoria), 1, arquivo);

			printf("%d ", aux.endBloco);
			printf("%d %d %d %d ", aux.palavra[0], aux.palavra[1], aux.palavra[2], aux.palavra[3]);
			printf("%d ", aux.cacheHit);
			printf("%d ", aux.atualizado);
			printf("%d ", aux.custo);
			printf("%d\n", aux.tempoChamado);
		}

		fclose(arquivo);
	}
}