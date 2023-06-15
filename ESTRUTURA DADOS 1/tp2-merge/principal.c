//Caio silas - Matricula : 21.1.4111
//Turmas 21-22


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"


int main(){
    int qnt;
    //lendo a quantidade de upas que serao alocadas
    scanf("%d",&qnt);
    Tupa *upa = NULL;
    //alocando a struct de upa
    alocaUpa(&upa,qnt);
    //preenchendo a struct
    Completaupa(&upa,qnt);
    // ordenando a struct
    mergeint(&upa,0,qnt,qnt);
    //printando apos ter feito a ordenacao e colocado por ordem de preferencia
    printupa(&upa,qnt);
    //liberando a struct que foi alocada
    free(upa);
    return 0;
}