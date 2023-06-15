#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

int TArvore_Pesquisa (TArvore *pRaiz , TChave c , TItem *pX ) {
    if ( pRaiz == NULL )
        return 0;

    if (c < (*pRaiz)->item.chave)
        return TArvore_Pesquisa ( &((*pRaiz)->pEsq) , c , pX );
    if (c > (*pRaiz)->item.chave)
        return TArvore_Pesquisa ( &((*pRaiz)->pDir) , c , pX );

    *pX = (*pRaiz)->item ;
    return 1;
}

// int TArvore_Pesquisa (TArvore *pRaiz , TChave c , TItem *pX ) {
//     TNo *pAux;
//     pAux = pRaiz;

//     while ( pAux != NULL ) {
//         if (c == pAux->item.chave) {
//             *pX = pAux->item;
//             return 1;
//         }
//         else if ( c > pAux-> item.chave)
//             pAux = pAux->pDir;
//         else
//             pAux = pAux->pEsq;
//         }
    
//     return 0; // não encontrado !
// }

int TArvore_Insere ( TNo ** ppR , TItem x) {
    if (* ppR == NULL ) {
        *ppR = TNo_Cria (x);
        return 1;
    }

    if (x.chave < (* ppR )->item.chave )
        return TArvore_Insere (&((* ppR ) -> pEsq ) , x);
    if (x.chave > (* ppR )->item.chave )
        return TArvore_Insere (&((* ppR ) -> pDir ) , x);

    return 0; // elemento jah existe
}

// int TArvore_Insere ( TNo * pRaiz , TItem x) {
//     if ( pRaiz == NULL ) return -1; // arvore vazia

//     if (x . chave < pRaiz -> item . chave ) {
//         if ( pRaiz->pEsq == NULL ) {
//         pRaiz->pEsq = TNo_Cria ( x);
//         return 1;
//         }
//         return TArvore_Insere ( pRaiz -> pEsq , x);
//     }

//     if (x . chave > pRaiz -> item . chave ) {
//         if ( pRaiz->pDir == NULL ) {
//             pRaiz->pDir = TNo_Cria ( x);
//             return 1;
//         }
//         return TArvore_Insere ( pRaiz -> pDir , x);
//     }
//     return 0; // elemento jah existe
// }

// void TArvore_Insere_Raiz ( TNo ** ppRaiz , TItem x) {
//     if (*ppRaiz == NULL ) {
//     *ppRaiz = TNo_Cria (x );
//     }
//     TArvore_Insere (*ppRaiz , x);
// }

// int TArvore_Insere ( TNo ** ppRaiz , TItem x) {
//     TNo ** ppAux ;
//     ppAux = ppRaiz ;

//     while (* ppAux != NULL ) {
//         if (x . chave < (* ppAux ) -> item . chave )
//             ppAux = &((* ppAux ) -> pEsq );
//         else if ( x. chave > (* ppAux ) -> item . chave )
//             ppAux = &((* ppAux ) -> pDir );
//         else
//         return 0;
//     }
//     *ppAux = TNo_Cria (x );
//     return 1;
// }

TNo * TNo_Cria ( TItem x) {
    TNo * pAux = ( TNo *) malloc ( sizeof ( TNo ));
    pAux -> item = x;
    pAux -> pEsq = NULL ;
    pAux -> pDir = NULL ;
    return pAux ;
}

void TArvore_Inicia ( TNo ** pRaiz ) {
    *pRaiz = NULL ;
}

int TArvore_Retira ( TNo **p , TItem x)
{
    TNo * pAux ;
    if (* p == NULL )
        return 0;

    if (x . chave < (* p ) -> item . chave )
        return TArvore_Retira (&((* p) -> pEsq ) , x );
    if (x . chave > (* p ) -> item . chave )
        return TArvore_Retira (&((* p) -> pDir ) , x );

    if ((* p) -> pEsq == NULL && (* p) -> pDir == NULL ) { // no eh folha
        free (* p );
        *p = NULL ;
    }
    return 1;


    if ((* p) -> pEsq != NULL && (* p) -> pDir == NULL ) { // esq
        pAux = *p ;
        *p = (* p) -> pEsq ;
        free ( pAux );
        return 1;
    }

    if ((* p) -> pDir != NULL && (* p) -> pEsq == NULL ) { // dir
        pAux = *p ;
        *p = (* p) -> pDir ;
        free ( pAux );
        return 1;
    }

    // no possui dois filhos
    TArvore_Sucessor (*p , &((* p) -> pDir ) );
    // equivalente a TArvore_Antecessor (*p, &((* p) ->pEsq ));
    return 1;
}

//para esquerda
void PreOrdem ( TNo * p) {
    if (p == NULL )
        return ;
    printf ("%ld\n", p->item.chave ) ;
    PreOrdem (p -> pEsq );
    PreOrdem (p -> pDir );
}

//para direita
void PosOrdem ( TNo * p) {
    if (p == NULL )
        return ;
    PosOrdem (p->pEsq );
    PosOrdem (p->pDir );
    printf ("%ld\n", p->item.chave ) ;
}

//pelo centro
void Central ( TNo *p ) {
    if (p == NULL )
        return ;
    Central (p->pEsq ) ;
    printf ("%ld\n", p->item.chave ) ;
    Central (p->pDir );
}


int main (){
    TArvore arvore;
    TItem item;

    TArvore_Inicia(&arvore);
    item.chave = 7;
    TArvore_Insere(&arvore,item);
    item.chave = 3;
    TArvore_Insere(&arvore,item);
    item.chave = 9;
    TArvore_Insere(&arvore,item);

    Central(arvore);


    return 0;
}