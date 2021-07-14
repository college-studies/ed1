#include <stdio.h>
#define N 10

struct est_list
{
  int lista[N];
  int contador;
};
typedef struct est_list tipo_lista;

//Prototipacao
void inicializaLista(tipo_lista *lst);
void insereInicio(tipo_lista *lst, int valor);
void insereFim(tipo_lista *lst, int valor);
void inserePosicao(tipo_lista *lst, int valor, int posicao);
void imprimeLista(tipo_lista lst);
int removeInicio(tipo_lista *lst);
int removeFim(tipo_lista *lst);
int removePosicao(tipo_lista *lst, int posicao);

int main()
{
  tipo_lista lista;

  inicializaLista(&lista);

  insereFim(&lista, 7);
  insereFim(&lista, 9);

  insereInicio(&lista, 5);
  insereInicio(&lista, 2);

  inserePosicao(&lista, 20, 4);
  inserePosicao(&lista, 50, 5);
  inserePosicao(&lista, 1, 0);
  inserePosicao(&lista, 10, 5);
  inserePosicao(&lista, 3, 2);

  imprimeLista(lista);

  printf("Valor %d removido\n", removeInicio(&lista));
  printf("Valor %d removido\n", removeInicio(&lista));

  printf("Valor %d removido\n", removeFim(&lista));

  printf("Valor %d removido\n", removePosicao(&lista, 4));
  printf("Valor %d removido\n", removePosicao(&lista, 4));

  imprimeLista(lista);

  return 1;
}

void inicializaLista(tipo_lista *lst)
{
  lst->contador = 0;
}

void insereInicio(tipo_lista *lst, int valor)
{
  if (lst->contador < N)
  {
    int i;
    for (i = lst->contador; i > 0; i--)
    {
      lst->lista[i] = lst->lista[i - 1];
    }
    lst->lista[0] = valor;
    lst->contador++;
  }
  else
  {
    printf("ERRO - Lista esta cheia\n");
  }
}

void insereFim(tipo_lista *lst, int valor)
{
  if (lst->contador < N)
  {
    lst->lista[lst->contador++] = valor;
  }
  else
  {
    printf("ERRO Fila esta cheia");
  }
}

void inserePosicao(tipo_lista *lst, int valor, int posicao)
{
  if (lst->contador < N)
  {
    if ((posicao >= 0) && (posicao <= lst->contador))
    {
      //verificar se a posicao === 0 -> chama insere inicio;
      //verificar se a posicao === contador -> chama insere fim
      int i;
      for (i = lst->contador - 1; i >= posicao; i--)
      {
        lst->lista[i + 1] = lst->lista[i];
      }
      lst->lista[i + 1] = valor;
      lst->contador++;
    }
  }
  else
  {
    printf("ERRO - Lista esta cheia\n");
  }
}

void imprimeLista(tipo_lista lst)
{
  printf("LISTA [");

  int i;
  for (i = 0; i < lst.contador; i++)
  {
    printf("%d ", lst.lista[i]);
  }
  printf("]\nContador=%d\n", lst.contador);
}

int removeInicio(tipo_lista *lst)
{
  if (lst->contador > 0)
  {
    int aux, i;
    aux = lst->lista[0];

    //atualiza o posicionamento dos valores no vetor
    for (i = 0; i < lst->contador - 1; i++)
    {
      lst->lista[i] = lst->lista[i + 1];
    }
    lst->contador--;
    return aux;
  }
  else
  {
    printf("ERRO Lista esta vazia\n");
    return -1;
  }
}

int removeFim(tipo_lista *lst)
{
  if (lst->contador > 0)
  {
    return lst->lista[--lst->contador];
  }
  else
  {
    printf("ERRO Lista esta vazia\n");
    return -1;
  }
}

int removePosicao(tipo_lista *lst, int posicao)
{
  if (lst->contador > 0)
  {
    if ((posicao >= 0) && (posicao < lst->contador))
    {
      int aux, i;
      aux = lst->lista[posicao];

      //atualiza o posicionamento dos valores no vetor
      for (i = posicao; i < lst->contador - 1; i++)
      {
        lst->lista[i] = lst->lista[i + 1];
      }
      lst->contador--;
      return aux;
    }
    else
    {
      printf("ERRO Posicao invalida para removacao de valor da lista\n");
      return -1;
    }
  }
  else
  {
    printf("ERRO Lista esta vazia\n");
    return -1;
  }
}