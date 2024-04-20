#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int linha;
    int coluna;
    int valor;
} Elemento;

typedef struct {
    int linhas;
    int colunas;
    int numElementos;
    Elemento* elementos;
} MatrizEsparsa;

int compararVetorComLinha(int* vetor, int* linha, int tamanho){
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] != linha[i]) {
            return 0;
        }
    }
    
    return 1;
}

int buscarVetorNaMatriz(MatrizEsparsa matriz, int* vetor){
    for (int i = 0; i < matriz.linhas; i++) {
        int* linha = (int*)calloc(matriz.colunas, sizeof(int));
        
      
        for (int j = 0; j < matriz.colunas; j++) {
            linha[j] = 0;
        }
        
       
        for (int j = 0; j < matriz.numElementos; j++) {
            if (matriz.elementos[j].linha == i) {
                linha[matriz.elementos[j].coluna] = matriz.elementos[j].valor;
            }
        }
        
        
        if (compararVetorComLinha(vetor, linha, matriz.colunas)) {
            free(linha);
            return i;
        }
        
        free(linha);
    }
    
    return -1;
}

int main(){
    int numLinhas, numColunas;
    scanf("%d %d", &numLinhas, &numColunas);
    
    MatrizEsparsa matriz;
    matriz.linhas = numLinhas;
    matriz.colunas = numColunas;
    matriz.numElementos = 0;
    matriz.elementos = NULL;
    
  
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            int valor;
            scanf("%d", &valor);
            
            if (valor != 0) {
                matriz.numElementos++;
                matriz.elementos = (Elemento*)realloc(matriz.elementos, matriz.numElementos * sizeof(Elemento));
                matriz.elementos[matriz.numElementos - 1].linha = i;
                matriz.elementos[matriz.numElementos - 1].coluna = j;
                matriz.elementos[matriz.numElementos - 1].valor = valor;
            }
        }
    }
    
    int* vetor = (int*)malloc(numColunas * sizeof(int));
    for (int i = 0; i < numColunas; i++) {
        scanf("%d", &vetor[i]);
    }
    
    
    int posicao = buscarVetorNaMatriz(matriz, vetor);
    
  
    printf("%d\n", posicao);
    
   
    free(matriz.elementos);
    free(vetor);
    
    return 0;
}