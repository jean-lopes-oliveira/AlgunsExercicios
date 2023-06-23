#include <stdio.h>
#include <stdlib.h>
void matriz(int *m, char *ma[][20],int *vet[],int n);
int main()
{
    int n;
    printf("\nDigite a quantidade de linhas da matriz:\n");
    scanf("%d",&n);
    char ma[n][20];
    int m = 20;
    int vet[n];
    char valor;
    for(int i = 0; i<n; i++)
    {

        fflush(stdin);
        gets(ma[i]);
        fflush(stdin);

    }
    matriz(&m,&ma,&vet,n);
    printf("%d",m);
    for(int j = 0; j<n; j++)
    {
        printf("%d",vet[j]);
    }
    return 0;
}
void matriz(int *m,char *ma[][20],int *vet[],int n)
{


    int i = 0, x=0,y=0;

    while(x<n)
    {


        while(*ma[x][y] != '\0')
        {

            if(*ma[x][y+1] == '\0')
            {

                if(*ma[x][0] == *ma[x][y]){
                    *vet[i++] = x;
                    (*m)++;
                }
            }
            y++;

        }
        x++;
    }


}
