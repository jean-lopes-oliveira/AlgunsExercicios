#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nDigite a idade em dias \n");
    int idade;
    scanf("%d",&idade);
    int restoIdade;
    restoIdade = idade %365;
    int idadeAnos = (idade-restoIdade)/365;
    int restoMeses = restoIdade%30;
    int idadeMeses = (restoIdade-restoMeses)/30;
    int dias = restoMeses;
    printf("A idade e = %d anos, %d meses, %d dias",idadeAnos,idadeMeses,dias);

    return 0;
}
