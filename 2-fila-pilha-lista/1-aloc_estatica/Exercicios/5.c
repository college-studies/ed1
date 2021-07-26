#include <stdio.h>
#define N 10
#define M = 2 * N

struct est_lista
{
  int valor[N];
  int cont;
};
typedef struct est_lista Lista;

void inicializa(Lista *lst);
void imprime(Lista lst);

void insere_inicio(Lista *lst, int vl);
void insere_fim(Lista *lst, int vl);
void insere_posicao(Lista *lst, int vl, int pos);

int remove_inicio(Lista *lst);
int remove_fim(Lista *lst);
int remove_posicao(Lista *lst, int pos);

Lista concatenar(Lista lst1, Lista lst2);
Lista ordenacao(Lista lst);

int main()
{

  Lista lst1, lst2, concatenada;

  inicializa(&lst1);
  inicializa(&lst2);
  inicializa(&concatenada);

  insere_fim(&lst1, 4);
  insere_fim(&lst1, 6);
  insere_fim(&lst1, 3);
  insere_fim(&lst1, 6);
  insere_fim(&lst1, 1);

  insere_fim(&lst2, 2);
  insere_fim(&lst2, 5);
  insere_fim(&lst2, 7);
  insere_fim(&lst2, 9);

  imprime(lst1);
  imprime(lst2);

  concatenada = concatenar(lst1, lst2);
  imprime(concatenada);

  concatenada = ordenacao(concatenada);
  imprime(concatenada);

  return 1;
}

void inicializa(Lista *lst)
{
  lst->cont = 0;
}

void imprime(Lista lst)
{
  printf("[ ");
  for (int i = 0; i < lst.cont; i++)
    printf(" [%d] ", lst.valor[i]);
  printf(" ] \n");
}

void insere_inicio(Lista *lst, int vl)
{
  if (lst->cont < N)
  {
    int i;
    for (i = lst->cont; i > 0; i--)
    {
      lst->valor[i] = lst->valor[i - 1];
    }
    lst->valor[0] = vl;
    lst->cont++;
  }
  else
  {
    printf("Erro - Lista Cheia\n");
  }
}

void insere_fim(Lista *lst, int vl)
{
  if (lst->cont < N)
  {
    lst->valor[lst->cont++] = vl;
  }
  else
  {
    printf("Erro - Lista cheia\n");
  }
}

void insere_posicao(Lista *lst, int vl, int pos)
{
  if (lst->cont < N)
  {
    if ((pos >= 0) && (pos <= lst->cont))
    {
      int i;
      for (i = lst->cont - 1; i >= pos; i--)
      {
        lst->valor[i + 1] = lst->valor[i];
      }
      lst->valor[i + 1] = vl;
      lst->cont++;
    }
  }
  else
  {
    printf("Erro - lista cheia\n");
  }
}

int remove_inicio(Lista *lst)
{
  if (lst->cont > 0)
  {
    int aux, i;

    for (i = 0; i < lst->cont - 1; i++)
    {
      lst->valor[i] = lst->valor[i + 1];
    }
    lst->cont--;
    return aux;
  }
  else
  {
    printf("Erro - Lista vazia\n");
    return -1;
  }
}

int remove_fim(Lista *lst)
{
  if (lst->cont > 0)
    return lst->valor[--lst->cont];
  printf("Erro - Lista Vazia\n");
  return -1;
}

int remove_posicao(Lista *lst, int pos)
{
  if (lst->cont > 0)
  {
    if ((pos >= 0) && (pos < lst->cont))
    {
      int aux, i;
      aux = lst->valor[pos];
      for (i = pos; i < lst->cont - 1; i++)
      {
        lst->valor[i] = lst->valor[i + 1];
      }
      lst->cont--;
      return aux;
    }
    else
    {
      printf("Erro - Posicao invalida\n");
      return -1;
    }
  }
  else
  {
    printf("Erro - Lista vazia\n");
    return -1;
  }
}

Lista concatenar(Lista lst1, Lista lst2)
{
  int i;
  Lista resultado;
  inicializa(&resultado);

  for (i = lst2.cont - 1; i >= 0; i--)
  {
    insere_fim(&resultado, lst2.valor[i]);
  }

  for (i = lst1.cont - 1; i >= 0; i--)
  {
    insere_fim(&resultado, lst2.valor[i]);
  }
  return resultado;
}

Lista ordenacao(Lista lst)
{
  int i, j, aux;
  Lista lista_ordenada;

  inicializa(&lista_ordenada);

  for (i = 0; i < lst.cont; i++)

  {
    for (j = 0; j < lst.cont - 1; j++)
    {
      if (lst.valor[j] > lst.valor[j + 1])
      {
        aux = lst.valor[j];
        lst.valor[j] = lst.valor[j + 1];
        lst.valor[j + 1] = aux;
      }
    }
  }

  for (i = lst.cont - 1; i >= 0; i--)
    insere_fim(&lista_ordenada, lst.valor[i]);

  return lista_ordenada;
}