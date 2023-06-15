# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[20];
} TipoAluno;


//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n);
//função para preecher o vetor
void preeche(TipoAluno *alunos,int n);
//Manter como especificado
void ordena(TipoAluno *alunos, int n);
//função que retorna 2 caso y for maior que x
int compara(TipoAluno x, TipoAluno y);
//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos);
# endif
