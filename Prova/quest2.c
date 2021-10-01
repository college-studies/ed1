
/*** Inclusao das bibliotecas ***/
#include <stdio.h>
#include <stdlib.h>

/*** Definicao da estrutura ***/
struct estruturaNo
{
  int dado;
  struct estruturaNo *ant;
  struct estruturaNo *prox;
};
typedef struct estruturaNo tipoNo;

/*** Prototipacao das funcoes ***/
void insereInicio(tipoNo **, int);
void insereFim(tipoNo **, int);
void inserePosicao(tipoNo **, int, int);
void imprimeListaDup(tipoNo *);
void retira_maiores(tipoNo **lst, int k);

int main()
{
  tipoNo *lista;
  lista = NULL;

  insereInicio(&lista, 10);
  insereInicio(&lista, 5);
  insereFim(&lista, 30);
  insereFim(&lista, 50);

  imprimeListaDup(lista);

  retira_maiores(&lista, 10);

  imprimeListaDup(lista);

  return 1;
}

// Imprime lista
void imprimeListaDup(tipoNo *lst)
{
  printf("Lista DUP: [");
  while (lst != NULL)
  {
    printf("%d ", lst->dado);
    lst = lst->prox;
  }
  printf("]\n");
}

//Funcao que insere no inicio da lista duplamente encadeada
void insereInicio(tipoNo **lst, int valor)
{
  tipoNo *novoNo;

  novoNo = (tipoNo *)malloc(sizeof(tipoNo));
  novoNo->dado = valor;
  novoNo->ant = NULL;
  novoNo->prox = (*lst);
  if ((*lst) != NULL)
    (*lst)->ant = novoNo;
  (*lst) = novoNo;
}

//Funcao que insere no fim da lista duplamente encadeada
void insereFim(tipoNo **lst, int valor)
{
  tipoNo *aux, *novoNo;

  novoNo = (tipoNo *)malloc(sizeof(tipoNo));
  novoNo->dado = valor;
  novoNo->prox = NULL;
  novoNo->ant = NULL;

  if ((*lst) == NULL)
  {
    (*lst) = novoNo;
  }
  else
  {
    aux = (*lst);
    while (aux->prox != NULL)
      aux = aux->prox;
    novoNo->ant = aux;
    aux->prox = novoNo;
  }
}

//Funcao que insere um novo valor em uma posicao especifica da lista duplamente encadeada
void inserePosicao(tipoNo **lst, int valor, int pos)
{
  tipoNo *aux, *novoNo;
  int cont;
  if (pos == 0)
  {
    insereInicio(lst, valor);
  }
  else
  {
    cont = 0;
    aux = (*lst);
    while ((aux != NULL) && (cont < pos))
    {
      aux = aux->prox;
      cont++;
    }
    if ((aux == NULL) && (cont == pos))
    {
      insereFim(lst, valor);
    }
    else if ((aux != NULL) && (cont == pos))
    {
      novoNo = (tipoNo *)malloc(sizeof(tipoNo));
      novoNo->dado = valor;
      novoNo->prox = aux;
      novoNo->ant = aux->ant;
      aux->ant->prox = novoNo;
      aux->ant = novoNo;
    }
  }
}

void retira_maiores(tipoNo **lst, int k)
{

  if ((*lst) != NULL)
  {

    tipoNo *aux = (*lst);

    aux = (*lst);
    while (aux != NULL)
    {
      if (aux->dado > k)
      {
        if (aux->ant == NULL)
        {
          (*lst) = NULL;
        }
        else
        {
          aux->ant->prox = aux->prox;

          if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
          free(aux);
        }
      }
      aux = aux->prox;
    }
  }
}
