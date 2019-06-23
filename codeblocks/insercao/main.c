#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct No
{
	int			fb;
	struct No*	esq;
	int			val;
	struct No*	dir;
};

int AVL_Altura(struct No* arvore)
{
	if (arvore == NULL)
		return -1;
	else if (arvore->esq == NULL && arvore->dir == NULL)
		return 0;
	else
	{
		int alt_esq = AVL_Altura(arvore->esq);
		int alt_dir = AVL_Altura(arvore->dir);

		if (alt_esq > alt_dir)
			return 1 + alt_esq;
		else
			return 1 + alt_dir;
	}
}

void AVL_CalculaFB(struct No* arvore)
{
	if (arvore->esq == NULL && arvore->dir == NULL)
		arvore->fb = 0;
	else
		arvore->fb = AVL_Altura(arvore->esq) - AVL_Altura(arvore->dir);
}

struct No* AVL_CriaNo(int valor)
{
	struct No* novo_no = (struct No*) malloc(sizeof(struct No));
	novo_no->fb = 0;
	novo_no->esq = NULL;
	novo_no->val = valor;
	novo_no->dir = NULL;
	return novo_no;
}

struct No* AVL_Pesquisa(struct No* arvore, int valor)
{
	if (arvore == NULL)
		return NULL;
	else if (valor == arvore->val)
		return arvore;
	else if (valor < arvore->val)
		return AVL_Pesquisa(arvore->esq, valor);
	else
		return AVL_Pesquisa(arvore->dir, valor);
}

struct No* AVL_Rebalanceia(struct No* arvore)
{
	AVL_CalculaFB(arvore); // Calcula o fator de balanceamento

	struct No* filho = NULL;
	struct No* neto = NULL;

	if (arvore->fb >= - 1 && arvore->fb <= 1) // Caso nenhuma rotação seja necessária...
		return arvore; // Não alteramos a árvore
	else if (arvore->fb > 1) // Se a subárvore esquerda for maior...
	{
		filho = arvore->esq;

		if (filho->fb >= 0)	// Rotação LL
		{
			arvore->esq = filho->dir;
			filho->dir = arvore;
			AVL_CalculaFB(arvore);
			AVL_CalculaFB(filho);
			return filho;
		}
		else				// Rotação LR
		{
			neto = filho->dir;
			filho->dir = neto->esq;
			neto->esq = filho;
			arvore->esq = neto->dir;
			neto->dir = arvore;
			AVL_CalculaFB(arvore);
			AVL_CalculaFB(filho);
			AVL_CalculaFB(neto);
			return neto;

		}
	}
	else if (arvore->fb < -1) // Se a subárvore direta for maior...
	{
		filho = arvore->dir;

		if (filho->fb <= 0)	// Rotação RR
		{
			arvore->dir = filho->esq;
			filho->esq = arvore;
			AVL_CalculaFB(arvore);
			AVL_CalculaFB(filho);
			return filho;
		}
		else				// Rotação RL
		{
			neto = filho->esq;
			filho->esq = neto->dir;
			neto->dir = filho;
			arvore->dir = neto->esq;
			neto->esq = arvore;
			AVL_CalculaFB(arvore);
			AVL_CalculaFB(filho);
			AVL_CalculaFB(neto);
			return neto;
		}
	}

	return NULL; // Retorno para suprimir warning do GCC - nunca é alcançado
}

int AVL_Insere(struct No** arvore, int valor)
{
	if ((*arvore) == NULL)
	{
		*arvore = AVL_CriaNo(valor);
		return 1;
	}
	else if (AVL_Pesquisa(*arvore, valor) == NULL)
	{
		if (valor < (*arvore)->val) // Se o valor for menor que o do nó atual...
		{
			if ((*arvore)->esq == NULL)
				(*arvore)->esq = AVL_CriaNo(valor);
			else
				AVL_Insere(&(*arvore)->esq, valor);
		}
		else if (valor > (*arvore)->val) // Se o valor for maior que o do nó atual...
		{
			if ((*arvore)->dir == NULL)
				(*arvore)->dir = AVL_CriaNo(valor);
			else
				AVL_Insere(&(*arvore)->dir, valor);
		}

		(*arvore) = AVL_Rebalanceia(*arvore);

		return 1;
	}

	return 0;
}

int AVL_Remove(struct No** arvore, int valor)
{
	if (arvore != NULL && AVL_Pesquisa(*arvore, valor) != NULL)
	{
		if (valor == (*arvore)->val)
		{
			struct No* aux = NULL;
			if ((*arvore)->dir != NULL)
			{
				struct No** menor_direita = &(*arvore)->dir;
				while ((*menor_direita)->esq != NULL)
					menor_direita = &(*menor_direita)->esq;
				aux = *menor_direita;
				if (aux->dir != NULL)
					(*menor_direita) = aux->dir;
				else
					(*menor_direita) = NULL;
				(*arvore)->val = aux->val;
				free(aux);
			}
			else if ((*arvore)->esq != NULL)
			{
				aux = (*arvore)->esq;
				(*arvore)->val = (*arvore)->esq->val;
				(*arvore)->esq = NULL;
				free(aux);
			}
			else
			{
				free((*arvore));
				(*arvore) = NULL;
			}
		}
		else if (valor < (*arvore)->val)
		{
			AVL_Remove(&(*arvore)->esq, valor);
		}
		else
		{
			AVL_Remove(&(*arvore)->dir, valor);
		}

		if ((*arvore) != NULL)
			(*arvore) = AVL_Rebalanceia(*arvore);

		return 1;
	}

	return 0;
}

void AVL_PreOrdem(struct No* arvore)
{
	if (arvore != NULL)
	{
		printf("%d ", arvore->val);
		AVL_PreOrdem(arvore->esq);
		AVL_PreOrdem(arvore->dir);
	}
}

int main()
{
	struct No* AVL = NULL;
	int numero = 0, n_remocoes = 0, remocoes[128];

	while (numero >= 0)
	{
		scanf("%d", &numero);
		if (numero >= 0)
			AVL_Insere(&AVL, numero);
	}

	numero = 0;

	while (numero >= 0)
	{
		scanf("%d", &numero);
		if (numero >= 0)
		{
			remocoes[n_remocoes] = numero;
			n_remocoes++;
		}
	}

	AVL_PreOrdem(AVL);
	printf("\n%d\n", AVL_Altura(AVL));

	for (numero = 0; numero < n_remocoes; numero++)
	{
		AVL_Remove(&AVL, remocoes[numero]);
	}

	AVL_PreOrdem(AVL);
	printf("\n%d\n", AVL_Altura(AVL));

	free(AVL);

	return 0;
}
