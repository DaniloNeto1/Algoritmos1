#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};


Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}


int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}


int empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}


int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

int acessar_valor_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->item[p->topo];
    else
        return INT_MIN;
}

int cont_diamantes(char *carga){
    Pilha *p = criar_pilha();
    
    int i, diamantes = 0;

    for(i=0; carga[i] != '\0'; i++){
        if(carga[i] == '<'){
            empilhar(p, carga[i]);
        }
        else if(carga[i] == '>'){
            if(acessar_valor_topo(p) == '<'){
                desempilhar(p);
                diamantes++;
            }
        }
    }

    obter_posicao_topo(p);

    liberar_pilha(p);

    return diamantes;
}

int main(){
    int i, n;
    char carga[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%s", carga);
        
        printf("%d\n", cont_diamantes(carga));
    }

    return 0;
}
    
