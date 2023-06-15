#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void montaRam(int *memoriaDados){
    srand(time(NULL));

    for(int i  = 0; i < 1000; i++){
        memoriaDados[i] = rand() % 100;
    }
}

void maquinaInterpretada(int *umaInstrucao, int *memoriaDados){
    int opcode = umaInstrucao[0];
    int end1, end2, conteudoRam1, conteudoRam2, soma = 0, sub = 0, end3, conteudo, end;

    switch(opcode){
        case 0:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];

            conteudoRam1 = memoriaDados[end1];
            conteudoRam2 = memoriaDados[end2];
            soma = conteudoRam1 + conteudoRam2;

            end3 = umaInstrucao[3];
            memoriaDados[end3] = soma;

            printf("Somando %d com %d e obtendo %d\n", conteudoRam1, conteudoRam2, soma);
        break;
        
        case 1:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];

            conteudoRam1 = memoriaDados[end1];
            conteudoRam2 = memoriaDados[end2];
            sub = conteudoRam1 - conteudoRam2;

            end3 = umaInstrucao[3];
            memoriaDados[end3] = soma;

            printf("Substraindo %d com %d e obtendo %d\n", conteudoRam1, conteudoRam2, sub);
        break;

        case 2:
            conteudo = umaInstrucao[1]; 
            end = umaInstrucao[2];
            memoriaDados[end] = conteudo;
        break;

        case 3:
            umaInstrucao[1] = memoriaDados[umaInstrucao[2]];
        break;
    }
}

void maquina(int memoriaInstrucoes[][4], int *memoriaDados){
    int opcode = 0, PC = 0;
    int umaInstrucao[4];

    while(opcode != -1){
        umaInstrucao[0] = memoriaInstrucoes[PC][0];
        umaInstrucao[1] = memoriaInstrucoes[PC][1];
        umaInstrucao[2] = memoriaInstrucoes[PC][2];
        umaInstrucao[3] = memoriaInstrucoes[PC][3];

        opcode = umaInstrucao[0];

        maquinaInterpretada(umaInstrucao, memoriaDados);
        PC++;
    }

}

void montarInstrucoesProgramaAleatorio(int *memoriaDados){
    srand(time(NULL));
    int memoriaInstrucoes[100][4];

    for(int i = 0; i < 99; i++){
        
        memoriaInstrucoes[i][0] = rand() % 2;
        memoriaInstrucoes[i][1] = rand() % 1000; 
        memoriaInstrucoes[i][2] = rand() % 1000; 
        memoriaInstrucoes[i][3] = rand() % 1000; 
    }

    memoriaInstrucoes[99][0] = -1; 
    memoriaInstrucoes[99][1] = -1; 
    memoriaInstrucoes[99][2] = -1; 
    memoriaInstrucoes[99][3] = -1; 
    
    maquina(memoriaInstrucoes, memoriaDados);
}

int main (){
    int memoriaDados[1000];
    montaRam(memoriaDados);

    montarInstrucoesProgramaAleatorio(memoriaDados);

    return 0;
}