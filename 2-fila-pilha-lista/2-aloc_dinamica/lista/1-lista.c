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
void insereFim(tipo_no **lst, int vl);
void inserePosicao(tipo_no **lst, int vl, int pos);
int removeInicio(tipo_no **lst);
int removeFim(tipo_no **lst);
int removePosicao(tipo_no **lst, int pos);
void imprimeLista(tipo_no *lst);

int main()
{
  tipo_no *lista;
  lista = NULL;

  insereFim(&lista, 20);
  insereFim(&lista, 30);
  insereFim(&lista, 40);

  insereInicio(&lista, 5);
  insereInicio(&lista, 3);
  insereInicio(&lista, 1);
  insereInicio(&lista, 0);

  insereFim(&lista, 10);

  imprimeLista(lista);

  printf("Valor removido = %d\n", removeInicio(&lista));
  printf("Valor removido = %d\n", removeInicio(&lista));
  printf("Valor removido = %d\n", removeFim(&lista));
  printf("Valor removido = %d\n", removeFim(&lista));

  imprimeLista(lista);

  inserePosicao(&lista, 1, 0);
  inserePosicao(&lista, 10, 3);
  inserePosicao(&lista, 50, 6);
  inserePosicao(&lista, 100, 8);

  imprimeLista(lista);

  printf("Valor removido = %d\n", removePosicao(&lista, 0));
  printf("Valor removido = %d\n", removePosicao(&lista, 2));
  printf("Valor removido = %d\n", removePosicao(&lista, 4));
  printf("Valor removido = %d\n", removePosicao(&lista, 4));

  imprimeLista(lista);

  return 1;
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

// Funcao que insere no final da lista
void insereFim(tipo_no **lst, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);

  if ((*lst) == NULL)
  {
    (*lst) = novo_no;
  }
  else
  {
    tipo_no *aux;
    aux = (*lst);
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

// Funcao que remove o primeiro no da lista
int removeInicio(tipo_no **lst)
{
  tipo_no *aux;
  int vl;

  if ((*lst) != NULL)
  {
    aux = (*lst);
    vl = (*lst)->valor;
    (*lst) = (*lst)->prox;
    free(aux);
    return vl;
  }
  else
  {
    return -1;
  }
}

// Funcao que remove o ultimo no da lista
int removeFim(tipo_no **lst)
{
  tipo_no *aux, *aux2;
  int vl;

  if ((*lst) != NULL)
  {
    aux = (*lst);
    while (aux->prox != NULL)
    {
      aux2 = aux;
      aux = aux->prox;
    }
    vl = aux->valor;
    free(aux);
    aux2->prox = NULL;
    return vl;
  }
  else
  {
    return -1;
  }
}

// Funcao que insere por posicao
void inserePosicao(tipo_no **lst, int vl, int pos)
{
  tipo_no *novo_no, *aux, *aux2;
  int contador;

  if (pos == 0)
  {
    insereInicio(lst, vl);
  }
  else
  {
    aux = (*lst);
    contador = 0;
    while ((aux != NULL) && (contador < pos))
    {
      aux2 = aux;
      aux = aux->prox;
      contador++;
    }
    if ((aux != NULL) && (contador == pos))
    {
      novo_no = alocaNovoNo(vl);
      novo_no->prox = aux;
      aux2->prox = novo_no;
    }
    else if ((aux == NULL) && (contador == pos))
    {
      novo_no = alocaNovoNo(vl);
      aux2->prox = novo_no;
    }
    else
    {
      printf("[ERRO] - POSICAO (%d) INVALIDA PARA INSERCAO DE VALOR (%d) NA LISTA\n", pos, vl);
    }
  }
}

// Funcao que remove no em posicao especifica
int removePosicao(tipo_no **lst, int pos)
{
  tipo_no *aux, *aux2;
  int contador, vl;

  if ((*lst) != NULL)
  {
    if (pos == 0)
    {
      return removeInicio(lst);
    }
    else
    {
      aux = (*lst);
      contador = 0;
      while ((aux != NULL) && (contador < pos))
      {
        aux2 = aux;
        aux = aux->prox;
        contador++;
      }
      if (aux != NULL)
      {
        vl = aux->valor;
        aux2->prox = aux->prox;
        free(aux);
        return vl;
      }
      else
      {
        printf("ERRO - POSICAO (%d) Invalida para remocao\n", pos);
        return -1;
      }
    }
  }
  else
  {
    printf("ERRO - Lista esta vazia\n");
    return -1;
  }
}