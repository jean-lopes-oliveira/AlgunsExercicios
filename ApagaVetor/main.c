#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam = 7;
    int vet[tam],valor,aux;

    for(int i = 0; i <tam; i++){

            scanf("%d",&vet[i]);

    }
    scanf("%d",&valor);
    int l = 0;
     for(int j = 0; j <tam;j++){

        if(vet[j] == valor){
            for(int k = j; k < tam-1;k++){

                vet[k] = vet[k+1];

                if(k == tam -2){

                    l++;

                }

            }
            j--;
        }

     }
     for(int i = 0; i < tam - l;i++){


        printf("\n %d \n",vet[i]);

     }
    return 0;
}
