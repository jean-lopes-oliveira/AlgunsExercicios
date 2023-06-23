#include <stdio.h>
#include <stdlib.h>
struct arvore
{
    int info;
    struct arvore *esq,*dir;
};
typedef struct arvore *raiz;
raiz* insere(raiz *root,raiz *r,int dado);
int main()
{
    int valor;
    raiz raiz = NULL;
    for(int i = 1; i <=3; i++)
    {
        scanf("%d", valor);
        if(raiz==NULL)
            raiz = insere(raiz,raiz,valor);
        else
            insere(raiz,raiz,valor);
    }

    PreOrdem(raiz);
    EmOrdem(raiz);
    PosOrdem(raiz);
    return 0;
}

raiz* insere(raiz *root,raiz *r,int dado)
{
    if(r==NULL)
    {
        r = (raiz*) malloc(sizeof(raiz));
        if(r==NULL)
            printf("MemoriaInsufuciente!!!");
        else
        {
            r->esq=NULL;
            r->dir=NULL;
            r->info=dado;
            if(root==NULL)
            return r;
            if(r->info< root->info)
                root->esq= r;
            else
                root->dir= r;
            return r;
        }
    }
    if(dado < r->info)
        insere(r,r->esq,dado);
    else
        insere(r,r->dir,dado);
    return r;
}
void PreOrdem(raiz *root)
{
    if(root==NULL)
        return;
    printf("%d",root->info);
    PreOrdem(root->esq);
    PreOrdem(root->dir);
}

