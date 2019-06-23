#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    struct node *esq;
    struct node *dir;
    int cor;  // 0 negro 1 rubro
};


struct node* criaNode(int elemento)
{
    struct node* novo =(struct node*)malloc(sizeof(struct node));
    novo->x = elemento;
    novo->esq = novo->dir = NULL;
    novo->cor = 1;
    return novo;
}

int alturaNegra(struct node *arv)
{
    if(arv == NULL)
        return 0;
    else
    {
        int alturaEsq = alturaNegra(arv->esq);
        int alturaDir = alturaNegra(arv->dir);


        if(alturaEsq > alturaDir )
        {
            if(arv->cor == 0)
              return alturaEsq + 1;
            else
              return alturaEsq + 0;
        }
        else
        {
            if(arv->cor == 0)
                return alturaDir + 1;
            else
                return alturaDir + 0;
        }

    }
}

int ArvoreARN(struct node *arv, struct node *raiz)
{
    if(arv == NULL)
        return 0;

    if(raiz->cor == 1)
        return 0;
    if(arv->cor!=1 && arv->cor!=0)
        return 0;

    else
    {
    ArvoreARN(arv->dir,raiz);
    ArvoreARN(arv->esq,raiz);

       if(arv->cor == 1)
       {
          if(arv->esq->cor == 1 || arv->dir->cor == 1)
            return 0;
       }

        if(alturaNegra(arv->dir) != alturaNegra(arv->esq))
        return 0;
    }
    return 1;
}

void trocaCores(struct node **node)
{
    if((*node)->cor == 0)
        (*node)->cor = 1;
    else if((*node)->cor == 1)
        (*node)->cor = 0;
}

void rotaDireita(struct node** node)
{
  struct node *pb;


    pb = (*node)->esq;
    (*node)->esq = pb->dir;
    pb->dir = (*node);
    (*node) = pb;

}

void rotaEsquerda(struct node** node)
{
 struct node *pb;

    pb = (*node)->dir;
    (*node)->dir = pb->esq;
    pb->esq = (*node);
    (*node) = pb;
}

void balancaNo(struct node **arv, struct node *raiz)
{
     if(*arv==NULL)
        return;
     if((*arv)->esq!=NULL && (*arv)->esq->cor == 1 )
     {
        if((*arv)->esq->esq!=NULL && (*arv)->esq->esq->cor == 1)
         {
            if ((*arv)->dir==NULL || (*arv)->dir->cor == 0 )
            {
                 trocaCores(&(*arv));
                 trocaCores(&(*arv)->esq);
                 rotaDireita(&(*arv));
            }
            else if((*arv)->dir->cor == 1 )
            {
                if(*arv != raiz)
                trocaCores(&(*arv));
                trocaCores(&(*arv)->dir);
                trocaCores(&(*arv)->esq);
            }
         }
         else if((*arv)->esq->dir!=NULL && (*arv)->esq->dir->cor == 1)
         {
            if ((*arv)->dir==NULL || (*arv)->dir->cor == 0 )
            {

                 rotaEsquerda(&(*arv)->esq);
                 trocaCores(&(*arv));
                 trocaCores(&(*arv)->esq);
                 rotaDireita(&(*arv));
            }
            else if((*arv)->dir->cor == 1 )
            {
                if(*arv != raiz)
                trocaCores(&(*arv));
                trocaCores(&(*arv)->dir);
                trocaCores(&(*arv)->esq);
            }
         }
     }

      if((*arv)->dir!=NULL && (*arv)->dir->cor == 1 )
     {
         if((*arv)->dir->esq!=NULL &&(*arv)->dir->esq->cor == 1)
         {
            if ((*arv)->esq==NULL || (*arv)->esq->cor == 0 )
            {
                 rotaDireita(&(*arv)->dir);
                 trocaCores(&(*arv));
                 trocaCores(&(*arv)->dir);
                 rotaEsquerda(&(*arv));
            }

            else if((*arv)->esq->cor == 1 )
            {
                if(*arv != raiz)
                trocaCores(&(*arv));
                trocaCores(&(*arv)->dir);
                trocaCores(&(*arv)->esq);
            }
         }
         else if((*arv)->dir->dir!=NULL && (*arv)->dir->dir->cor == 1)
         {
            if ((*arv)->esq==NULL || (*arv)->esq->cor == 0 )
            {
                 trocaCores(&(*arv));
                 trocaCores(&(*arv)->dir);
                 rotaEsquerda(&(*arv));
            }
            else if((*arv)->esq->cor == 1 )
            {
                if(*arv != raiz)
                    trocaCores(&(*arv));
                trocaCores(&(*arv)->dir);
                trocaCores(&(*arv)->esq);
            }
         }
     }
}

void insere(struct node **arv, struct node* raiz, int key)
{

    if(key < (*arv)->x)
    {
        if((*arv)->esq == NULL)
        {
            (*arv)->esq = criaNode(key);
        }
        else
            insere(&(*arv)->esq,raiz,key);

    }
    else if(key > (*arv)->x)
    {
        if((*arv)->dir == NULL)
            (*arv)->dir = criaNode(key);
        else
            insere(&(*arv)->dir,raiz,key);
    }
            balancaNo(&(*arv),raiz);
}

void imprime(struct node* arv)
{
    printf("(");
    if (arv != NULL)
    {
        if(arv->cor == 0)
            printf("N%d", arv->x);
        else if(arv->cor == 1)
            printf("R%d", arv->x);
        imprime(arv->esq);
        imprime(arv->dir);
    }
    printf(")");
}

int main()
{
    int n, i, x;
    struct node* tree = NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(tree == NULL)
        {
            tree=criaNode(x);
            trocaCores(&tree);
        }
        else
            insere(&tree, tree, x);
    }

    printf("%d\n",alturaNegra(tree));
    imprime(tree);
    return 0;
}
