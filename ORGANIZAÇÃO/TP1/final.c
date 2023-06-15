//Caio Silas 
//21.1.4111

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void montaRam(int *memoriaDados){
    

    for(int i  = 0; i < 1000; i++){
        memoriaDados[i] = rand() % 100;
    }
}

void maquinaInterpretada(int *umaInstrucao, int *memoriaDados){
    int opcode = umaInstrucao[0];
    int end1, end2, conteudoRam1, conteudoRam2, soma = 0, sub = 0, end3, conteudo, end;

    switch(opcode){
        //somar
        case 0:
            
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];
            //buscando os valores
            conteudoRam1 = memoriaDados[end1];
            conteudoRam2 = memoriaDados[end2];
            //somando os valores
            soma = conteudoRam1 + conteudoRam2;
            //salvando o resultado
            end3 = umaInstrucao[3];
            memoriaDados[end3] = soma;

            printf("Somando %d + %d = %d\n", conteudoRam1, conteudoRam2, soma);
            break;

        //subtrair
        case 1:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];
            //buscando os valores
            conteudoRam1 = memoriaDados[end1];
            conteudoRam2 = memoriaDados[end2];
            //subtraindo os valores
            sub = conteudoRam1 - conteudoRam2;
            //salvando os valores
            end3 = umaInstrucao[3];
            memoriaDados[end3] = sub;

            printf("Substraindo %d - %d = %d\n", conteudoRam1, conteudoRam2, sub);
            break;
        
        //levar para a memoria
        case 2:
            conteudo = umaInstrucao[1]; 
            end = umaInstrucao[2];
            memoriaDados[end] = conteudo;
            break;
        
        //trazer da memoria
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

void montarMultiplicacao(int multiplicando, int multiplicador,int *memoriadados){

    int memoriacomando[100][4];

    //levando para memoria
    memoriacomando[0][0] = 2;
    memoriacomando[0][1] = 0;
    memoriacomando[0][2] = 1;
    memoriacomando[0][3] = -1;

    //levar para memoria
    memoriacomando[1][0] = 2;
    memoriacomando[1][1] = multiplicando;
    memoriacomando[1][2] = 0;
    memoriacomando[1][3] = -1;


    
    for (int i = 2; i <= multiplicador + 2;i++){
        memoriacomando[i][0] = 0;
        memoriacomando[i][1] = 0;
        memoriacomando[i][2] = 1;
        memoriacomando[i][3] = 1;
    }


    memoriacomando[multiplicador + 2][0] = -1;
    memoriacomando[multiplicador + 2][1] = -1;
    memoriacomando[multiplicador + 2][2] = -1;
    memoriacomando[multiplicador + 2][3] = -1;
    
    maquina(memoriacomando,memoriadados);

    //trazendo da memoria o resultado
    int umainstrucao[4];
    umainstrucao[0] = 3;
    umainstrucao[1] = -1;
    umainstrucao[2] = 1;
    umainstrucao[3] = -1;
    maquinaInterpretada(umainstrucao,memoriadados);

    printf("multiplicando : %d * %d = %d\n",multiplicando,multiplicador,umainstrucao[1]);
    
}

