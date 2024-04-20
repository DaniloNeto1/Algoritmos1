#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenar_matriz(int matriz[][100], int linhas, int colunas) {
    int i, j, k, temp;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas - 1; j++){
            for(k = 0; k < colunas - j - 1; k++){
                if(matriz[i][k] < matriz[i][k + 1]){
                   
                    temp = matriz[i][k];
                    matriz[i][k] = matriz[i][k + 1];
                    matriz[i][k + 1] = temp;
                }
            }
        }
    }
}

int main(){
    int i, j, linhas, colunas, matriz[100][100];
    
    scanf("%d %d", &linhas, &colunas);

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++)
            scanf("%d", &matriz[i][j]);
    }

    ordenar_matriz(matriz, linhas, colunas);

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);

        printf("\n");
    }

    return 0;
}