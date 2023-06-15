#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main (int argc, char** argv){
    
    TSudoku *sudoku;
    AlocarSudoku(&sudoku);
    
    TabuleiroInicializa(argv[1], sudoku);

    TCelula *vazias = defineVazias(sudoku);
    int valido = EhValido(sudoku);
    
    if(valido == 1){
        free(vazias);
        DesalocarSudoku(&sudoku);
        return 1;
    }

    int situacao = situacaoSudoku(sudoku, vazias, valido);    
    free(vazias);
    DesalocarSudoku(&sudoku);
    return situacao;
}