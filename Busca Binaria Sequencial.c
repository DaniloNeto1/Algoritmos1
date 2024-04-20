#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_bin_seq(int chave, int v[], int esq, int dir, int m) {
    while (dir - esq + 1 > m) {
        int meio = (esq + dir) / 2;

        if (v[meio] == chave) {
            dir = meio;
        } else if (v[meio] < chave) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }

    for (int i = esq; i <= dir; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    for (int i = esq; i <= dir; i++) {
        if (v[i] == chave) {
            return i;
        }
    }

    return -1;
}

int busca(int chave, int v[], int n, int m) {
    return busca_bin_seq(chave, v, 0, n - 1, m);
}

int main() {
    int chave,i, n, m, posicao;
 
    scanf("%d", &chave);
   
    scanf("%d", &n);

    int v[n];
  
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    posicao = busca(chave, v, n, m);

    printf("%d\n", posicao);

    return 0;
}