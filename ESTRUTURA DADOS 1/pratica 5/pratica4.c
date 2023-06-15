#include "pilha.h"
#include <stdio.h>

int main() {
    char ch;
    TItem item;
    TPilha pilha;

    TPilhaInicia(&pilha);

    while (scanf("%c", &ch)!=EOF) {
        if(ch == '\n')
            break;
        //processar cada elemento lido
        if (ch == '('){
            TPilhaPush(&pilha, item);
        }
        else if (ch ==')'){
            if (TPilhaEhVazia(&pilha) == 1){
                TPilhaPush(&pilha,'(');
                break;
            }
            else {
                TPilhaPop(&pilha,&item);
            }
        }
    }
    //determinar o resultado
    if (TPilhaEhVazia(&pilha) == 1){
        printf("correto\n");
    }
    else if (TPilhaEhVazia(&pilha) == 0) {
        printf("incorreto\n");
    }

    TPilhaEsvazia(&pilha);

    return 0;//nao remova
}
