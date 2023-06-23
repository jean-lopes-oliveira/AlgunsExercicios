#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100
struct pilha{
    int topo;
    char dados[max];

};
int main()
{
    int a = 2;
    int b = 4;
    int c = 1;
    float x1;
    float x2;
    x1 = (float)(((b*-1) + sqrt((b*b)-4*a*c))/(2*a));
    x2 = (float)(((b*-1) - sqrt((b*b)-4*a*c))/(2*a));
    printf("%f %f",x1,x2);
    return 0;
}
int inserir(){}
