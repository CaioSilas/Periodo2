# ifndef avl_h
# define avl_h

typedef char TChave[200];

typedef struct {
  TChave chave;
} TItem;

typedef struct No {
  TItem item;
  struct No* pEsq;
  struct No* pDir;
} TNo;

typedef TNo* TAVL;

//definição da enum
typedef enum resposta {
  PRIMEIRO_MENOR=1,
  PRIMEIRO_MAIOR,
  IGUAIS
} ENUM_RESPOSTA;

//Manter como especificado
void TAVLInicia(TNo**);

//Definir de acordo com o metodo escolhido para insercao na arvore
int TAVLInsere(TNo**, TItem*);

//Manter como especificado
TNo *TNoCria(TItem);

//Manter como especificado
ENUM_RESPOSTA compara(const TItem, const TItem);

//Manter como especificado
int TAVLFB(TNo*);

//Manter como especificado
int TAVLAltura(TNo*);

// Realizar o caminhamento adequado na arvore
// PREENCHER AQUI

// Funções para rotação da árvore AVL
// Manter como especificado todas as funções abaixo
void TAVLRSE(TNo**);
void TAVLRSD(TNo**);
int TAVLBalancaEsquerda(TNo**);
int TAVLBalancaDireita(TNo**);
int TAVLBalanceamento(TNo**);
void Central ( TNo *p );
void PosOrdem ( TNo *p);
void PreOrdem ( TNo *p);

# endif
