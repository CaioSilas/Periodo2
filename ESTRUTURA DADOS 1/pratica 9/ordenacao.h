# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[20];
} TipoAluno;


//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *aluno, int n);

//Manter como especificado
void desalocaAlunos(TipoAluno **alunos);

//Manter como especificado
void heapsort(TipoAluno*v, int n);

void heapcontroi(TipoAluno* v,int n);

void heapRefaz(TipoAluno *v,int esq,int dir);
# endif
