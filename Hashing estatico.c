#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell {
    int item;
    struct Cell* next;
} Cell;

typedef struct {
    Cell* head;
} ListaE;


ListaE* criar_listaE() {
    ListaE* l = (ListaE*)malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}


Cell* criar_celula(int key) {
    Cell* c = (Cell*)malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;
    return c;
}


typedef struct {
    unsigned int tam;
    ListaE** buckets;
} hash;


hash* hash1(unsigned int tam){
    int i;

    hash* tabela = malloc(sizeof(hash));
    tabela->tam = tam;
    tabela->buckets = malloc(tam * sizeof(ListaE*));

    for (i = 0; i < tam; i++)
        tabela->buckets[i] = criar_listaE();

    return(tabela);
}


int inserir(int key, hash* tabela){
    int posicao = key % tabela->tam;

    printf("%d\n", posicao);
    Cell* aux, *novo;

    if(tabela->buckets[posicao]->head == NULL){
        aux = criar_celula(key);
        tabela->buckets[posicao]->head = aux;
    }else{
        aux = tabela->buckets[posicao]->head;
        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);
        aux->next = novo;
    }

    return 0;
}


void imprimir(hash* tabela){
    int i;
    Cell* aux;

    for(i = 0; i < tabela->tam; i++){
        aux = tabela->buckets[i]->head;
        printf("%d:", i);

        if(aux == NULL)
            printf(" ->");

        while(aux != NULL) {
            printf(" -> %d", aux->item);
            aux = aux->next;
        }

        printf("\n");

    }
}


void liberar(hash* tabela){
    int i;

    for(i = 0; i < tabela->tam; i++){
        Cell* aux = tabela->buckets[i]->head;

        while(aux != NULL){
            Cell* temp = aux;
            aux = aux->next;
            free(temp);
        }

        free(tabela->buckets[i]);

    }

    free(tabela->buckets);
    free(tabela);
}

int main(){
    int i = 0, tam, key, n;

    scanf("%d", &tam);
    hash* hash = hash1(tam);
    scanf("%d", &n);

    while(i < n){
        scanf("%d", &key);
        inserir(key, hash);
        i++;
    }

    printf("\n");

    imprimir(hash);

    liberar(hash);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    return 0;
}