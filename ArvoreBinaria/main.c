#include <stdio.h>
#include <stdlib.h>
typedef struct arv
{

    int info;
    struct arv *esq;
    struct arv *dir;

} arvore;
void inserir(arvore *t,int dado);
void EmOrdem(arvore *root);
int main()
{
    arvore *l = NULL;
    arvore *f = NULL;
    inserir(&l,2);
    inserir(&l,4);
    //printf("%d",l->info);
    EmOrdem(l);

    return 0;
}

void inserir(arvore *t, int dado){
  int ok;
  // se t aponta para null, a inserção é na raiz...
  if (*t == NULL) {
    *t = (arvore *) malloc(sizeof(arvore));
    if (*t == NULL)
        return;
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->info = dado;
  }
  // Se o dado a ser inserido for menor que o nó atual, recursividade à esquerda
  if (dado < (*t)->info) {
     inserir(&((*t)->esq), dado);
  }
  else{
    // Se o dado a ser inserido for menor que o nó atual, recursividade à direita
    if (dado > (*t)->info) {
       inserir(&((*t)->dir), dado);
    }
  }
}
    void EmOrdem(arvore *root)
    {
        if(root==NULL)
            return ;
        EmOrdem(root->esq);
        printf("%d",root->info);
        EmOrdem(root->dir);
    }
