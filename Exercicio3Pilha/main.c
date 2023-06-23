#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct pilha{
    int topo;
    char dados[max];

}p;
int inserir(char x,p *pilha);
int remover(p *pilha);
int main()
{
    p pi;
    pi.topo = -1;
    char s[100];
    gets(s);
    fflush(stdin);
    int j = 0;
    int cont = 0, cont2 = 0,cont3 = 0;
    int l=1;
    while(s[j] != '\0' && l != 0){

        if(s[j] == '('){
           inserir(s[j],&pi);
           cont++;
           }else if(s[j] == ')'){
                cont--;
                l = remover(&pi);

           }
        j++;
    }
    if(l != 0 && cont == 0){

        printf("\nExpressao valida\n");

    }else{

        printf("\nExpressao invalida\n");

    }

    return 0;
}

int inserir(char x, p *pilha){
    if((*pilha).topo == max-1){

        printf("stack overflow");
        return 0;
    }else{

        (*pilha).dados[++(*pilha).topo] = x;

        return 1;
    }

}
int remover(p *pilha){


    if((*pilha).topo == -1){

        printf("Stack underflow");
        return 0;

    }else{

        (*pilha).topo--;
        return 1;
    }

}
