#include <stdio.h>
#include <stdlib.h>
#define max 5
typedef struct fila{

    int dados[max];
    int inicio,fim;

}f;
void iniciar(f *fila);
int inserir(f *fila,int x);
int remover(f *fila);
void mostrar(f *fila);

int main()
{
    int n;
    f p;
    f p2;
    f p3;
    iniciar(&p);
    iniciar(&p2);
    iniciar(&p3);
    for(int i = 0;i<5;i++){

        scanf("%d",&n);
        inserir(&p,n);

    }
    int l;
    for(int i = 0; i<5;i++){

        l = remover(&p);
        if(l < 100){

            inserir(&p2,l);
        }else{

            inserir(&p3,l);

        }

    }
    inserir(&p,1);
    inserir(&p,2);
    inserir(&p,1);
    inserir(&p,2);

    printf("%d",p.fim);
    printf("=====fila1");
    mostrar(&p);
    printf("=====fila2");
    mostrar(&p2);
    printf("\n");
    printf("=====fila3");
    mostrar(&p3);

    return 0;
}
void iniciar(f *fila){

    (*fila).inicio = (*fila).fim = 0;

}
int inserir(f *fila, int x){

    if((*fila).fim == max && (*fila).inicio == 0|| (*fila).inicio-1 == (*fila).fim){

        printf("Fila cheia");
        return -1;

    }else{
        if((*fila).inicio == max || (*fila).fim == max){

            (*fila).fim = 0;
            (*fila).dados[(*fila).fim++] = x;

        }else{

            (*fila).dados[(*fila).fim++] = x;
        }

        return 1;

    }

}
int remover(f *fila){
    int l;
    if((*fila).fim == (*fila).inicio){

        printf("A fila esta vazia");
        return -1;
    }else{
        l = (*fila).dados[(*fila).inicio];
        if((*fila).fim == max && (*fila).inicio != 0){

            (*fila).inicio = 0;
            (*fila).inicio++;

        }else{
            (*fila).inicio++;
        }

        return l;
    }

}
void mostrar(f *fila){
    int i =(*fila).inicio;

        while(i != max && i-1 != (*fila).fim){

            printf("\n%d\n",(*fila).dados[i]);
            if(i == max){

                i = 0;
            }else{

                i++;
            }





        }



}