void montarDivisao(int dividendo, int divisor,int *memoriadados){

    
    int memoriacomando[1000][4];

    // memoriadados [0] = divisor; //5
    // memoriadados [1] = dividendo; //30
    int resultado = 0;
    int fim = 0;

    //levando para memoria
    memoriacomando[0][0] = 2;
    memoriacomando[0][1] = divisor;
    memoriacomando[0][2] = 0;
    memoriacomando[0][3] = -1;

    //levar para memoria
    memoriacomando[1][0] = 2;
    memoriacomando[1][1] = dividendo;
    memoriacomando[1][2] = 1;
    memoriacomando[1][3] = -1;

    memoriacomando[2][0] = 2;
    memoriacomando[2][1] = 1;
    memoriacomando[2][2] = 2;
    memoriacomando[2][3] = -1;

    memoriacomando[3][0] = 2;
    memoriacomando[3][1] = 0;
    memoriacomando[3][2] = 3;
    memoriacomando[3][3] = -1;

    // maquina(memoriacomando,memoriadados);
    
    memoriacomando[99][0] = -1;
    memoriacomando[99][1] = -1;
    memoriacomando[99][2] = -1;
    memoriacomando[99][3] = -1;


    for (int i = 4; i < dividendo + 4;i++){
        //caso nao seja possivel fazer a divisao
        if (divisor > dividendo){
            int umainstrucao1[4];
            umainstrucao1[0] = 2;
            umainstrucao1[1] = 0;
            umainstrucao1[2] = 1;
            umainstrucao1[3] = -1;
            maquinaInterpretada(umainstrucao1,memoriadados);
            break;
        }

        memoriacomando[i][0] = 1;
        memoriacomando[i][1] = 1;
        memoriacomando[i][2] = 0;
        memoriacomando[i][3] = 1;
        resultado++;
        maquina(memoriacomando,memoriadados);
        

        //trazendo o resultado da memoria para comparação
        int umainstrucao[4];
        umainstrucao[0] = 3;
        umainstrucao[1] = -1;
        umainstrucao[2] = 1;
        umainstrucao[3] = -1;
        maquinaInterpretada(umainstrucao,memoriadados);

        fim = umainstrucao[1];
        //se fim <= 0 quer dizer que a divisao chegou ao final
        if(fim <= divisor && fim == 0){
            break;
        }
    }


    //levando para a memoria
    int umainstrucao1[4];
    umainstrucao1[0] = 2;
    umainstrucao1[1] = resultado;
    umainstrucao1[2] = 1;
    umainstrucao1[3] = -1;
    maquinaInterpretada(umainstrucao1,memoriadados);

    //trazendo da memoria o resultado
    int umainstrucao[4];
    umainstrucao[0] = 3;
    umainstrucao[1] = -1;
    umainstrucao[2] = 1;
    umainstrucao[3] = -1;
    maquinaInterpretada(umainstrucao,memoriadados);
    printf("dividindo : %d : %d = %d\n",dividendo,divisor,umainstrucao[1]);
    
}

void montarPotencia(int base,int expoente, int *memoriadados){

    int resultado = base;

    for (int i = 0; i < expoente - 1; i++)
    {
        montarMultiplicacao(resultado,base,memoriadados);

        //levando para memoria
        int umainstrucao[4];
        umainstrucao[0] = 3;
        umainstrucao[1] = -1;
        umainstrucao[2] = 1;
        umainstrucao[3] = -1;
        maquinaInterpretada(umainstrucao,memoriadados);
        resultado = umainstrucao[1];
    }

    //trazendo da memoria
    int umainstrucao[4];
    umainstrucao[0] = 3;
    umainstrucao[1] = -1;
    umainstrucao[2] = 1;
    umainstrucao[3] = -1;
    maquinaInterpretada(umainstrucao,memoriadados);

    printf("elevando : %d ^ %d = %d\n",base,expoente,umainstrucao[1]);
}

void montarRaiz(int radiano, int *memoriadados){
    int achou = 0;

    for (int i = 0; i < radiano;i++){
        montarMultiplicacao(i,i,memoriadados);
        if (memoriadados[1] == radiano){
            achou = 1;
            //levando para a memoria o resultado
            int umainstrucao[4];
            umainstrucao[0] = 2;
            umainstrucao[1] = i;
            umainstrucao[2] = 1;
            umainstrucao[3] = -1;
            maquinaInterpretada(umainstrucao,memoriadados);
            break;
        }
    }
    if (achou == 0){
        printf("O NUMERO :%d NAO POSSUI RAIZ NOS REAIS\n",radiano);
    }
    else{
        //trazendo da memoria o resultado
        int umainstrucao[4];
        umainstrucao[0] = 3;
        umainstrucao[1] = -1;
        umainstrucao[2] = 1;
        umainstrucao[3] = -1;
        maquinaInterpretada(umainstrucao,memoriadados);
        printf("raiz : %d = %d\n",radiano,umainstrucao[1]); 
    }
    
}


int main (){
    srand(time(NULL));
    int memoriaDados[1000];
    montaRam(memoriaDados);

    // montarInstrucoesProgramaAleatorio(memoriaDados);
    // montarMultiplicacao(10,20,memoriaDados);
    // montarDivisao(200,10,memoriaDados);
    // montarPotencia(2,5,memoriaDados);
    // montarRaiz(15,memoriaDados);
    
    return 0;
}