#include <stdio.h>
#include <stdlib.h>

int* matriz_diagonal(int **matriz, int n) {
    int i;
    int *vet = (int*) malloc(n * sizeof(int)); 
    for (i = 0; i < n; i++) {
        vet[i] = matriz[i][i];
    }
    return vet;
}

int main() {
    int n, i, j;
    
    scanf("%d", &n);
    
    int **matriz = (int**) malloc(n * sizeof(int*)); 
    for (i = 0; i < n; i++){
        matriz[i] = (int*) malloc(n * sizeof(int));
        
        for (j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]); 
        }
    }
    
    int *vet = matriz_diagonal(matriz, n);
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]); 
    }
    printf("\n");
    
    free(vet); 
    
    for (i = 0; i < n; i++) {
        free(matriz[i]); 
    }
    free(matriz); 
    return 0;
}