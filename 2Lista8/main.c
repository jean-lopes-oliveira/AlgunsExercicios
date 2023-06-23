#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct celula{

    char nome[100];
    float salario;
    struct celula *prox;

}p;
void iniciar(p **inicio);
void inserir(p **inicio);
void calcule(p **inicio);
int main()
{
    p *c;
    c = (p *)malloc(sizeof(struct celula));
    iniciar(c);
    inserir(c);
    inserir(c);
    inserir(c);
    inserir(c);
    calcule(c);
    return 0;
}
void iniciar(p **inicio){
    *inicio = NULL;

}
void inserir(p **inicio){

    p *c;
    c = (p *)malloc(sizeof(struct celula));
    char nome[100];
    float salario;
    printf("\nDigite o nome do funcionario\n");
    fflush(stdin);
    gets(nome);
    fflush(stdin);
    strcpy(c->nome,nome);
    printf("\nDigite o salario do funcionario\n");
    scanf("%f",&salario);
    c->salario = salario;
    if(*inicio == NULL){

        c->prox = NULL;

    }else{


        c->prox = *inicio;

    }
    *inicio = c;


}
void calcule(p **inicio){

    p *c;
    c = *inicio;
    float soma=0;
    float media;
    float maior;
    float salario = 0;
    char nome[100];
    float valor;
    printf("\nDigite o valor\n");
    scanf("%f",&valor);
    int cont = 0;
    int l =0;
    int cont2 = 0;
    while(c != NULL){

            soma += c->salario;
            if(c->salario >salario){

               salario = c->salario;
               strcpy(nome,c->nome);
            }
            if(c->salario > valor){

                cont++;
                l = 1;

            }
            cont2++;

            c = c->prox;

    }
    media = soma/cont2;
    printf("\nA media do salario de todos os funcionarios e = %f\n",media);
    printf("\nO funcionario com maior salario é o(a)");
    puts(nome);
    printf(" e seu salario e = %.2f",salario);
    if(l == 0){

            printf("\nNao ha funcionarios com salario acima do valor especificado\n");

    }else{

            printf("\nA quantidade de funcionarios com salario maior que o especificado foi %d\n",cont);

    }

}
