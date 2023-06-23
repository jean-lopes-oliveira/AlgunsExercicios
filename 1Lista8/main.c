#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
    int codigo;
    float preco;
    int quant;
    struct celula *prox;

}p;
int main()
{
    p *c;
    c = (p *)malloc(sizeof(struct celula));
    iniciar(c);
    inserir(c);
    inserir(c);
    inserir(c);
    inserir(c);
    desconto(c);
    relatorio(c);
    return 0;
}
void iniciar(p **inicio){
    *inicio = NULL;

}
void inserir(p **inicio){

    p *c;
    c = (p *)malloc(sizeof(struct celula));
    int cod,quant;
    float preco;
    printf("\nDigite o codigo do produto.\n");
    scanf("%d",&cod);
    printf("\nDigite o preco do produto.\n");
    scanf("%f",&preco);
    printf("\nDigite a quantidade do produto.\n");
    scanf("%d",&quant);
    c->codigo = cod;
    c->preco = preco;
    c->quant = quant;

    if(*inicio == NULL){

        c->prox = NULL;

    }else{

        c->prox = *inicio;

    }
    *inicio = c;

}
void desconto(p **inicio){

    p *p;
    p = *inicio;
    printf("\nDigite o desconto\n");
    float desconto;
    scanf("%f",&desconto);
    while(p != NULL){


        p->preco = p->preco - (p->preco*(desconto/100));
        p = p->prox;

    }

}
void relatorio(p **inicio){


    int cont = 0;
    p *p;
    p = *inicio;
    while(p != NULL){

        printf("\nCodigo : %d\n",p->codigo);
        printf("\nPreco : %f\n",p->preco);
        if(p->quant >500){

            cont++;

        }
        p = p->prox;

    }
    printf("\nSao %d os produtos com quantidade superior a 500\n",cont);

}
