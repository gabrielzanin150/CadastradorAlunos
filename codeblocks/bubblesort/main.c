#include <stdio.h>
#include <stdlib.h>
void selection(int *v, int n)
{
   int i, j, aux;
   for(i=0; i<n-1; i++)
   {
       for(j=0; j<n-i; j++)
       {
           if(v[j]>v[j+1])
           {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
           }
       }
   }
}

int main()
{
   int *v, i, n;
   scanf("%d", &n);
   v = (int*)malloc(n*sizeof(int));
   for(i=0; i<n; i++)
    scanf("%d", &v[i]);

    selection(v,n);
    for(i=0; i<n; i++)
        printf("%d ",v[i]);
    return 0;
}
