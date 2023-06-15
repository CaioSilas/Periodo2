//caio silas
//21.1.4111

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void heapRefaz(int *v,int esq,int dir){
    int i = esq;
    int j = i * 2 + 1;
    int aux = v[i];

    while (j <= dir){
        if (j < dir && v[j] < v[j+1]){
            j = j + 1;
        }
        if (aux >= v[j]){
            break;
        }
        v[i] = v[j];
        i = j;
        j = i * 2 + 1;
    }
    v[i] = aux;
}

void heapcontroi(int *v,int n){
    int esq = (n/2) - 1;
    while (esq >= 0)
    {
        heapRefaz(v,esq,n - 1);
        esq--;
    }
    
}

void heapsort(int *v,int n){
    heapcontroi(v,n);
    int aux;
    while (n > 1)
    {
        aux = v[n - 1];
        v[n - 1] = v[0];
        v[0] = aux;
        n = n - 1;
        heapRefaz(v,0,n-1);
    }
    
}

int main(){
    int n;
    printf("digite o tamanho do vetor\n");
    scanf("%d",&n);

    int *v = calloc(n,sizeof(int));
    printf("digite os numeros do vetor\n");
    for (int i = 0; i < n;i++){
        scanf("%d",&v[i]);
    }

    heapsort(v,n);
    printf("\n\n");

    printf("vetor ordenado\n");
    for (int i = 0; i < n;i++){
        printf("%d: %d\n",i + 1,v[i]);
    }

    free(v);
    return 0;
}