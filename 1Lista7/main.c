#include <stdio.h>
#include <stdlib.h>
typedef struct pilha{

    int dados;
    struct pilha *prox;

}p;
int inserir(p **pilha);
int remover(p **pilha);
void mostrar(p **pilha);
void iniciar(p **pilha);
int main()
{
    p *f;
    f = (p *)malloc(sizeof(struct pilha));
    iniciar(&f);
    inserir(&f);
    inserir(&f);
    remover(&f);
    mostrar(&f);


    return 0;
}
void iniciar(p **pilha){

    (*pilha) = NULL;

}
int inserir(p **pilha){

        p *l;
        l = (p *)malloc(sizeof(struct pilha));
        int f;
        scanf("%d",&f);
        l->dados = f;
        if(*pilha == NULL){
                l->prox = NULL;
        }else{

            l->prox = *pilha;

        }
        *pilha = l;
}
int remover(p **pilha){
    p *l;
    l = *pilha;
    if(*pilha == NULL){

        printf("A pilha esta vazia");

        return 0;
    }else{
       l = *pilha;
       printf("removido");
       (*pilha) = l->prox;
       free(l);
       return 1;
    }

}
void mostrar(p **pilha){

        p *l;
        l = *pilha;
        while(l != NULL){

            printf("%d",l->dados);
            l = l->prox;

        }

}
