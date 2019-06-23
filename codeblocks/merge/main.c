#include <stdio.h>
#include <stdlib.h>

void intercalar (int *vet,int *temp, int p, int q, int r, int tam) // realiza a comparacao entre os sub vetores inserindo o vetor auxiliar, apos completar a comparacao repassa para o vetor principal
{
    int  i, j, k=0;
    i = p;
    j = q+1;

    while(i <= q && j <= r) // enquanto estiver percorrendo os 2 sub vetores
    {
        if(vet[i] <= vet[j])  // compara qual valor é menor
            temp[k++] = vet[i++];
        else
            temp[k++] = vet[j++];
    }

    while(i <= q)             // caso a condicao acima tenha acabado, porem o lado esquerdo ainda tenha elementos
        temp[k++] = vet[i++];
    while(j < r+1)             // caso a condicao acima tenha acabado, porem o lado direito ainda tenha elementos
        temp[k++] = vet[j++];

    for(i = p; i <= r; i++)    // copia os elementos do vetor temp para o principal, para dar free posteriormente
        vet[i] = temp[i-p];

     for(i=0;i<tam;i++)        // exibe o vetor a cada chamada da funcao
    {
      printf("%d ",vet[i]);
    }
    printf("\n");

}

void ordenar(int *vet,int *temp, int inicio, int fim, int tam)  // funcao recursiva responsavel pela "quebra" do vetor
{
    int meio;
    if(inicio < fim)     // se ainda existir elementos
    {
        meio = (inicio + fim)/2;  // calcula o meio do vetor onde sera feita a particao
        ordenar(vet, temp, inicio, meio, tam); // a funcao eh chamada recursivamente para o lado esquerdo do vetor
        ordenar(vet, temp, meio+1, fim, tam);   // aqui eh chamada para o lado direito
        intercalar(vet, temp, inicio, meio, fim, tam);
    }
}

int main()
{
    int *merge, *temp,n,i;
    scanf("%d",&n);
    merge = (int*)malloc(n*sizeof(int)); // aloca dinamicamente o vetor principal

    for(i=0; i<n; i++)
        scanf("%d",&merge[i]);

    temp = (int*)malloc(n*sizeof(int));     // aloca dinamicamente o vetor temporario
    ordenar(merge,temp,0,n-1,n);     // chamada da funcao recursiva
    free(temp);
    return 0;
}
