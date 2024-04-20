#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int energia;
    int defesa;
    int forca;
    int golpes[3];
} Personagem;

void reduzir_energia(Personagem *p, int pontos_dano){
    p->energia -= pontos_dano;
    if (p->energia < 0) {
        p->energia = 0;
    }
}

void restaurar(Personagem *p){
    p->energia += 200;
    if (p->energia > 1000) {
        p->energia = 1000;
    }
}

int executar_ataque(Personagem *atacante, Personagem *atacado, int golpe){
    int dano = atacante->forca + atacante->golpes[golpe - 1] - atacado->defesa;
    if (dano <= 0) {
        dano = 1;
    }
    reduzir_energia(atacado, dano);
    return dano;
}

int main(){
    int i, num_acoes, turno = 1, personagem, golpe;
    char acao;
    
    Personagem p1, p2;
    
    scanf("%s %d %d %d %d %d %d", p1.nome, &p1.energia, &p1.defesa, &p1.forca, &p1.golpes[0], &p1.golpes[1],   &p1.golpes[2]);
    scanf("%s %d %d %d %d %d %d", p2.nome, &p2.energia, &p2.defesa, &p2.forca, &p2.golpes[0], &p2.golpes[1], &p2.golpes[2]);

    scanf("%d", &num_acoes); 

    for(i = 0; i < num_acoes; i++){
        scanf("%d %c", &personagem, &acao);
        if(acao == 'C'){ 
            if(personagem == 1){
                restaurar(&p1);
            } 
            else{
                restaurar(&p2);
            }
        }
        else{
            scanf("%d", &golpe);
            if(personagem == 1){
              executar_ataque(&p1, &p2, golpe);
            }
            else{
                executar_ataque(&p2, &p1, golpe);
            }
        }
        if(p1.energia == 0 || p2.energia == 0){
            break;
        }
        if(turno == 1){
            turno = 2;
        }
        else{
            turno = 1;
        }
    }

    printf("%s %d\n", p1.nome, p1.energia);
    printf("%s %d\n", p2.nome, p2.energia);
    
    if(p1.energia == p2.energia){
        printf("empate\n");
    }
    else if(p1.energia > p2.energia){
        printf("%s", p1.nome);
    }
    else{
        printf("%s", p2.nome);
    }
    
    return 0;
}