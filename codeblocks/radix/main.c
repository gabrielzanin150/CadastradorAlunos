#include <stdio.h>
#include <stdlib.h>

int maximo(int v[], int tam)
{
    int i = 0, max=v[0];

  for(i=0; i<tam; i++)
  {
      if(v[i]>max)
        max=v[i];
  }
  return max;
}
void countingSort(int v[], int tam){
    int i, max;
    max = maximo(v,tam);

  int * aux = calloc(max,sizeof(int));

  for(i = 0; i < tam; i ++){
    aux[v[i]]++;
  }

  int num = 0;
  i = 0;

  while(i <= tam){
    while(aux[num] > 0){
      v[i] = num;
      aux[num]--;
      i++;
      if(i > tam)
      {
        break;
      }
    }
    num++;
  }
    for(i = 0; i < tam; i++)
        printf("%d ", v[i]);
}


int main(){

  int *v, i, n;
  scanf("%d", &n);
  v = malloc(n*sizeof(int));
  for(i=0; i<n; i++)
    scanf("%d",&v[i]);

    countingSort(v,n);
  return 0;
}
