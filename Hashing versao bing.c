#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int *tabela;
    int tam;
    float c;
} tabelahash;

int hash1(tabelahash *th, int key){
    return (int)(th->tam * (key * th->c - (int)(key * th->c)));
}

int hash2(int key, int tam){
    return 1 + (key % (tam - 1));
}

int rehash(tabelahash *th, int key, int i){
    return (hash1(th, key) + (i * hash2(key, th->tam))) % th->tam;
}

void inicio(tabelahash *th, int tam, float c){
    th->tabela = malloc(tam * sizeof(int));
    th->tam = tam;
    th->c = c;
    
    for (int i = 0; i < tam; i++){
        th->tabela[i] = 0;
    }
}

int inserir(tabelahash *th, int key){
    int i = 0;
    int posicao;
    
    while(i < th->tam){
        posicao = rehash(th, key, i);
        
        if(th->tabela[posicao] == 0){
            th->tabela[posicao] = key;
            printf("%d\n", posicao);
            return 1; 
        }
        
        i++;
    }
    
    return 0; 
}

int main(){
    int i, n, num_key, key;
    float x;

    scanf("%f %d", &x, &n);
    
    tabelahash th;

    inicio(&th, n, x);

    scanf("%d", &num_key);
    
    for(i = 0; i < num_key; i++){
        scanf("%d", &key);
        inserir(&th, key);
    }
    
    free(th.tabela);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    return 0;
}
