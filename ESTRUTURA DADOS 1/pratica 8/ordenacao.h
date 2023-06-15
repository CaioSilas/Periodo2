# ifndef ordenacao_h
# define ordenacao_h

#include "lista.h"

// Manter como especificado
void ordena(TLista *l, int n);

/* Manter como especificado
 * Retorna:
 *      -1 se o primeiro TItem for menor que o segundo
 *       0 se ambos forem iguais
 *       1 se o primeiro TItem for maior que o segundo
 */
int compare(const TAluno, const TAluno);

# endif
