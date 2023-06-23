#include <stdio.h>
#include <stdlib.h>
typedef struct celula{

    int dado;
    struct celula *prox;
    struct celula *ant;

}l;
void iniciar(l **inicio);
void inserir(l **inicio);
void inserir_fila_circular(l **inicio,l **fim);
void remover_fila(l **inicio);
void remover_fila_circular(l **inicio,l **fim);
void remover_pilha(l **inicio);
void menu_fila(l **inicio);
void menu_fila_circular(l **inicio,l **fim);
void menu_pilha(l **inicio);
int main()
{
    l *pilha;
    l *fila;
    l *fila_c;
    iniciar(&pilha);
    iniciar(&fila);
    iniciar(&fila_c);
    l *fim = NULL;
        int d;
    do{

        printf("\n1->PILHA\n2->FILA\n3->FILA CIRCULAR\n");
        scanf("%d",&d);
        switch(d){

        case 1:
            menu_pilha(&pilha);break;
        case 2:
            menu_fila(&fila);break;
        case 3:
            menu_fila_circular(&fila_c,&fim);break;

        }


    }while(d !=0);

    return 0;
}
void iniciar(l **inicio){

    *inicio = NULL;

}
void mostrar(l **inicio){

    l *p = *inicio;
    while(p != NULL){

        printf("\nValor:%d\n",p->dado);
        p = p->prox;

    }

}
void mostrar_fila_circular(l **inicio,l **fim){

   // l *g;
    l *f = (*inicio);
    l *p = (*inicio);
   // int m =0;
    if(*inicio == NULL){

        printf("\nLista vazia\n");

    }else{
    while(p != *fim){

                printf("\nValor%d\n",p->dado);
                //f = p;
                p = p->prox;

        }
        printf("\nValor%d\n",p->dado);
    }


}
void menu_pilha(l **inicio){

    int m = 1;
    do{

        printf("\n1->INSERIR\n2->REMOVER\n3->MOSTRAR\n");
        scanf("%d",&m);
        switch(m){

        case 1:
            inserir(&*inicio);break;
        case 2:
            remover_pilha(&*inicio);break;
        case 3:
            mostrar(&*inicio);break;

        }


    }while(m !=0);

}
void menu_fila(l **inicio){

    int n;
    do{

        printf("\n1->INSERIR\n2->REMOVER\n3->MOSTRAR\n");
        scanf("%d",&n);
        switch(n){

        case 1:
            inserir(&*inicio);break;
        case 2:
            remover_fila(&*inicio);break;
        case 3:
            mostrar(&*inicio);break;

        }


    }while(n !=0);

}
void menu_fila_circular(l **inicio,l **fim){

    int d;
    do{

        printf("\n1->INSERIR\n2->REMOVER\n3->MOSTRAR\n");
        scanf("%d",&d);
        switch(d){

        case 1:
            inserir_fila_circular(&*inicio,&*fim);break;
        case 2:
            remover_fila_circular(&*inicio,&*fim);break;
        case 3:
            mostrar_fila_circular(&*inicio,&*fim);break;

        }


    }while(d !=0);

}
void menu_geral(l **inicio){


}
void inserir(l **inicio){

    l *p = *inicio;
    p = (l *)malloc(sizeof(struct celula));
    int n;
    printf("\nInserir um numero\n");
    scanf("%d",&n);
    p->dado = n;
    p->ant = NULL;
    if(*inicio == NULL){
        p->prox = NULL;
    }else{

        p->prox = *inicio;
        (*inicio)->ant = p;

    }
    *inicio = p;

}
void remover_pilha(l **inicio){

    l *p = *inicio;
    if(*inicio == NULL){

        printf("\nA lista esta vazia\n");

    }else{

        (*inicio) = (*inicio)->prox;
        (*inicio)->ant = NULL;
        free(p);
    }

}
void remover_fila(l **inicio){
    l *p = *inicio;
    if(*inicio == NULL){

        printf("\nA fila esta vazia\n");

    }else{

        l *g;
        while(p->prox != NULL){
            g = p;
            p = p->prox;

        }
        g->prox = NULL;
        free(p);

    }

}
void inserir_fila_circular(l **inicio,l **fim){


    l *p;
    p = (l *)malloc(sizeof(struct celula));
    int n;
    scanf("%d",&n);
    p->dado = n;
    if(*inicio == NULL){



        p->prox = p;
        p->ant = p;
        *inicio =  p;
        *fim = p;

    }/*else if(p == p->prox){
        l *f;
        f = *inicio;
        p->prox = f;
        f->prox = p;
        p->ant = f;
        *inicio = p;

    }*/else{
        l *f = *inicio;
        l *g;
        f = *inicio;

        p->prox = *inicio;
        (*inicio)->ant = p;
        //g = *inicio;

        *inicio = p;
        (*inicio)->ant = *fim;


    }

}
void remover_fila_circular(l **inicio,l **fim){

        l *g = (*inicio);
        l *p = *inicio;
    if(*inicio == NULL){

        printf("\nA lista esta vazia\n");

    }else if( p->prox == p){

        *inicio = NULL;
        free(p);

    }else{


        while(p !=*fim){

            p = p->prox;

        }

        (*inicio)->ant = p->ant;
        l *f = p->ant;
        f->prox = *inicio;
        *fim = (*inicio)->ant;
        free(p);
    }

}
