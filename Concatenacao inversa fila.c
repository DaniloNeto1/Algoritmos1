#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int busca_seq(int item, int v[], int esq, int dir){
    int i;
    printf("%d", v[esq]);
    for(i = esq + 1; i <= dir; i++){
        printf(" %d", v[i]);
    }
    printf("\n");
    
    for(i = esq; i <= dir; i++){
        if(v[i] == item){
            return i;
        }
    }
    
    return -1;
}

int busca_bin(int item, int v[], int esq, int dir, int m){
    int meio;
    
    while(dir - esq + 1 > m){
        meio = (esq + dir) / 2;
        
        if(v[meio] == item){
            return meio;
        }
        
        if(v[meio] > item){
            dir = meio - 1;
        }else{
            esq = meio + 1;
        }
    }
    
    return busca_seq(item, v, esq, dir);
}

int main(){
    int i, item, tamanho, m, posicao;
    
    scanf("%d", &item);
    scanf("%d", &tamanho);
    
    int vetor[tamanho];
    
    for(i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);
    
    scanf("%d", &m);
    
    posicao = busca_bin(item, vetor, 0, tamanho - 1, m);
    
    printf("%d\n", posicao);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}