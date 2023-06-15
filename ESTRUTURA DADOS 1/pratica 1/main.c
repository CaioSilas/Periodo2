#include <stdio.h>
int main()
{
    double s = 0.0, M[12][12];
    char T;
    int lin,col;

    // Leitura do Char
    scanf ("%c",&T);

    // Leitura da Matriz e Cálculos
    for (lin = 0;lin < 12;lin++){
        for (col = 0;col < 12;col++){
            scanf("%lf",&M[lin][col]);
        }
    }

    //soma das matrizes
    int h = 1;
    int j = 10;
    
    if (T == 's' || T == 'S'){
        int cont = 0;
        while(cont != 5){
            for (int l = h; l <= j;l++){
                s += M[cont][l];
            }
            cont++;
            h++;
            j--;
        }
    }

    if (T == 'm' || T == 'M'){
        int cont = 0;
        while(cont != 5){
            for (int l = h; l <= j;l++){
                s += M[cont][l];
            }
            cont++;
            h++;
            j--;
        }
        s = s / 30;
    }

    // Impressão dos resultados
    
    if (T == 'm' || T == 'M'){
        printf("%.1lf",s);
    }

    if (T == 's' || T == 'S'){
        printf("%.1lf",s);
    }
    
    return 0;
}
