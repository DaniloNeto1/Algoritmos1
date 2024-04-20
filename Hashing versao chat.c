#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float c;
    int n;
    int* tabela;
} tabelahash;

int hash(float c, int n, int key){
    return (int)(n * ((key * c) - (int)(key * c)));
}

int rehash(int n, int key, int i){
    return (hash(1, n-1, key) + i * (1 + key % (n - 1))) % n;
}

tabelahash* criar(float c, int n){
    int i;
    tabelahash* tabela_hash = (tabelahash*)malloc(sizeof(tabelahash));
    tabela_hash->c = c;
    tabela_hash->n = n;
    tabela_hash->tabela = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        tabela_hash->tabela[i] = -1;
    }

    return tabela_hash;
}

int inserir(tabelahash* tabela_hash, int key, int* posicao, int index){
    int i = 0;
    int pos;

    while(i < tabela_hash->n){
        pos = rehash(tabela_hash->n, key, i);
        if(tabela_hash->tabela[pos] == -1){
            tabela_hash->tabela[pos] = key;
            posicao[index] = pos;

            return pos;
        }

        i++;
    }

    return -1;
}

int main(){
    float c;
    int n;
    scanf("%f %d", &c, &n);

    int num_keys;
    scanf("%d", &num_keys);

    tabelahash* tabela_hash = criar(c, n);

    int* posicao = (int*)malloc(num_keys * sizeof(int));
    for (int i = 0; i < num_keys; i++) {
        int key;
        scanf("%d", &key);
        int pos = inserir(tabela_hash, key, posicao, i);
        posicao[i] = pos;
    }

    for (int i = 0; i < num_keys; i++) {
        printf("%d\n", posicao[i]);
    }

    free(posicao);
    free(tabela_hash->tabela);
    free(tabela_hash);

    return 0;
}
