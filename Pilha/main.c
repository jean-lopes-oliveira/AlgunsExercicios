#include <stdio.h>
#include <stdlib.h>
#define max 5
typedef struct pilha{
    int topo;
    int dados[max];
}p;
int inserir(int f,struct pilha *pilha);
int remover(struct pilha *pilha);
void desempilha(struct pilha *pilha);
int main()
{
    struct pilha pi;
    pi.topo = -1;
    inserir(1,&pi);
    inserir(2,&pi);
    inserir(3,&pi);
    inserir(4,&pi);
    inserir(5,&pi);
    remover(&pi);
    desempilha(&pi);

    return 0;
}
int inserir(int f,struct pilha *pilha){

    if((*pilha).topo == max-1){

        printf("Stack overflow");
        return 0;
    }else{
        (*pilha).dados[++(*pilha).topo] = f;

        return 1;
    }


}
int remover(struct pilha *pilha){

    if((*pilha).topo == -1){

        printf("Stack underflow");
        return 0;
    }else{

        (*pilha).topo--;
        return 1;
    }

}
void desempilha(struct pilha *pilha){

    int j = 0;
    while(j <= (*pilha).topo){

        printf("%d",(*pilha).dados[j]);
        j++;
    }


}
