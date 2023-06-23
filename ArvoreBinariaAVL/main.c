#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
int Inserir(int val, AVL **raiz)
{
    if (*raiz == NULL)
    {
        AVL *novo;
        novo = (AVL *) malloc(sizeof(AVL));
        novo->dado = val;
        novo->bal = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz=novo;
        return 0;
    }
    else if (val < (*raiz)->dado)
    {
        if (Inserir(val, &(*raiz)->esq)==0)
        {
            switch ((*raiz)->bal)
            {
            case -1:
                (*raiz)->bal = 0;
                return 1;
            case 0:
                (*raiz)->bal = 1;
                return 0;
            case 1:
                if ((*raiz)->esq->bal == 1)
                    RotacaoSimplesADireita(&(*raiz));
                elseRotacaoDuplaADireita(&(*raiz));
                return 1;
            }
        }
    }
    else
    {
        else
        {
            if (Inserir(val, &(*raiz)->dir)==0)
            {
                switch ((*raiz)->bal)
                {
                case -1:
                    if ((*raiz)->dir->bal== -1)
                        RotacaoSimplesAEsquerda(&(*raiz));
                    else

                        RotacaoDuplaAEsquerda(&(*raiz));
                    return 1;
                case 0:
                    (*raiz)->bal= -1;
                    return 0;
                case 1:
                    (*raiz)->bal= 0;
                    return 1;
                }
            }
        }
