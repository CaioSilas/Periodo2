#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int instancia = 0;
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor = NULL;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        
        if (n == 0){
            break;
        }
        if (instancia > 0){
            printf("\n");
        }

        //aloque o vetor
        vetor = alocaVetor(n);
        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
            if (pontos1 > pontos2){
                vetor[time1 - 1].ponto += 2;
                vetor[time2 - 1].ponto ++;
            }
            else {
                vetor[time1 - 1].ponto ++;
                vetor[time2 - 1].ponto += 2;
            }
            vetor[time1 - 1].CestasFeitos += pontos1;
            vetor[time1 - 1].CestasRecebidos += pontos2;
            vetor[time2 - 1].CestasFeitos += pontos2;
            vetor[time2 - 1].CestasRecebidos += pontos1;
            //preencher o vetor de estruturas de acordo com os dados lidos

        }
        for (i = 0; i < n; i++)
        {
            vetor[i].time = i + 1;
        }


        //ordenar os times
        ordenacao(vetor, n);
        instancia++;
        printf("Instancia %d\n",instancia);
        //imprima o resultado
        for (i = 0; i < n; i++)
        {   
            if (i != n - 1){
              printf("%.0f ",vetor[i].time);  
            }
            else{
               printf("%.0f",vetor[i].time); 
            }
        }
        printf("\n");
        
        
        
        //desaloque o vetor
        desalocaVetor(&vetor);
    }

    return 0;
}
