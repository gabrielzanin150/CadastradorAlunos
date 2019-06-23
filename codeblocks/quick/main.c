#include <stdio.h>
#include <stdlib.h>

int particiona(int v[], int inicio, int fim, int tam)
{
    int esq, dir, pivo, aux, i;
    pivo = v[fim];
    esq = inicio;
    dir = fim-1;
    printf("pivo: %d ", pivo);
    printf("\n");
    while(esq <= dir)
    {
        if(v[esq] <= pivo)
            esq++;

        else if(v[dir] > pivo)
            dir--;
        else if( esq <= dir)
        {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
            esq++;
            dir--;
        }
    }

            v[fim] = v[esq];
            v[esq] = pivo;

    for(i = 0; i < tam; i++)
        printf("%d ", v[i]);
    printf("\n");
    return  esq;
}

void quick(int v[], int inicio, int fim, int tam)
{
    if(fim > inicio)
    {
        int pivo;
        pivo = particiona(v, inicio, fim, tam);
        quick(v, inicio, pivo-1, tam);
        quick(v, pivo+1,fim, tam);
    }
}
int main()
{
   int *v,n,i;
    scanf("%d",&n);
    v = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    quick(v,0,n-1,n);
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    return 0;
}
