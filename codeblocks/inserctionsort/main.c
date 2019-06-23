#include <stdio.h>
#include <stdlib.h>

void insert(int *v, int n)
{
    int  key, i, j, aux,k;
    for(i=1; i<n; i++)
    {
        key=v[i];
        j=i-1;
        while(j>=0 && key<v[j])
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1]=key;
        for(k=0; k<n; k++)
            printf("%d ",v[k]);
        printf("\n");
    }
}
int main()
{
    int *v, i, n;
    scanf("%d",&n);

    v = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d",&v[i]);
    }
    insert(v,n);
    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    return 0;
}
