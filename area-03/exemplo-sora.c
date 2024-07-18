/*Programa para inserir dados no fim de uma lista simplemente
encadeada e imprimir a lista. 
No nodo da lista teremos um dado do inteiro */
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
	int dado;
	struct nodo *prox;
} no;

void cria_lista (no **prim)
{
	*prim = NULL;
}

void insere_fim (no **prim, int num)
{
	no *p, *lista;
	p = *prim;
	lista = (no *) malloc (sizeof (no));
	if (lista == NULL)
	{
	  	printf ("\n Nao conseguiu alocar endereco");
	}
	else
	{
		lista->dado = num;
	    lista->prox = NULL;
		if (*prim == NULL)
		{
			
			*prim = lista;
		}
		else
		{
		   while (p->prox != NULL)
		   {
		      p = p->prox;
		   }
		    p->prox = lista;
		}
	     	
    }
}
		
void imprime_lista (no *prim)
{
	no *p = prim;
	if (prim == NULL)
	{
		printf ("\nLista Vazia");
	}
	else
	{
	do
		{
		    printf ("\n Valor %d", p->dado);
			p = p->prox;
	    } while (p != NULL);
		
	}
}

main()
{
	no *primeiro;
	
	int valor;
	cria_lista(&primeiro);
	if (primeiro == NULL)
	{
		printf ("Criou lista vazia");
		
	}
	printf ("\ndigite um valor");
	scanf ("%d", &valor);
	while (valor != 0)
	{
	   	insere_fim (&primeiro, valor);
		
	    printf ("\ndigite um valor");
	    scanf ("%d", &valor); 
    }
    imprime_lista (primeiro);
}