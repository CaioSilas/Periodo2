# ifndef fib_h
# define fib_h

typedef struct{
  //preencher conforme a necessidade
  double i;
  double chamadas;
  double resultado;
} TADFib;

/*colocar o tipo de retorno adequado para grandes numeros*/
double fibonacci(int i, TADFib *f);


# endif
