# ifndef duende_h
# define duende_h

//COMPLETAR O NOME DA ESTRUTURA
typedef struct duende TADduende;
//COMPLETAR O NOME DA ESTRUTURA
typedef struct time TADtime;
//Manter como especificado
void lerQuantidade(int *qtd);
//Manter como especificado
TADduende *alocaDuendes(int qtd);
//Manter como especificado
TADtime *alocaTimes(int qtd);
//Manter como especificado
void desalocaDuendes(TADduende **D);
//Manter como especificado
void desalocaTimes(TADtime **T);
//Manter como especificado
void lerDuendes(TADduende *D, int qtd);
//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd);
//Manter como especificado
int proximoMaisVelho(TADduende *D, int qtd);
//Manter como especificado
void printTimes(TADtime *T, int qtd);
# endif
