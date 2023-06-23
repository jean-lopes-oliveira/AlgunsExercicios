#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct celula{

    float nf;
    char nome[100];
    struct celula *prox;

}p;
int main()
{

    p c;
    iniciar(&c);
    inserir(&c);
    inserir(&c);
    mostrar(&c);


    return 0;
}
void iniciar(p **inicio){

    *inicio = NULL;

}
void inserir(p **inicio){

    p *c;
    c = (p *)malloc(sizeof(struct celula));
    char vet[100];
    float nf;
    scanf("%f",&nf);
    fflush(stdin);
    gets(vet);
    fflush(stdin);
    c->nf = nf;
    strcpy(c->nome,vet);
    if(*inicio == NULL){

        c->prox = NULL;

    }else{

        c->prox = *inicio;

    }
    *inicio = c;

}
void mostrar(p **inicio){

    p *c = *inicio;
    int l = 0;
    while(c != NULL){

        if(c->nf>=7){

            puts(c->nome);
            l=1;

        }

        c = c->prox;
    }
    if(l == 0){

            printf("\nNão ha alunos aprovados\n");

        }

}
