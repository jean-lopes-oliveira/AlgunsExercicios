#include <stdio.h>
#include <stdlib.h>
struct estatistica{

    int num_carros;
    int cod_cidade;
    int num_acidentes;

};
int main()
{

    int valor = 5;
    printf("\nDigite a quantidade de cadastros que desaja fazer\n");
    struct estatistica estat[valor];
    for(int i = 0; i <valor;i++){

        printf("\nDigite o codigo da cidade\n");
        scanf("%d",&estat[i].cod_cidade);
        printf("\nDigite o numero de carros\n");
        scanf("%d",&estat[i].num_carros);
        printf("\nDigite o numero de acidentes\n");
        scanf("%d",&estat[i].num_acidentes);

    }
    int maior = estat[0].num_acidentes,menor = estat[0].num_acidentes ,cidade_menor = estat[0].cod_cidade,cidade_maior =estat[0].cod_cidade,somar = 0,somar2 = 0;
    int cont = 0;
    for(int i = 0; i<valor;i++){

        if(maior<estat[i].num_acidentes){

            maior = estat[i].num_acidentes;
            cidade_maior = estat[i].cod_cidade;
        }
        if(menor>estat[i].num_acidentes){

            menor = estat[i].num_acidentes;
            cidade_menor = estat[i].cod_cidade;

        }
        somar += estat[i].num_carros;
        if(estat[i].num_acidentes<2000){

            somar2 += estat[i].num_acidentes;
            cont++;

        }

    }

    printf("\nO maior e o menor numero são %d  cidade %d e %d cidade %d\n",maior,cidade_maior,menor,cidade_menor);
    printf("\nMedia de veiculos nas 5 cidades %.2f\n",(float)somar/5);
    printf("\nMedia de acidentes de transitos nas cidades com menos de 2000 veniculos = %.2f\n",(float)somar2/cont);

    return 0;
}
