# ifndef arvore_h
# define arvore_h

typedef char TChave[200];

typedef struct {
  TChave chave;
} TItem;

typedef struct No {
  TItem item;
  struct No *pEsq,*pDir;
  
} TNo;

typedef TNo *TArvore;

// Definição da enum para as respostas da função de comparação
typedef enum resposta {
  PRIMEIRO_MENOR = 1,
  PRIMEIRO_MAIOR,
  IGUAIS
} ENUM_RESPOSTA;


// Manter como especificado
void TArvore_Inicia (TNo **pRaiz);

// Definir de acordo com o metodo escolhido para insercao na arvore
int TArvore_Insere (TNo ** ppR , TItem x);

// Manter como especificado
TNo *TNo_Cria (TItem x);

// Realizar o caminhamento adequado na arvore
void Central ( TNo *p );
// PREENCHER AQUI

// Função para realizar a comparação entre dois itens
ENUM_RESPOSTA compara(const TItem, const TItem);

# endif
