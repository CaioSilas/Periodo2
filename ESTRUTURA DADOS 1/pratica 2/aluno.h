#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno TAluno;

typedef struct turma TTurma;

// Manter como especificado
void lerInfos(int*, char*);

// Manter como especificado
void alocaAluno(TAluno**);

// Manter como especificado
void alocaTurma(TTurma**, int);

// Manter como especificado
void desalocaAluno(TAluno**);

// Manter como especificado
void desalocaTurma(TTurma**);

// Manter como especificado
void lerTurma(TTurma*);

// Manter como especificado
float calcularMetrica(TTurma*, char*, char);

// Manter como especificado
void printMetrica(char*, float, char);

#endif // ALUNO_H