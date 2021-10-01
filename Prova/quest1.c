#include <stdio.h>
#include <stdlib.h>

struct estru_no
{
  int valor;
  struct estru_no *prox;
};
typedef struct estru_no tipo_no;

// prototipo
tipo_no *alocaNovoNo(int vl);
void insereInicio(tipo_no **lst, int vl);
void imprimeLista(tipo_no *lst);
void insereOrdenado(tipo_no **lst, int vl);

int main()
{
  tipo_no *lista;
  lista = NULL;

  insereOrdenado(&lista, 1);
  insereOrdenado(&lista, 2);
  insereOrdenado(&lista, 6);
  insereOrdenado(&lista, 4);
  insereOrdenado(&lista, 3);
  insereOrdenado(&lista, 5);
  insereOrdenado(&lista, 7);
  insereOrdenado(&lista, 8);
  insereOrdenado(&lista, 10);
  insereOrdenado(&lista, 9);

  imprimeLista(lista);
}

// Funcao de impressao da lista
void imprimeLista(tipo_no *lst)
{
  printf("LISTA: [ ");
  while (lst != NULL)
  {
    printf("%d ", lst->valor);
    lst = lst->prox;
  }
  printf("]\n");
}

// Funcao que aloca memoria para um tipo_no
tipo_no *alocaNovoNo(int vl)
{
  tipo_no *novo_no;
  novo_no = (tipo_no *)malloc(sizeof(tipo_no));
  novo_no->valor = vl;
  novo_no->prox = NULL;
  return novo_no;
}

//Funcao que insere no inicio da lista
void insereInicio(tipo_no **lst, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  novo_no->prox = (*lst);
  (*lst) = novo_no;
}

// Funcao que insere de forma Ordenada
void insereOrdenado(tipo_no **lst, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  if ((*lst) == NULL)
    (*lst) = novo_no;
  else
  {
    tipo_no *aux, *aux2;
    aux = (*lst);

    if (aux->valor > vl)
      insereInicio(lst, vl);
    else
    {
      while (aux != NULL && aux->valor < vl)
      {
        aux2 = aux;
        aux = aux->prox;
      }
      if (aux != NULL)
      {
        novo_no->prox = aux;
        aux2->prox = novo_no;
      }
      else if (aux == NULL)
        aux2->prox = novo_no;
    }
  }
}