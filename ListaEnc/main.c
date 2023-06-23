#include <stdio.h>
#include <stdlib.h>
typedef struct celula
{

    int dado;
    struct celula *prox;

} p;
void iniciar(p **inicio);
void inserir(p **inicio);
void mostrar(p **inicio);
int main()
{
    p *c;
    c = (p *)malloc(sizeof(struct celula));
    iniciar(c);
    inserir(c);
    inserir(c);
    mostrar(c);
    return 0;
}
void iniciar(p **inicio)
{

    *inicio = NULL;

}
void inserir(p **inicio)
{

    p *c;
    c = (p *)malloc(sizeof(struct celula));
    int n;
    scanf("%d",&n);
    c->dado = n;
    if(*inicio == NULL)
    {

        c->prox = NULL;

    }
    else
    {

        c->prox = *inicio;

    }
    *inicio = c;


}
void mostrar(p **inicio)
{

        if(inicio==NULL)
        {
            printf("\nLista Vazia!!!");
            return;
        }
        p *p, *ante, *ultimo;
        p = *inicio;
        ante=p;
        while(p->prox!=NULL)
        {
            ante=p;
            p = p->prox;
        }
        printf("\nultimo: %d",p->dado);
        ultimo=ante;
        while(*inicio!=ultimo)
        {
            p=inicio;
            ante=p;
            while(p!=ultimo)
            {
                ante=p;
                p = p->prox;
            }
            printf("\nultimo: %d",p->dado);
            ultimo=ante;
        }
        printf("\nultimo: %d",(*inicio)->dado);

}
