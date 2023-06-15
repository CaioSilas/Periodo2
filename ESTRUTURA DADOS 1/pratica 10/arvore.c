#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void TArvore_Inicia ( TNo **pRaiz ) {
    *pRaiz = NULL ;
}

// Manter como especificado
int TArvore_Insere ( TNo ** ppR , TItem x) {
    if (* ppR == NULL ) {
        *ppR = TNo_Cria (x);
        return 1;
    }
    if (compara(x,(* ppR )->item) == PRIMEIRO_MENOR )
        return TArvore_Insere (&((* ppR ) -> pEsq ) , x);
    if (compara(x,(* ppR )->item) == PRIMEIRO_MAIOR )
        return TArvore_Insere (&((* ppR ) -> pDir ) , x);

    return 0;
}

// Manter como especificado
TNo * TNo_Cria ( TItem x) {
    TNo * pAux = ( TNo *) malloc ( sizeof ( TNo ));
    pAux -> item = x;
    pAux -> pEsq = NULL ;
    pAux -> pDir = NULL ;
    return pAux ;
}

// Realizar o caminhamento adequado na arvore
void Central ( TNo *p ) {
    if (p == NULL )
        return ;
    Central (p->pEsq ) ;
    printf ("%s\n", p->item.chave ) ;
    Central (p->pDir );
}
// PREENCHER AQUI

// Função para realizar a comparação entre dois itens
ENUM_RESPOSTA compara(const TItem item1, const TItem item2) {
  if (strcmp(item1.chave,item2.chave) > 0){
    return PRIMEIRO_MAIOR;
  }
  else if (strcmp(item1.chave,item2.chave) < 0){
    return PRIMEIRO_MENOR;
  }
  else{
    return IGUAIS;
  }
}

