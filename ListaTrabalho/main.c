#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct celula
{

    char nome[50];
    struct celula *prox;
    struct celula *ant;

} l;
void iniciar(l **inicio);
void inserir(l **inicio);
void mostrar(l **inicio);
void remover(l **inicio);
int main()
{
    int m;
    l *p;
    iniciar(&p);
    do
    {

        printf("\nDigite 1 para inserir\nDigite 2 para mostrar\nDigite 3 para remover\nDigite 0 para sair\n");
        scanf("%d",&m);
        switch(m)
        {

        case 1:
            inserir(&p);
            break;
        case 2:
            mostrar(&p);
            break;
        case 3:
            remover(&p);
            break;


        }


    }
    while(m != 0);
    return 0;
}
void iniciar(l **inicio)
{

    *inicio = NULL;

}
void inserir(l **inicio)
{

    l *p;
    l *f;
    f = *inicio;
    l *g;
    p = (l *)malloc(sizeof(struct celula));
    char nome[50];
    fflush(stdin);
    scanf("%s",&nome);
    fflush(stdin);
    strcpy(p->nome,nome);
    int m = 0;
    if(*inicio == NULL)
    {

        p->prox = NULL;
        p->ant = NULL;
        *inicio = p;
        m = 1;
    }

l *h;
    if(m !=1)
    {
        while(strcmp(p->nome,f->nome)>0 && f->prox != NULL)
        {
            g = f;
            f = f->prox;
            h = f->prox;
        }
       if(strcmp(p->nome,f->nome) >0 && f->prox == NULL &&f->ant != NULL )
        {

            p->prox = NULL;
            p->ant = f;
            f->prox = p;

        }
        else if(strcmp(p->nome,f->nome)> 0 && f->prox != NULL && f->ant != NULL)
        {

            p->ant = f;
            p->prox = f->prox;
            f->prox = p;
            g->ant = p;


        }
        else if(strcmp(p->nome,f->nome)> 0 && f->prox == NULL && f->ant == NULL)
        {

            p->ant = f;
            p->prox = NULL;
            f->prox = p;


        }
        else if(strcmp(p->nome,f->nome)> 0 && f->ant != NULL && f->prox == NULL)
        {

            p->prox = f->prox;
            p->ant = f;
            f->prox = p;
        }
        else if(strcmp(p->nome,f->nome)< 0 && f->ant == NULL && f->prox == NULL)
        {
            p->prox = f;
            p->ant = NULL;
            f->ant = p;
            *inicio = p;
        }
        else if(strcmp(p->nome,f->nome)< 0 && f->ant != NULL && f->prox != NULL){

            p->prox = f;
            p->ant = f->ant;
            f->ant = p;
            g->prox = p;

        }
        else if(strcmp(p->nome,f->nome)< 0 && f->ant == NULL && f->prox !=NULL)
        {

            p->prox = f;
            p->ant = NULL;
            f->ant = p;
            *inicio = p;
        }
        else if(strcmp(p->nome,f->nome)< 0 && f->ant != NULL && f->prox ==NULL)
        {

            p->prox = f;
            p->ant = f->ant;
            f->ant = p;
            g->prox = p;
        }
    }


}
void mostrar(l **inicio)
{
    if(*inicio == NULL)
    {


        printf("\nLista vazia\n");

    }
    l *p = *inicio;
    while(p != NULL)
    {

        puts(p->nome);
        p = p->prox;


    }

}
void remover(l **inicio){

    l *f = *inicio;
    l *aux;

    char nome[50];
    fflush(stdin);
    scanf("%s",&nome);
    fflush(stdin);


    if(*inicio == NULL){

        printf("\nLista vazia\n");

    }

    if((*inicio)->prox==NULL && strcmp((*inicio)->nome,nome)==0)
    {

        free((*inicio));
        (*inicio)=NULL;

    }
    else if((*inicio)->prox!=NULL && strcmp((*inicio)->nome,nome)==0)
    {

        aux=(*inicio);
        (*inicio)=(*inicio)->prox;
        (*inicio)->ant = NULL;
        free(aux);
    }
    else
    {
        aux=(*inicio);
        l *g;
        l *h;
        while(aux!=NULL && strcmp(aux->nome,nome)<0 )
        {

            g = aux;
            aux = aux->prox;
            h = aux->prox;


        }
         if(aux->ant != NULL && aux->prox == NULL)
        {

            g->prox = NULL;

        }
        else if(aux->ant != NULL && aux->prox != NULL){

            g->prox = h;
            h->ant = g;
        }
        else if(aux->ant == NULL && aux->prox !=NULL)
        {

            h->ant = NULL;
            *inicio = h;

        }else if(aux->ant == NULL && aux->prox == NULL){

            *inicio = NULL;

        }
        free(aux);

    }

}
