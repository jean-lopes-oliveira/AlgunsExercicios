#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lista{

    char nome[30];
    int idade;
    struct lista *prox;
    struct lista *ant;

}l;
int main()
{
    int m = 1;
    l *p;

    iniciar(&p);
    while(m != 0){

        printf("\nDigite 1 para inserir\nDigite 2 para remover\nDigite 3 para verificar nome\nDigite 4 para mostrar\nDigite 0 para sair\n");
        scanf("%d",&m);
        switch(m){

            case 1:
                inserir(&p);break;
            case 2:
                remover(&p);break;
            case 3:
                verificar(&p);break;
            case 4:
                mostrar(&p);break;
        }

    }
    return 0;
}
void iniciar(l **inicio){

    *inicio = NULL;

}
void inserir(l **inicio){

    l *p;
    p = (l *)malloc(sizeof(struct lista));
    char vet[30];
    fflush(stdin);
    gets(vet);
    fflush(stdin);
    int n;
    scanf("%d",&n);
    strcpy(p->nome,vet);
    p->idade = n;
    p->ant = NULL;
    if(*inicio == NULL){

        p->prox = NULL;

    }else{

        p->prox = *inicio;
        (*inicio)->ant = NULL;

    }
    *inicio = p;

}
void mostrar(l **inicio){
    l *p;
    p = *inicio;

    while(p != NULL){

        puts(p->nome);
        printf("\n%d\n",p->idade);
        p = p->prox;

    }

}
void remover(l **inicio){

    l *p;
    p = *inicio;
    if(*inicio == NULL){

        printf("\nLista vazia\n");

    }else if((*inicio)->prox == NULL){

        *inicio = (*inicio)->prox;

    }else{


        *inicio = p->prox;
        (*inicio)->ant = NULL;

    }
    free(p);

}
void verificar(l **inicio){
    char vet[30];
    fflush(stdin);
    gets(vet);
    fflush(stdin);
    l *p = *inicio;
    while(p != NULL){

        if(strcmp(p->nome,vet) == 0){


            p->idade = p->idade+10;

        }
        p = p->prox;
    }

}
