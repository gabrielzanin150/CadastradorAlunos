#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    struct node *esq;
    struct node *dir;
    int cor;  // 0 negro 1 rubro
};

struct node* criaTree()
{
    return NULL;
}
struct node* criaNode(int elemento)
{
    struct node* novo =(struct node*)malloc(sizeof(struct node));
    novo->x = elemento;
    novo->esq = novo->dir = NULL;
    novo->cor = 1;
    novo->dir = novo->esq = 0; // filhos recebem nil
    return novo;
}

int alturaNegra(struct node *arv)
{
    if(arv == NULL)
        return -1;
    else if(arv->dir == NULL && arv->esq == NULL)
        return 0;

        int alturaEsq = alturaNegra(arv->esq);
        int alturaDir = alturaNegra(arv->dir);


        if(alturaEsq > alturaDir && arv->cor == 0)
        {
            return alturaEsq + 1;
        }
        else if(alturaEsq < alturaDir && arv->cor == 0)
            return alturaDir + 1;
        else
            return alturaDir + 0;
}

int ArvoreARN(struct node *arv)
{
    if(arv == NULL)
        return 0;

    else if(arv->cor == 1) // condicao 2
        return 0;

    else
    {
    ArvoreARN(arv->dir);
    ArvoreARN(arv->esq);

       if(arv->cor == 1)
       {
          if(arv->esq->cor == 1 || arv->dir->cor == 1)
            return 0;
       }

        if(alturaNegra(arv->dir) != alturaNegra(arv->esq)) // condicao 6
        return 0;
    }
    return 1;
}

void trocaCores(struct node *node)
{
    if(node->cor == 0)
        node->cor = 1;
    else if(node->cor == 1)
        node->cor = 0;
}

struct node* rotaDireita(struct node* node)
{
  struct node *pa, *pb;
    pa = node;

    pb = pa->esq;
    pa->esq = pb->dir;
    pb->dir = pa;
    pa = pb;

    return pb;
}

struct node* rotaEsquerda(struct node* node)
{
 struct node *pa, *pb;
    pa = node;

    pb = pa->dir;
    pa->dir = pb->esq;
    pb->esq = pa;
    pa = pb;

    return pb;
}

int balancaNo(struct node *arv)
{
  if(arv == NULL)
        return 1;

  if(arv->esq->cor == 1) // se A for rubro e esquerdo
  {
        if(arv->dir->cor == 1) // D é rubro, caso 1
        {
            trocaCores(arv->esq); // muda a cor do pai
            trocaCores(arv);      // muda cor do avo
            trocaCores(arv->dir); // muda a cor do tio
        }
        else if(arv->dir->cor == 0) // se D for negro
        {
            if(arv->esq->dir->cor == 1) // caso 2a
            {
              rotaEsquerda(arv->esq);

              rotaDireita(arv);         // caiu no caso 3a
              trocaCores(arv->esq);
              trocaCores(arv);
            }
            else if(arv->esq->esq->cor == 1)// caso 3a
            {
              rotaDireita(arv);
              trocaCores(arv->esq);     // troca cor do pai
              trocaCores(arv);          // troca cor do avo
            }
          }
  } // final do A ser filho esquerdo
  else if(arv->dir->cor == 1) // se A for rubro e direito
  {
      if(arv->esq->cor == 1) // D é rubro, caso 1
      {
          trocaCores(arv->dir); // troca a cor do pai
          trocaCores(arv);      // troca a cor do avo
          trocaCores(arv->esq); // troca a cor do tio
      }
      else if(arv->esq->cor == 0) // D é negro
      {
          if(arv->dir->esq->cor == 1)          // caso 2b
          {
              rotaDireita(arv->dir);

              rotaEsquerda(arv);    // caiu no caso 3b
              trocaCores(arv->dir);
              trocaCores(arv);

          }
          else if(arv->dir->dir->cor == 1)     // caso 3b
          {
              rotaEsquerda(arv);
              trocaCores(arv->dir);   // troca a cor do pai
              trocaCores(arv);         // troca a cor do avo
          }
      }
  }
        return 1;
}

struct node* pesquisa(struct node* arv, int key)
{
 if(arv == NULL || arv->x == key)
        return arv;
 if(arv->x < key)
    return pesquisa(arv->dir, key);
 else
    return pesquisa (arv->esq, key);
}

struct node* insere(struct node *arv,struct node *no)
{
    if(arv == NULL)
    {
       no->cor=0;
       return no;
    }

    if(no->x < arv->x)
        arv->esq = insere(arv->esq, no);
    else if(no->x > arv->x)
        arv->dir = insere(arv->dir, no);

    if(ArvoreARN(arv) == 0)
    {
        balancaNo(arv);
    }
    arv->cor=0;
    return arv;
}

void imprime(struct node* arv)
{
    if (arv != NULL)
    {
        if(arv->cor == 0)
            printf("N%d ", arv->x);
        else if(arv->cor == 1)
            printf("R%d ", arv->x);
        imprime(arv->esq);
        imprime(arv->dir);
    }
}

int main()
{
    int n, i, x;
    struct node* tree = criaTree();

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        tree=insere(tree, criaNode(x));
    }
    if(ArvoreARN(tree) == 1)

    printf("%d\n",alturaNegra(tree));
    imprime(tree);
    return 0;
}
