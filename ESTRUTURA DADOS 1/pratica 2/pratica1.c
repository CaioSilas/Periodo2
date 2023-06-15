#include "aluno.h"


int main() {
    char option;
    int qtd;
    float resultado;

    TTurma *pTurma;

    lerInfos(&qtd,&option);

    alocaTurma(&pTurma, qtd);

    lerTurma(pTurma);
    

    resultado = calcularMetrica(pTurma, "computacao", option);
    printMetrica("computacao", resultado, option);

    resultado = calcularMetrica(pTurma, "direito", option);
    printMetrica("direito", resultado, option);

    resultado = calcularMetrica(pTurma, "nutricao", option);
    printMetrica("nutricao", resultado, option);
    

    return 0;
}