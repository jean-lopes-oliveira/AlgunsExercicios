#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;

}p;
int main()
{
    p *c;
    c = (p *)malloc(sizeof(struct celula));
    p *b;
    b = (p *)malloc(sizeof(struct celula));
    iniciar(c);
    iniciar(b);
    inserir(c);
    inserir(b);
    inserir(b);
    unir(c,b);

    return 0;
}
void iniciar(p **inicio){
    *inicio = NULL;
}
void inserir(p **inicio){

    p *c;
    c = (p *)malloc(sizeof(struct celula));

    int n;
    scanf("%d",&n);
    c->dado = n;

    if(*inicio == NULL){

        c->prox = NULL;

    }else{

        c->prox = *inicio;

    }

    *inicio = c;


}
void unir(p **inicio,p **inicio1){

    p *c = *inicio;
    p *e = *inicio1;
    int l = 1;
    while(l!=0){

        if(c->prox == NULL){

            c->prox = *inicio1;
            l = 0;
        }
        c = c->prox;


    }

    c = *inicio;
    while(c != NULL){

        printf("%d",c->dado);
        c = c->prox;

    }

}
