//Caio Silas 
//21.1.4111

#ifndef final_h
#define final_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mmu.h"
#include "constantes.h"
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
void maquina(Instrucao *memoriaInstrucoes, BlocoMemoria *RAM, BlocoMemoria *cache1, BlocoMemoria *cache2, BlocoMemoria *cache3){
    int PC = 0, opcode = 0, custo = 0, tempoEx = 1;
    int hitC1 = 0, hitC2 = 0, hitC3 = 0, hitR = 0, missC1 = 0, missC2 = 0, missC3 = 0;

    while(opcode != HALT){
        Instrucao umaIstrucao = memoriaInstrucoes[PC];
        opcode = umaIstrucao.opcode;
        
        if (opcode != HALT){
            BlocoMemoria dadoMemoria1 = buscarNasMemoriasAssociativo(umaIstrucao.end1,RAM,cache1,cache2,cache3);
            dadoMemoria1.tempoChamado = tempoEx;
            for (int i = 0; i < TAMANHO_CACHE1; i++)
            {
                if (dadoMemoria1.endBloco == cache1[i].endBloco){
                    cache1[i] = dadoMemoria1;
                    break;
                }
            }

            BlocoMemoria dadoMemoria2 = buscarNasMemoriasAssociativo(umaIstrucao.end2,RAM,cache1,cache2,cache3);
            dadoMemoria2.tempoChamado = tempoEx;
            for (int i = 0; i < TAMANHO_CACHE1; i++)
            {
                if (dadoMemoria2.endBloco == cache1[i].endBloco){
                    cache1[i] = dadoMemoria2;
                    break;
                }
            }

            BlocoMemoria dadoMemoria3 = buscarNasMemoriasAssociativo(umaIstrucao.end3,RAM,cache1,cache2,cache3);
            dadoMemoria3.tempoChamado = tempoEx;
            for (int i = 0; i < TAMANHO_CACHE1; i++)
            {
                if(dadoMemoria3.endBloco == cache1[i].endBloco){
                    cache1[i] = dadoMemoria3;
                    break;
                }
            }

            //aumentando o custo da maquina
            custo += dadoMemoria1.custo;
            custo += dadoMemoria2.custo;
            custo += dadoMemoria3.custo;

            switch (dadoMemoria1.cacheHit)
            {
                case CACHE1:
                    hitC1++;
                    break;
                
                case CACHE2:
                    missC1++;
                    hitC2++;
                    break;
                
                case CACHE3:
                    missC2++;
                    hitC3++;
                case CRAM:
                    missC1++;
                    missC2++;
                    missC3++;
                    hitR++;
                    break;
            }

            switch (dadoMemoria2.cacheHit)
            {
                case CACHE1:
                        hitC1++;
                        break;
                    
                    case CACHE2:
                        missC1++;
                        hitC2++;
                        break;
                    
                    case CACHE3:
                        missC2++;
                        hitC3++;
                    case CRAM:
                        missC1++;
                        missC2++;
                        missC3++;
                        hitR++;
                        break;
            }

            switch (dadoMemoria3.cacheHit)
            {
                case CACHE1:
                        hitC1++;
                        break;
                    
                    case CACHE2:
                        missC1++;
                        hitC2++;
                        break;
                    
                    case CACHE3:
                        missC2++;
                        hitC3++;
                    case CRAM:
                        missC1++;
                        missC2++;
                        missC3++;
                        hitR++;
                        break;
            }

            printf("\n\nCusto ate o momento do programa em execucao: %d\n", custo);
			printf("\tHits e Misses ate o momento:\n");
			printf("\tHit C1 | Miss C1 | Hit C2 | Miss C2 | Hit C3 | Miss C3 | Hit RAM\n");
			printf("\t%6d | %7d | %6d | %7d | %6d | %7d | %7d\n\n", hitC1, missC1, hitC2, missC2, hitC3, missC3, hitR);


            int conteudo1,conteudo2, resut;

            switch (opcode)
            {
                case SOMA:
                    conteudo1 = dadoMemoria1.palavra[umaIstrucao.end1.endPalavra];
                    conteudo2 = dadoMemoria2.palavra[umaIstrucao.end1.endPalavra];
                    resut = conteudo1 + conteudo2;

                    dadoMemoria3.palavra[umaIstrucao.end3.endPalavra] = resut;
                    dadoMemoria3.atualizado = 1;

                    printf("\t\tSomando %d + %d = %d\n",conteudo1,conteudo2,resut);
                    break;
                
                case SUBTRACAO:
                    conteudo1 = dadoMemoria1.palavra[umaIstrucao.end1.endPalavra];
                    conteudo2 = dadoMemoria2.palavra[umaIstrucao.end1.endPalavra];
                    resut = conteudo1 - conteudo2;

                    dadoMemoria3.palavra[umaIstrucao.end3.endPalavra] = resut;
                    dadoMemoria3.atualizado = 1;

                    printf("\t\tSubtraindo %d - %d = %d\n",conteudo1,conteudo2,resut);
                    break;

                case ESCREVER:
                    printf(BOLD(RED("\n\t\tNAO FOI POSSIVEL REALIZAR A ACAO DE ESCREVER NA MEMORIA. \n")));

                    break;
                case LER:
                    printf(BOLD(RED("\n\t\tNAO FOI POSSIVEL REALIZAR A ACAO DE LEITURA DA MEMORIA.\n")));
                    break;
            }

            for (int i = 0; i < TAMANHO_CACHE1;i++){
                if (dadoMemoria1.endBloco == cache1[i].endBloco) {
					cache1[i] = dadoMemoria1;
				}

				if (dadoMemoria2.endBloco == cache1[i].endBloco) {
					cache1[i] = dadoMemoria2;
				}

				if (dadoMemoria3.endBloco == cache1[i].endBloco) {
					cache1[i] = dadoMemoria3;
				}
            }            
        }
        PC++;
        tempoEx++;
    }

    atualizarRAM(RAM,cache1,cache2,cache3);
    printf("\n\nCusto total do programa: %d\n", custo);
	printf("\tHits e Misses do programa:\n");
	printf("\tHit C1 | Miss C1 | Hit C2 | Miss C2 | Hit C3 | Miss C3 | Hit RAM\n");
	printf("\t%6d | %7d | %6d | %7d | %6d | %7d | %7d\n", hitC1, missC1, hitC2, missC2, hitC3, missC3, hitR);
    
}
//gerador
void montarProgramaGerador(Instrucao *memoriaInstrucoes){
    FILE *arquivo;
    char aux[100], *token;

    arquivo = fopen("programa.txt","r");
    if (arquivo != NULL){
        for (int i = 0; i < TAMANHO_PROGRAMA - 1; i++){
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
        memoriaInstrucoes[TAMANHO_PROGRAMA - 1].opcode = -1;
        fclose(arquivo);
    }
    else {
        printf("NAO FOI POSSIVEL ABRIR O ARQUIVO");
        exit(1);
    }

}

#endif