#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

struct sudoku{
    TCelula** celulas;
    TRegiao** regiao;
    int vazias;
    int situacao;
};

struct regiao{
    int regiao;
    TCelula** celulasRegiao;
};

struct celula{
    int linha;
    int coluna;
    int valor;
    int* possiveis;
    int regiao;
};



void AlocarRegiao(TRegiao **regiao){
    TRegiao* aux;

    aux = (TRegiao*)malloc(sizeof(TRegiao));
    if(aux == NULL){
        exit(EXIT_FAILURE);
    }

    aux->celulasRegiao = (TCelula**)calloc(3, sizeof(TCelula*));
    if(aux->celulasRegiao == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 3; i++){
        aux->celulasRegiao[i] = (TCelula*)calloc(3, sizeof(TCelula));
        if(aux->celulasRegiao[i] == NULL){
            exit(EXIT_FAILURE);
        }
    }

    *regiao = aux;
}

void AlocarSudoku(TSudoku **sudoku){
    TSudoku *aux;
    
    aux = (TSudoku*)malloc(sizeof(TSudoku));
    if(aux == NULL){
        exit(EXIT_FAILURE);
    }

    aux->regiao = (TRegiao**)malloc(9 * sizeof(TRegiao*));
    if(aux->regiao == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 9; i++){
        AlocarRegiao(aux->regiao + i);
    }
        
    aux->celulas = (TCelula**)calloc(9, sizeof(TCelula*));
    if(aux->celulas == NULL){
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < 9; i++){
        aux->celulas[i] = (TCelula*)calloc(9, sizeof(TCelula));
        if(aux->celulas[i] == NULL){
            exit(EXIT_FAILURE);
        }
    }

    *sudoku = aux;

}

void DesalocarRegiao(TRegiao **regiao){
    TRegiao* aux;
    aux = *regiao;

    for(int i = 0; i < 3; i++){
        free(aux->celulasRegiao[i]);
    }
    free(aux->celulasRegiao);

    free(aux);
    *regiao = NULL;

}

void DesalocarSudoku(TSudoku **sudoku){
    TSudoku *aux;
    aux = *sudoku;

    for(int i = 0; i < 9; i++){
        free(aux->celulas[i]);
    }
    free(aux->celulas);

    for(int i = 0; i < 9; i++){
        DesalocarRegiao(&aux->regiao[i]);
    }

    free(aux->regiao);
    free(aux);
    *sudoku = NULL;
}

void TabuleiroInicializa(char *arquivo, TSudoku *sudoku){

    //Inicializando o arquivo
    FILE* arq = fopen(arquivo, "r");
    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo!!\n");
        exit(EXIT_FAILURE);
    }

    //Preenchendo o sudoku a partir do arquivo
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            fscanf(arq, "%d", &sudoku->celulas[i][j].valor);
            sudoku->celulas[i][j].linha = i;
            sudoku->celulas[i][j].coluna = j;

        }
    }
    
    //Separando em regiões as celulas do sudoku para auxiliar na apuração no futuro
    //A ideia desses for é colocar em 9 matrizes 3x3 cada região do sudoku
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(i < 3 && j < 3){
                sudoku->celulas[i][j].regiao = 1;
                sudoku->regiao[0]->regiao = 1;
                sudoku->regiao[0]->celulasRegiao[i][j] =  sudoku->celulas[i][j];
            }
            else if(j >= 3 && j < 6 && i < 3){
                sudoku->celulas[i][j].regiao = 2;
                sudoku->regiao[1]->regiao = 2;
                sudoku->regiao[1]->celulasRegiao[i][j-3] =  sudoku->celulas[i][j];
            }
            else if(j >= 6 && j < 9 && i < 3){
                sudoku->celulas[i][j].regiao = 3;
                sudoku->regiao[2]->regiao = 3;
                sudoku->regiao[2]->celulasRegiao[i][j-6] =  sudoku->celulas[i][j];
            }

            else if(j < 3 && i >= 3 && i < 6){
                sudoku->celulas[i][j].regiao = 4;
                sudoku->regiao[3]->regiao = 4;
                sudoku->regiao[3]->celulasRegiao[i-3][j] =  sudoku->celulas[i][j];
            }

            else if(j >= 3 && j < 6 && i >= 3 && i < 6){
                sudoku->celulas[i][j].regiao = 5;
                sudoku->regiao[4]->regiao = 5;
                sudoku->regiao[4]->celulasRegiao[i-3][j-3] =  sudoku->celulas[i][j];
            }

            else if(j >= 6 && j < 9 && i >= 3 && i < 6){
                sudoku->regiao[5]->regiao = 6;
                sudoku->regiao[5]->celulasRegiao[i-3][j-6] =  sudoku->celulas[i][j];
                sudoku->celulas[i][j].regiao = 6;
            }

            else if(j < 3 && i >= 6 && i < 9){
                sudoku->regiao[6]->regiao = 7;
                sudoku->regiao[6]->celulasRegiao[i-6][j] =  sudoku->celulas[i][j];
                sudoku->celulas[i][j].regiao = 7;        
            }

            else if(j >= 3 && j < 6 && i >= 6 && i < 9){
                sudoku->regiao[7]->regiao = 8;
                sudoku->regiao[7]->celulasRegiao[i-6][j-3] =  sudoku->celulas[i][j];
                sudoku->celulas[i][j].regiao = 8;
            }

            else if(j >= 6 && j < 9 && i >= 6 && i < 9){
                sudoku->regiao[8]->regiao = 9;
                sudoku->regiao[8]->celulasRegiao[i-6][j-6] =  sudoku->celulas[i][j];
                sudoku->celulas[i][j].regiao = 9;
            }
        }
    }

    fclose(arq);
}

