#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# ifndef pesquisa_h
# define pesquisa_h

typedef long TChave ;

typedef struct {
/* outros componentes */
    TChave chave ;
} TItem ;

typedef struct No {
    TItem item ;
    struct No * pEsq , * pDir ;
} TNo ;
    
typedef TNo *TArvore ;


int TArvore_Pesquisa ( TArvore * pRaiz , TChave c , TItem * pX );

int TArvore_Insere ( TNo ** ppR , TItem x);

void TArvore_Insere_Raiz ( TNo ** ppRaiz , TItem x);

TNo * TNo_Cria ( TItem x);

void TArvore_Inicia ( TNo ** pRaiz );

int TArvore_Retira ( TNo **p , TItem x);

void TArvore_Sucessor ( TNo *q , TNo ** r);

void PreOrdem ( TNo * p);//menor

void PosOrdem ( TNo * p);//maior

void Central ( TNo *p );


#endif