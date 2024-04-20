#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

typedef struct Cell Cell;

struct Cell{
    int item;
    Cell *next;
};

typedef struct{
    Cell *inicio;
    Cell *fim;
}FilaE;

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item=key;
    c->next=NULL;
    return c;
}

FilaE* criar_filaE(){
    FilaE *f=(FilaE*) malloc(sizeof(FilaE));
    
    f->inicio=NULL;
    f->fim=NULL;
    return f;
}

int filaE_vazia(FilaE* f){
    return (f==NULL)||(f->inicio==NULL);
}

void enfileirarE(int key, FilaE* f){
    Cell *aux;

    if(f==NULL)
        f=criar_filaE();
    aux=criar_celula(key);
    if(f->inicio==NULL)
        f->inicio=f->fim=aux;
    else{
        f->fim->next=aux;
        f->fim=f->fim->next;
    }
}

int desenfileirarE(FilaE* f){
    int item=-INT_MAX;
    Cell *aux;

    if (!filaE_vazia(f)){
        aux=f->inicio;
        f->inicio=aux->next;
        item=aux->item;
        free(aux);
    }

    return item;
}

void imprimir_filaE(FilaE* f){
    Cell *aux;

    if(!filaE_vazia(f)){
        aux=f->inicio;
        while (aux!=NULL){
            printf("%d ", aux->item);
            aux=aux->next;
        }
    }
}

void semaforo(FilaE* E1, FilaE* E2, FilaE* E3, FilaE* E4){
    int cont;

    while(!filaE_vazia(E1) || !filaE_vazia(E2) || !filaE_vazia(E3)){
        if(!filaE_vazia(E1)){
            cont=0;
            do{
                if(!filaE_vazia(E1)){
                    enfileirarE(desenfileirarE(E1), E4);
                    cont++;
                }else
                    cont=3;
            }while(cont<3);
        }
        if(!filaE_vazia(E2)){
            cont=0;
            do{
                if(!filaE_vazia(E2)){
                    enfileirarE(desenfileirarE(E2), E4);
                    cont++;
                }else
                    cont=3;
            }while(cont<3);
        }

        if(!filaE_vazia(E3)){
            cont=0;
            do{
                if(!filaE_vazia(E3)){
                    enfileirarE(desenfileirarE(E3), E4);
                    cont++;
                }else
                    cont=3;

            }while(cont<3);
        }
    }
}

int main(){
    
    int a;

    FilaE *E1=criar_filaE();
    FilaE *E2=criar_filaE();
    FilaE *E3=criar_filaE();
    FilaE *E4=criar_filaE();
    
    do{
        scanf("%d", &a);
        if(a>=0)
            enfileirarE(a, E1);
    }while(a>=0);
    
    do{
        scanf("%d", &a);
        if(a>=0)
            enfileirarE(a, E2);
    }while(a>=0);
    
    do{
        scanf("%d", &a);
        if(a>=0)
            enfileirarE(a, E3);
    }while(a>=0);
    
    semaforo(E1, E2, E3, E4);

    imprimir_filaE(E4);
    
    free(E1);
    free(E2);
    free(E3);
    free(E4);
    
    /* Enter our code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}