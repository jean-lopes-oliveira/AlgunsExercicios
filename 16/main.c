#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet1[10],vet2[10],vet3[10];
    printf("\nPreencha o vetor 1\n");
    for(int i = 0; i <10;i++){

        scanf("%d",&vet1[i]);

    }
    printf("\nPreencha o vetor 2\n");
    for(int i = 0; i <10;i++){

        scanf("%d",&vet2[i]);

    }
    for(int i = 0; i <10;i++){

        vet3[i] = vet2[i] + vet1[i];

    }

    for(int i = 0; i <10;i++){

        printf("\n%d\n",vet3[i]);

    }
    return 0;
}
