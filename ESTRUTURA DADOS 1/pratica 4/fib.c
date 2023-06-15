#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

/*colocar o tipo de retorno adequado para grandes numeros*/ 
double fibonacci(int i, TADFib *f){
    //preencher o algoritmo recursivo
    
    if (i == 0){
        return 0;
    }
    else if (i == 1){
        return 1;
    }
    else {
        f->chamadas+= 2;
        return fibonacci(i-1,f) + fibonacci(i - 2,f); 
    }
}