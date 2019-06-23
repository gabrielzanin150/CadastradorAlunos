#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int tam;
    float *apontador;
}baldes;

void bubble(float *v, int n)
{
    int i, j;
    float aux;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(v[j]>v[j+1])
            {
                aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void bucket(float *v, int nro_baldes, int n)
{
    int i,j, mult;
    baldes *bucket;
    bucket=malloc(nro_baldes*sizeof(baldes));

    for(i=0; i<nro_baldes; i++)
    {
        bucket[i].tam=0;
    }

    for(i=0; i<n; i++)
    {
        mult=(v[i]*nro_baldes);
        if(mult > nro_baldes-1)
        {
            mult=nro_baldes-1;
        }

        if(bucket[mult].tam==0)
        {
            bucket[mult].apontador=(float*)malloc(n*sizeof(float));
        }
        bucket[mult].apontador[bucket[mult].tam]=v[i];
        bucket[mult].tam++;
    }

    for(i=0; i<nro_baldes; i++)
    {
        if(bucket[i].tam>0)
        {
            printf("%d-> ",i);
            for(j=0; j<bucket[i].tam; j++)
            printf("%7.3f",bucket[i].apontador[j]);
            printf("\n");
            }
    }
    printf("\n");

    for(i=0; i<nro_baldes; i++)
    {
        if(bucket[i].tam>0)
        {
            bubble(bucket[i].apontador,bucket[i].tam);
        }
    }

   for(i=0; i<nro_baldes; i++)
    {
        if(bucket[i].tam>0)
        {
            printf("%d-> ",i);
            for(j=0; j<bucket[i].tam; j++)
            printf("%7.3f",bucket[i].apontador[j]);
            printf("\n");
            }
    }
    printf("\n");

    int pos=0;
    for(i=0; i<nro_baldes; i++)
    {
        if(bucket[i].tam>0)
            for(j=0; j<bucket[i].tam; j++)
        {
            v[pos]=bucket[i].apontador[j];
            pos++;
        }

    }
}
int main()
{
    float *v;
    int i,n,nbaldes;
    scanf("%d", &n);
    v = malloc(n*sizeof(int));
    scanf("%d", &nbaldes);
    for(i=0; i<n; i++)
    {
        scanf("%f",&v[i]);
    }

    bucket(v,nbaldes,n);

    for(i = 0; i < n; i++)
        printf("%7.3f ", v[i]);
    return 0;
}
