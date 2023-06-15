# ifndef ordenacao_h
# define ordenacao_h

struct time {
    //preencher com os dados de cada time
    float time;
    float ponto;
    float CestasFeitos;
    float CestasRecebidos;
    float saldo;
};

//Manter como especificado
void ordenacao(struct time *vetor, int n);
//Manter como especificado
struct time *alocaVetor(int n);
//Manter como especificado
void desalocaVetor(struct time **vetor);
//faz a comparacao utilizada para ordenar os times
int compare(struct time t1, struct time t2);
void merge(struct time *v,int l,int m, int r);

int mergeint(struct time *v, int l, int r,int n);
# endif
