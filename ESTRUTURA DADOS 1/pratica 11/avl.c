#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void TAVLInicia (TNo **pRaiz) {
  // PREENCHER AQUI
  *pRaiz = NULL;
}

// Manter como especificado
int TAVLInsere (TNo **ppRaiz, TItem *x) {
    // PREENCHER AQUI
    if (*ppRaiz ==  NULL){
      *ppRaiz = malloc(sizeof(TNo));
      (*ppRaiz)->item = *x;
      (*ppRaiz)->pEsq = NULL;
      (*ppRaiz)->pDir = NULL;
      return 1;
    }

    else if (compara((*x),(*ppRaiz)->item) == PRIMEIRO_MENOR){
      if (TAVLInsere(&(*ppRaiz)->pEsq,x)){
        if (TAVLBalanceamento(ppRaiz)){
          return 0;
        }
        else {
          return 1;
        }
      }
    }

    else if (compara((*x),(*ppRaiz)->item) == PRIMEIRO_MAIOR){
      if (TAVLInsere(&(*ppRaiz)->pDir,x)){
        if (TAVLBalanceamento(ppRaiz)){
          return 0;
        }
        else {
          return 1;
        }
      }
      else {
        return 0;
      }
    }
    return 0;
}

// Manter como especificado
TNo *TNoCria (TItem x) {
    // PREENCHER AQUI
    return malloc(sizeof(TNo));
}

// Realizar o caminhamento adequado na arvore
  // PREENCHER AQUI

ENUM_RESPOSTA compara(const TItem item1, const TItem item2) {
  // PREENCHER AQUI
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

int TAVLFB (TNo *pRaiz) {
  // PREENCHER AQUI
  if (pRaiz == NULL){
    return 0;
  }
  return TAVLAltura (pRaiz->pEsq) - TAVLAltura(pRaiz->pDir);
}

int TAVLAltura (TNo *pRaiz) {
  // PREENCHER AQUI
  int esq,dir;

  if (pRaiz == NULL){
    return 0;
  }
  esq = TAVLAltura (pRaiz->pEsq);
  dir = TAVLAltura (pRaiz->pDir);

  if ( esq > dir ){
    return esq + 1;
  }
  else {
    return dir + 1;
  }

}

// Funções para rotação da árvore AVL
// Manter como especificado todas as funções abaixo
void TAVLRSE (TNo **ppRaiz) {
  TNo * pAux;
  pAux = (*ppRaiz)->pDir;
  (*ppRaiz)->pDir = pAux->pEsq;
  pAux->pEsq = (*ppRaiz);
  (*ppRaiz) = pAux;
}

// Manter como especificado
void TAVLRSD (TNo **ppRaiz) {
  TNo * pAux;
  pAux = (*ppRaiz)->pEsq;
  (*ppRaiz)->pEsq = pAux->pDir;
  pAux->pDir = (*ppRaiz);
  (*ppRaiz) = pAux;
}

// Manter como especificado
int TAVLBalancaEsquerda (TNo **ppRaiz) {
  int fbe = TAVLFB((*ppRaiz)->pEsq);
  if ( fbe >= 0 ) {
    TAVLRSD ( ppRaiz ) ;
    return 1;
  } else {
    /* Rotação Dupla Direita */
    TAVLRSE (&((*ppRaiz)->pEsq) );
    TAVLRSD (ppRaiz) ;
    return 1;
  }
}

// Manter como especificado
int TAVLBalancaDireita (TNo **ppRaiz) {
  int fbd = TAVLFB((*ppRaiz)-> pDir);
  if (fbd <= 0) {
    TAVLRSE(ppRaiz );
    return 1;
  } else {
    /* Rotação Dupla Esquerda */
    TAVLRSD (&((*ppRaiz)->pDir) );
    TAVLRSE (ppRaiz) ;
    return 1;
  }
 return 0;
}

// Manter como especificado
int TAVLBalanceamento (TNo ** ppRaiz) {
  int fb = TAVLFB (*ppRaiz);
  if ( fb > 1)
    return TAVLBalancaEsquerda (ppRaiz) ;
  else if ( fb < -1 )
    return TAVLBalancaDireita (ppRaiz);
  else
    return 0;
}

void Central ( TNo *p ) {
    if (p == NULL )
        return ;
    Central (p->pEsq ) ;
    printf ("%s\n", p->item.chave ) ;
    Central (p->pDir );
}

void PosOrdem ( TNo * p) {
    if (p == NULL )
        return ;
    PosOrdem (p->pEsq );
    PosOrdem (p->pDir );
    printf ("%s\n", p->item.chave ) ;
}

void PreOrdem ( TNo * p) {
    if (p == NULL )
        return ;
    printf ("%s\n", p->item.chave ) ;
    PreOrdem (p -> pEsq );
    PreOrdem (p -> pDir );
}
