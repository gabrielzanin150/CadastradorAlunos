#include <stdio.h>
#include <stdlib.h>

void bubble(int v[], int n)
{
    int i, j, aux, k;
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=i; j--)
        {
            if(v[j]>v[j-1])
            {
                aux=v[j];
                v[j]=v[j-1];
                v[j-1]=aux;
            }
        }
        for(k=0; k<n; k++)
            printf("%d ",v[k]);
        printf("\n");
    }
}

int main()
{
    int i,n,*v;
    scanf("%d", &n);
    v=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d", &v[i]);
        bubble(v,n);
}
