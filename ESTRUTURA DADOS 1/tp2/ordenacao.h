//Caio silas - Matricula : 21.1.4111
//Turmas 21-22


#ifndef ORDENACAO_H
#define ORDENACAO_H

//struct para guardar a quantidade de upas e seus casos de gravidade
typedef struct caso Tcaso;
//struct para upas
typedef struct upa Tupa;
//funcao para alocar upas
void alocaUpa(Tupa **upa,int qnt);
//funcao para preencher a struct
void Completaupa(Tupa **upa,int qnt);
//funcao para comparar qual entrada tem preferencia
int compara(Tupa x, Tupa y);
//funcao para ordernao por complexidade
int ordena(Tupa **upa, int qnt);
//printa as upas
void printupa(Tupa **upa, int qnt);
//insertion 
int insertion(Tupa **upa,int qnt);

#endif // ORDENACAO_H