TCelula* defineVazias(TSudoku *tabuleiro){
    TCelula* aux;
    int n = 1;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tabuleiro->celulas[i][j].valor == 0){
                n++;
            }
        }    
    }

    tabuleiro->vazias = n-1;
    aux = calloc(n, sizeof(TCelula));
    aux[0].valor = -1;
    n = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tabuleiro->celulas[i][j].valor == 0){
                aux[n] = tabuleiro->celulas[i][j];
                n++;
            }
        }    
    }

    return aux;

}

int EhValido(TSudoku *tabuleiro){

    int flag = 0;
    //Verifica inconsistências nas linhas
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 8; j++){
            for(int k = j+1; k < 9; k++){
                if(tabuleiro->celulas[i][j].valor == tabuleiro->celulas[i][k].valor && tabuleiro->celulas[i][j].valor != 0){
                    if(flag == 0){
                        printf("Alguma coisa deu errado... Invalidos:\n");
                        flag++;
                    }

                    printf("Linha %d: (%d,%d) e (%d,%d)\n", i+1, i+1, j+1, i+1, k+1);
                }
                
            }
        }
    }
    //Verifica inconsistências nas colunas
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 9; j++){
            for(int k = i+1; k < 9; k++){
                if(tabuleiro->celulas[i][j].valor == tabuleiro->celulas[k][j].valor && tabuleiro->celulas[i][j].valor != 0){
                    if(flag == 0){
                        printf("Alguma coisa deu errado... Invalidos:\n");
                        flag++;
                    }

                    printf("Coluna %d: (%d,%d) e (%d,%d)\n", j+1, i+1, j+1, k+1, j+1);
                }
                
            }
        }
    }
    //Verifica inconsistências nas regiões
    for(int i = 0; i < 9; i++){
        //Em cada região irei verificar as linhas e colunas
        //Verificando linhas

        int aux[9], count = 0;
        //Calculo para ajustar a posição de cada região no tabuleiro, isso é necessário porque eu converti as regiões em pequenas matrizes de 3x3      
        int linha = ((i/3)*3)+1;
        int coluna = ((i%3)*3)+1;

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                aux[count] = tabuleiro->regiao[i]->celulasRegiao[j][k].valor;
                count++;
            }
        }

        count = 0;
        for(int j = 0; j < 8; j++){
            for(int k = j + 1; k < 9; k++){
                if(aux[j] == aux[k] && aux[j] != 0){
                    if(flag == 0){
                        printf("Alguma coisa deu errado... Invalidos:\n");
                        flag++;
                    }
                    printf("Regiao %d: (%d,%d) e (%d,%d)\n", i+1, (j/3)+linha, (j%3)+coluna, (k/3)+linha, (k%3)+coluna);                
                }  
            } 
        }
    }

    if(flag == 0){
        return 0;
    }
    else {
        return 1;
    }
}

int* valoresValidos(TSudoku *tabuleiro, TCelula celula){
    int *valores = (int*)calloc(9, sizeof(int));
    
    //Verifica possibilidades nas linhas
    for(int j = 0; j < 9; j++){
        // for(int k = 1; k <= 9; k++){
        //     if(k == tabuleiro->celulas[celula.linha][j].valor){
        //         valores[k]++;
                
        //         printf("%d\n", celula.valor);
        //     }
        // }    

        if(tabuleiro->celulas[celula.linha][j].valor != 0){
            valores[tabuleiro->celulas[celula.linha][j].valor-1]++;
        }
    }
    
    //Verifica possibilidades nas colunas
    for(int j = 0; j < 9; j++){
        // for(int k = 1; k <= 9; k++){
        //     if(k == tabuleiro->celulas[j][celula.coluna].valor){
        //         valores[celula.valor-1]++;
        //     }
        // }
        if(tabuleiro->celulas[j][celula.coluna].valor != 0){
            valores[tabuleiro->celulas[j][celula.coluna].valor-1]++;
        }
    }

    //verifica a regiao
    for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
            for(int l = 1; l <= 9; l++){
                if(l == tabuleiro->regiao[celula.regiao-1]->celulasRegiao[j][k].valor){
                    valores[l-1]++;
                } 
            }  
        }
    }
    return valores;
}

int situacaoSudoku(TSudoku *tabuleiro, TCelula *vazias, int valido){
    int *validos;
    
    if(vazias[0].valor == -1 && valido == 0){
        printf("Jogo completo. Voce ganhou!\n");
        return 0;
    }
    else if(valido == 0){
        printf("Voce esta no caminho certo. Sugestoes:\n");
        for(int i = 0; i < tabuleiro->vazias; i++){
            validos = valoresValidos(tabuleiro, vazias[i]);
            if(validos == NULL){
                exit(EXIT_FAILURE);
            }
            printf("(%d,%d):", vazias[i].linha + 1, vazias[i].coluna + 1);
            
            for(int j = 0; j <9; j++){
                if(validos[j] == 0){
                    printf("%d ", j+1);
                }
            }
            printf("\n");
            free(validos);
            validos = NULL;
        }
    }

    return 1;
}