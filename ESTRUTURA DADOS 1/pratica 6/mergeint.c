//caio silas 
//matricula 21.1.4111

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int *v,int l,int m, int r){
    int tamE = m - l + 1;
    int i,j;
    int tamD = r - m;
    int *vetorE = malloc((tamE - 1)*sizeof(int));
    int *vetorD= malloc((tamD - 1)*sizeof(int));
    for (i = 0; i < tamE; i++){
        vetorE[i] = v[i + l]; 
    }
    for (j = 0; j < tamD; j++)
    {
        vetorD[j] = v[m + j + 1];
    }
    i = 0;
    j = 0;
    int k;
    for (k = l; k <= r; k++)
    {
        if (i == tamE){
            v[k] = vetorD[j++];
        }
        else if (j == tamD){
            v[k] = vetorE[i++];
        }
        else if (vetorE[i]<= vetorD[j]){
            v[k] = vetorE[i++];
        }
        else {
            v[k] = vetorD[j++];
        }
        
    }
    free(vetorE);
    free(vetorD);
}

int mergeint(int *v, int l, int r,int n){
    int b;
    int esq,dir;
    b = 1;
    while (b < n){
        esq = 0;
        while ((esq + b) < n)
        {
            dir = esq + (2 * b);
            if (dir > n){
                dir = n;
            }
            merge(v,esq,(esq + b) - 1,dir - 1);
            esq = esq + (2 * b);
        }
        b = b * 2;
    }
    return 0;
}

int main(){
    int v[]={10,3,6,8,1,9};
    int n = 6;
    mergeint(v,0,6,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",v[i]);
    }
    
    return 0;
}