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
    inserir(c);
    inserir(b);
    int l = comparar(c,b);
    if(l == 1){

        printf("A lista a é maior");

    }else if(l == -1){
        printf("A lista b é maior");

    }else{

        printf("Alista a é igual a lista b");

    }
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
int comparar(p **inicio,p **inicio1){

    p *c = *inicio;
    p *e = *inicio1;
    int cont1 = 0;
    while(c != NULL){

        cont1++;
        c = c->prox;

    }

    int cont2 = 0;
    while(e != NULL){

        cont2++;
        e = e->prox;

    }
    if(cont1 > cont2){

        return 1;

    }else if (cont1 < cont2){

        return -1;
    }else{

        return 0;

    }

}
