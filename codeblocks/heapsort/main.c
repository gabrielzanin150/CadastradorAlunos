#include<stdio.h>
#include<stdlib.h>

void refaz(int heap[],int i)
{
	int j,temp,n,acabou=0;
	n=heap[0];

	while(2*i<=n && acabou==0) // enquanto tiver filho
	{
		j=2*i;	//j aponta para o filho esquerdo
		if(j+1<=n && heap[j+1] > heap[j]) // se tiver filho direito e ele for maior que o esquerdo ele que sera trocado
			j=j+1;
		if(heap[i] > heap[j])  // se a raiz for maior que o filho maior acaba
			acabou=1;
		else
		{
			temp=heap[i];  // senao for eh feita a troca e continua
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
        }
        for(i=1;i<=n;i++)
            printf("%d ",heap[i]);
        printf("\n");
	}
}

void criaHeap(int heap[])
{
	int i,n,j;
	n=heap[0]; //numero de elementos
	for(i=n/2;i>=1;i--)
    {
		refaz(heap,i);
    }
}

void heapsort(int heap[])
{
    int ultimo,temp,j;
    while(heap[0] > 1) // enquanto o tamanho do vetor for mairo que 1
	{
		//troca o ultimo com a raiz
		ultimo=heap[0];
		temp=heap[1];
		heap[1]=heap[ultimo];
		heap[ultimo]=temp;
		heap[0]--;
		refaz(heap,1);
	//	for(j=1;j<=heap[0];j++)
      //      printf("%d ",heap[j]);
     //   printf("\n");

	}

}
int main()
{
	int *heap,n,i,j;
	scanf("%d",&n);
    heap = (int*)malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);
	// cria o heap
	heap[0]=n;   // o primeiro elemento do vetor eh o seu tamanho

	criaHeap(heap);
    for(j=1;j<=n;j++)
		printf("%d ",heap[j]);
    printf("\n");
   // heapsort(heap);

	//for(i=1;i<=n;i++)              // imprime ordenado
	//	printf("%d ",heap[i]);
	return 0;
}
