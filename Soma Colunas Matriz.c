#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int linha;
    int coluna;
    int valor;
} Elemento;

typedef struct{
    int linhas;
    int colunas;
    int numElementos;
    Elemento* elementos;
} MatrizEsparsa;

int* soma_col(MatrizEsparsa matriz){
    int* vetorSoma = (int*)realloc(matriz.colunas, sizeof(int));
    
    for(int i = 0; i < matriz.numElementos; i++){
        int colunaAtual = matriz.elementos[i].coluna;
        int valorAtual = matriz.elementos[i].valor;
        
        vetorSoma[colunaAtual] += valorAtual;
    }
    
    return vetorSoma;
}

int main(){
    int i, j, lin, col, valor;

    scanf("%d %d", &lin, &col);
    
    MatrizEsparsa matriz;
    matriz.linhas = lin;
    matriz.colunas = col;
    matriz.numElementos = 0;
    matriz.elementos = NULL;
    
   
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &valor);
            
            if(valor != 0){
                matriz.numElementos++;
                matriz.elementos = (Elemento*)realloc(matriz.elementos, matriz.numElementos * sizeof(Elemento));
                matriz.elementos[matriz.numElementos - 1].linha = i;
                matriz.elementos[matriz.numElementos - 1].coluna = j;
                matriz.elementos[matriz.numElementos - 1].valor = valor;
            }
        }
    }
    
    int* vetorSoma = soma_col(matriz);
    

    for(i = 0; i < col; i++)
        printf("%d ", vetorSoma[i]);

    free(matriz.elementos);
    free(vetorSoma);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    return 0;
}