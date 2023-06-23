#include <stdio.h>
#include <stdlib.h>
void duplicar(char frase[]);
int main()
{
    char f[200];
    gets(f);
    fflush(stdin);
    duplicar(f);
    return 0;
}

void duplicar(char frase[]){

    char p[200];
    int g = 0;
    int cont = 0;
    int f = 0;
    int j = 0;
    while(frase[j] != '\0'){

        p[cont] = frase[j];
        cont++;
        if(frase[j] == ' ' || frase[j+1] == '\0'){
            f = j-g;
            while(f<=j){
                p[cont] = frase[f];
                cont++;
                f++;
            }
            g=0;
        }
        g++;
        j++;
    }
        p[cont] = '\0';
        puts(p);

}
