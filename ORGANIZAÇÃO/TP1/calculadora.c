// caio silas de araujo amaro
// 21.1.4111

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int **criaMatrizR(int linha, int coluna)
{
    int **matriz;
    matriz = calloc(linha, sizeof(int *));
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = calloc(coluna, sizeof(int));
    }

    if (matriz == NULL)
    {
        printf("matriz errro");
        exit(1);
    }
    return matriz;
}

void desaloca_matriz(int **A, int linha)
{
    for (int i = 0; i < linha; i++)
    {
        free(A[i]);
    }
    free(A);
}

typedef struct
{
    int operador;
    int primeiro;
    int segundo;
    int resultado;
} Memoria;

int main()
{
    // declarando o tamanho da matriz
    int linha, coluna;
    linha = 100;
    coluna = 4;

    // criando a matriz
    int **Calculador = criaMatrizR(linha, coluna);

    // completando a matriz
    srand(time(NULL));
    int i, l;
    for (i = 0; i < linha; i++)
    {
        for (l = 0; l < coluna; l++)
        {
            Calculador[i][l] = rand() % 100;
        }
    }

    Memoria *RAM = calloc(100, sizeof(Memoria));
    int opcode = 0;

    // criando os comandos
    while (opcode != -1)
    {
        int k;
        for (k = 0; k < 100; k++)
        {
            RAM[k].operador = rand() % 2;
            switch (RAM[k].operador)
            {
            case 1:
                RAM[k].primeiro = rand() % 100;
                RAM[k].segundo = rand() % 100;
                break;

            case 2:
                RAM[k].primeiro = rand() % 100;
                RAM[k].segundo = rand() % 100;
                break;
            }
            printf("%d\n", RAM[k].primeiro);
        }
        if (k == 5)
        {
            opcode = -1;
        }
    }

    // for(i = 0; i < linha;i++){
    //     for (l = 0; l < coluna;l++){
    //         printf("%d ",Calculador[i][l]);
    //     }
    //     printf("\n");
    // }

    printf("fim");

    return 0;
}