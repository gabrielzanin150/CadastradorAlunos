#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    int cor; // 0 se for negro e 1 se for rubro
    struct node    *dir;
    struct node    *esq;
};



struct node* cria_no(int x)
{
    struct node* novo = (struct node*) malloc(sizeof(struct node));

    novo->esq = NULL;
    novo->dir = NULL;
    novo->x = x;
    novo->cor = 1;
    novo->esq->cor = 0;
    novo->dir->cor = 0;

    return novo;
}

int alturaNegra(struct node* arv)
{
    if (arv == NULL)

        return -1;

    else if (arv->dir == NULL && arv->esq == NULL)

        return 0;

    else
    {
        int dir_h = altura(arv->dir);
        int esq_h = altura(arv->esq);

        if(esq_h > dir_h)
        {
            if (arv->esq->cor==0)
                esq_h+1;
            else
                esq_h+0;
        }
        else
            if (arv->dir->cor==0)
                dir_h+1;
            else
                dir_h+0;

    }
}

void calculaBalanceamento(struct node* arv)
{
  //  if (arv->dir == NULL && arv->esq == NULL)
    //    arv->fatBalanceamento = 0;
  //  else
      //  arv->fatBalanceamento = altura(arv->esq) - altura(arv->dir);
}

struct node* search(struct node* arv, int x)
{
    if (arv == NULL)
        return NULL;

    else if (x == arv->x)
        return arv;

    else if (x < arv->x)
        return search(arv->esq, x);

    else
        return search(arv->dir, x);
}

struct node* refazBalanco(struct node* arv)
{


    calculaBalanceamento(arv);

    struct node* net = NULL;
    struct node* fil = NULL;

    if (arv->fatBalanceamento >= -1 && arv->fatBalanceamento <= 1)
        return arv;

    else if (arv->fatBalanceamento < -1)
    {
        fil = arv->dir;

        if (fil->fatBalanceamento <= 0)
        {
            arv->dir = fil->esq;
            fil->esq = arv;
            calculaBalanceamento(fil);
            calculaBalanceamento(arv);
            return fil;
        }
        else
        {
            net = fil->esq;
            fil->esq = net->dir;
            net->dir = fil;
            arv->dir = net->esq;
            net->esq = arv;
            calculaBalanceamento(net);
            calculaBalanceamento(fil);
            calculaBalanceamento(arv);
            return net;
        }
    }

        else if (arv->fatBalanceamento > 1)
    {
        fil = arv->esq;

        if (fil->fatBalanceamento >= 0)
        {
            arv->esq = fil->dir;
            fil->dir = arv;
            calculaBalanceamento(fil);
            calculaBalanceamento(arv);
            return fil;
        }
        else
        {
            net = fil->dir;
            fil->dir = net->esq;
            net->esq = fil;
            arv->esq = net->dir;
            net->dir = arv;
            calculaBalanceamento(net);
            calculaBalanceamento(fil);
            calculaBalanceamento(arv);
            return net;

        }
    }


    return NULL;
}

int insereNo(struct node** arv, int x)
{
    if ((*arv) == NULL)
    {
        *arv = cria_no(x);
        return 1;
    }

    else if (search(*arv, x) == NULL)
    {

        if (x > (*arv)->x)
        {
            if ((*arv)->dir == NULL)
                (*arv)->dir = cria_no(x);

            else
                insereNo(&(*arv)->dir,x);
        }

        else if (x < (*arv)->x)
        {
            if ((*arv)->esq == NULL)
                (*arv)->esq = cria_no(x);

            else
                insereNo(&(*arv)->esq, x);
        }

        (*arv) = refazBalanco(*arv);

        return 1;
    }

    return 0;
}

int remover(struct node** arv, int x)
{
    if ( search(*arv, x) != NULL && arv != NULL)
    {
        if (x == (*arv)->x)
        {
            struct node* temp = NULL;
            if ((*arv)->dir != NULL)
            {
                struct node** nodeAux = &(*arv)->dir;
                while ((*nodeAux)->esq != NULL)
                {
                    nodeAux = &(*nodeAux)->esq;
                }

                temp = *nodeAux;

                if (temp->dir != NULL)
                    (*nodeAux) = temp->dir;

                else
                    (*nodeAux) = NULL;


                (*arv)->x = temp->x;

                free(temp);
            }

            else if ((*arv)->esq != NULL)
            {
                temp = (*arv)->esq;
                (*arv)->x = (*arv)->esq->x;
                (*arv)->esq = NULL;
                free(temp);
            }

            else
            {
                free((*arv));
                (*arv) = NULL;
            }
        }

        else if (x < (*arv)->x)
        {
            remover(&(*arv)->esq, x);
        }

        else
        {
            remover(&(*arv)->dir, x);
        }

        if ((*arv) != NULL)
            (*arv) = refazBalanco(*arv);

        return 1;
    }

    return 0;
}


void imprime(struct node* arv)
{
    if (arv != NULL)
    {
        printf("%d ", arv->x);
        imprime(arv->esq);
        imprime(arv->dir);
    }
}

int main()
{
    struct node* arvore = NULL;
    int n = 0, remocoes[100], contremocoes = 0;


    while (n >= 0)
    {
        scanf("%d", &n);
        if (n >= 0)
            insereNo(&arvore, n);
    }
    n=0;
    while (n >= 0)
    {
        scanf("%d", &n);
        if (n >= 0)
        {
            remocoes[contremocoes] = n;
            contremocoes++;
        }
    }

    imprime(arvore);

    printf("\n%d\n", altura(arvore));

    for (n = 0; n < contremocoes; n++)
        remover(&arvore, remocoes[n]);

    imprime(arvore);

    printf("\n%d", altura(arvore));

    free(arvore);

    return 0;
}
