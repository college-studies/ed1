#include <stdio.h>
#include <stdlib.h>

struct estruturaNo
{
  int valor;
  struct estruturaNo *prox;
};
typedef struct estruturaNo tipoNo;

void insereInicio(tipoNo **lista, int vl);
void imprimeLista(tipoNo *lista);

int main()
{
  tipoNo *lista;
  lista = NULL;

  insereInicio(&lista, 10);
  insereInicio(&lista, 20);
  insereInicio(&lista, 1);
  insereInicio(&lista, 4);

  imprimeLista(lista);

  return 1;
}

void insereInicio(tipoNo **lista, int vl)
{
  tipoNo *novo, *aux;
  novo = (tipoNo *)malloc(sizeof(tipoNo));
  aux = (*lista);

  if (novo != NULL)
  {
    if ((*lista) == NULL)
    {
      novo->valor = vl;
      novo->prox = novo;
      (*lista) = novo;
    }
    else
    {
      novo->valor = vl;
      novo->prox = (*lista);
      while (aux->prox != (*lista))
      {
        aux = aux->prox;
      }
      aux->prox = novo;
      (*lista) = novo;
    }
  }
}

void imprimeLista(tipoNo *lista)
{
  int i;
  tipoNo *aux;
  if (lista == NULL)
  {
    printf("ERRO - LISTA VAZIA");
  }
  else
  {
    aux = lista;
    printf("Lista Circular: [ ");
    while (aux->prox != lista)
    {
      printf("%d ", aux->valor);
      i++;
      aux = aux->prox;
    }
    printf("%d ]\n", aux->valor);
  }
}