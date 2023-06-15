//Caio silas - Matricula : 21.1.4111
//Henrique Dantas - Matricula : 21.1.4025
//Turmas 21-22


#ifndef FUNCOES_H
#define FUNCOES_H
//Struct do sudoku
typedef struct sudoku TSudoku;
//Struct de cada região do sudoku
typedef struct regiao TRegiao;
//Struct de cada celula do sudoku
typedef struct celula TCelula;

//Função para inicializar o tabuleiro
void TabuleiroInicializa(char *arquivo, TSudoku *sudoku);
//Função para definir as celular vazias
TCelula* defineVazias(TSudoku *tabuleiro);
//Função para validar o sudoku
int EhValido(TSudoku *tabuleiro);
//Função para validar os valores possiveis de cada celula
int* valoresValidos(TSudoku *tabuleiro, TCelula celula);
//Função para averiguar a situação do sudoku
int situacaoSudoku(TSudoku *tabuleiro, TCelula *vazias, int valido); 


//Função para alocar o Sudoku
void AlocarSudoku(TSudoku **sudoku);
//Função para alocar a Região
void AlocarRegiao(TRegiao **regiao);
//Função para desalocar a região
void DesalocarRegiao(TRegiao **regiao);
//Função para desalocar o Sudoku
void DesalocarSudoku(TSudoku **sudoku);




#endif // FUNCOES_H