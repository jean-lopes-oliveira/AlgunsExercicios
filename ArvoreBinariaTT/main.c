#include <stdio.h>
#include <stdlib.h>
typedef struct arvore
{
    int info;
    struct arvore *esq, *dir;

} arv;
arv* inserir(arv *root, arv *r, int dado);
void EmOrdem(arv *root);
int main()
{
    int valor;
    arv *raiz=NULL;
    int i =1;
    while(i <= 5){
    scanf("%d",&valor);
    //if(raiz==NULL)
        raiz=inserir(raiz,raiz,valor);
   // else
      // inserir(raiz,raiz,valor);

    i++;

    }

    EmOrdem(raiz);
    return 0;
}
arv* inserir(arv *root, arv *r, int dado)
{
    arv *p;
    if(r == NULL)
    {

        r = (arv *)malloc(sizeof(arv));
        if(r == NULL)
        {

            printf("Sem memoria");

        }
        else
        {
            r->esq = NULL;
            r->dir = NULL;
            r->info = dado;
            if(root == NULL)
            {

                return r;

            }
            if(r->info < root->info)
            {

                root->esq = r;

            }
            else
            {
                root->dir = r;

            }/*else if(r->info > root->info &&  r->info&& root->dir->info > r->info){

                p =  root->dir;
                root->dir = r;
                root->dir->dir = p;

            }*//*else if(r->info < root->info &&  r->info&& root->esq->info < r->info){

                p =  root->dir;
                root->dir = r;
                root->dir->dir = p;

            }*/
            return r;
            if(dado < r->info)
            {

                inserir(r,r->esq,dado);

            }
            else
            {

                inserir(r,r->dir,dado);

            }
            return r;



        }

    }
}
void EmOrdem(arv *root){
        if(root==NULL){
            return;
        }
        EmOrdem(root->esq);
        printf("\n%d\n",root->info);
        EmOrdem(root->dir);
}




