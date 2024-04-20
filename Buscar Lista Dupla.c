#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};

Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

int lista_vazia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam > 0)
        return 0;
    else
        return 1;
}

int lista_cheia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam < MAX_SIZE)
        return 0;
    else
        return 1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }

 
    return 0;
}

int buscar_lista(Lista *l1, Lista *l2) {
    int i, j;
    for (i = 0; i <= l1->tam - l2->tam; i++) {
        for (j = 0; j < l2->tam; j++) {
            if (l1->item[i+j] != l2->item[j]) {
                break;
            }
        }
        if (j == l2->tam) {
            return i;
        }
    }
    return -1;
}

int main(){
    int i, posicao;

    Lista *l1 = criar_lista();
    Lista *l2 = criar_lista();

    scanf("%d", &i);
    while(i != -1){
        inserir(l1, i);
        scanf("%d", &i);
    }

    scanf("%d", &i);
    while(i != -1){
        inserir(l2, i);
        scanf("%d", &i);
    }

    posicao = buscar_lista(l1, l2);
    
    printf("%d\n", posicao);

    return 0;
}