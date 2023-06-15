// caio silas de araujo amaro
// 21.1.4111

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



void maquinaInterpretada(int *umaInstrucao, int *matrizdedados){
    int opcode = umaInstrucao[0];
    int end1, end2, conteudoRam1, conteudoRam2, soma = 0, end3, conteudo, end;

    switch(opcode){
        //somar
        case 0:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];
            //buscando os valores
            conteudoRam1 = matrizdedados[end1];
            conteudoRam2 = matrizdedados[end2];
            //somandos os valores
            soma = conteudoRam1 + conteudoRam2;
            //salvando os dados
            end3 = umaInstrucao[3];
            matrizdedados[end3] = soma;

            // printf("Somando %d + %d = %d\n", conteudoRam1, conteudoRam2, soma);
        break;
        
        //subtrair
        case 1:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];
            //buscando os valores
            conteudoRam1 = matrizdedados[end1];
            conteudoRam2 = matrizdedados[end2];
            //subtraindo os valores
            soma = conteudoRam1 - conteudoRam2;
            //salvando
            end3 = umaInstrucao[3];
            matrizdedados[end3] = soma;

            // printf("Substraindo %d - %d = %d\n", conteudoRam1, conteudoRam2, soma);
        break;

        //levar para memoria
        case 2:
            conteudo = umaInstrucao[1]; 
            end = umaInstrucao[2];
            matrizdedados[end] = conteudo;
        break;

        //trazer da memoria
        case 3:
            umaInstrucao[1] = matrizdedados[umaInstrucao[2]];
        break;
    }
}



void maquina(int matrizdecomando[][4],int *matrizdedados){
    int opcode =0;
    int pc = 0;
    int umaInstrucao[4];

    while(opcode != -1){
        umaInstrucao[0] = matrizdecomando[pc][0];
        umaInstrucao[1] = matrizdecomando[pc][1];
        umaInstrucao[2] = matrizdecomando[pc][2];
        umaInstrucao[3] = matrizdecomando[pc][3];

        opcode = umaInstrucao[0];

        maquinaInterpretada(umaInstrucao, matrizdedados);
        pc++;
    }  
}

void maquinaintmult(int multiplicador,int multiplicando,int *matrizdedados){
    matrizdedados[1] = multiplicando;
    matrizdedados[2] = multiplicando;


    int opcode =0;
    int pc = 0;
    int matrizdecomandos[100][4];
    int resultado = 0;



    while(opcode != -1){


        opcode = umaInstrucao[0];
        

        

        for (int i = 0; i < multiplicador; i++)
        {
            maquinaInterpretada(umaInstrucao, matrizdedados);
            umaInstrucao[1] = umaInstrucao[3];
        }
        printf("multiplicando :%d * %d = %d\n",multiplicador,multiplicando,matrizdedados[resultado]);
        pc++;
    }
}

void montadados(int *matrizdados){
    for (int i = 0; i < 1000; i++)
    {
        matrizdados[i] = rand() %100;
    }  
}

void montacomandos(int *dados){
    int matrizdecomandos [100][4];
    for (int i = 0; i < 99; i++)
    {
        matrizdecomandos[i][0] = rand() %2;
        matrizdecomandos[i][1] = rand() %1000;
        matrizdecomandos[i][2] = rand() %1000;
        matrizdecomandos[i][3] = rand() %1000;
    }
    matrizdecomandos[99][0] = -1;
    matrizdecomandos[99][1] = -1;
    matrizdecomandos[99][2] = -1;
    matrizdecomandos[99][3] = -1;

    // maquina(matrizdecomandos,dados);
}

// void montacomandosmult(int *dados){
//     int matrizdecomandos [100][4];
//     for (int i = 0; i < 99; i++)
//     {
//         matrizdecomandos[i][0] = 0;
//         matrizdecomandos[i][1] = rand() %100;
//         matrizdecomandos[i][2] = rand() %100;
//         matrizdecomandos[i][3] = rand() %100;
//     }
//     matrizdecomandos[99][0] = -1;
//     matrizdecomandos[99][1] = -1;
//     matrizdecomandos[99][2] = -1;
//     matrizdecomandos[99][3] = -1;

//     maquinaintmult(matrizdecomandos,dados);
// }

// void maquinamult(int *matrizdedados){
//     montacomandosmult(matrizdedados);
// }


/*
 00 01 02 03
 10 11 12 13
 20 21 22 23
*/
int main (){
    //gerando uma semente
    srand(time(NULL));

    //montando o vetor com os dados
    int matrizdedados[1000];
    montadados(matrizdedados);
    // montacomandos(matrizdedados);
    maquinamult(3,4,matrizdedados);
    return 0;
}