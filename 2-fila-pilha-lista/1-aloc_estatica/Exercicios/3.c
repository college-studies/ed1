#include <stdio.h>
#include <stdlib.h>

#define N 100

struct estruturaFilaCircular
{
  int fila[N];
};
typedef struct estruturaFilaCircular FilaCircular;

void inicializa_fila(FilaCircular *fl);
void insere_elemento(FilaCircular *fl, int valor);
int fila_esta_cheia(FilaCircular fl);
int fila_esta_vazia(FilaCircular fl);
void imprime_fila(FilaCircular fl);
int remove_elemento(FilaCircular *fl);

int main()
{
  FilaCircular fila_circular;
  inicializa_fila(&fila_circular);

  int i = 0;
  while (i < N)
  {
    int r = rand() % 20;
    insere_elemento(&fila_circular, r);
    i++;
  }

  imprime_fila(fila_circular);

  printf("\nRemove: [%d]\n\n", remove_elemento(&fila_circular));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila_circular));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila_circular));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila_circular));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila_circular));

  imprime_fila(fila_circular);

  return 0;
}

void inicializa_fila(FilaCircular *fl)
{
  fl->fila[0] = 2;
  fl->fila[1] = 2;
}

void imprime_fila(FilaCircular fl)
{
  int i;
  printf("FILA = [");
  for (i = fl.fila[0]; i < fl.fila[1]; i++)
  {
    printf(" [%d] ", fl.fila[i]);
  }
  printf("]\n");
}

int fila_esta_cheia(FilaCircular fl)
{
  if (fl.fila[0] == N)
    return 1;
  return 0;
}

int fila_esta_vazia(FilaCircular fl)
{
  if (fl.fila[1] == fl.fila[0])
    return 1;
  return 0;
}

void insere_elemento(FilaCircular *fl, int valor)
{
  if (fila_esta_cheia(*fl))
  {

    if (fl->fila[0] == 2)
      printf("ERRO - Fila Cheia !! \n");

    int i;
    int vl = fl->fila[1] - fl->fila[0];
    for (i = 2; i < vl + 2; i++)
    {
      fl->fila[i] = fl->fila[fl->fila[0] + i - 2];
    }

    fl->fila[0] = 2;
    int fim_da_fila = vl + 2;
    fl->fila[fim_da_fila] = valor;
    fl->fila[i] = ++fim_da_fila;
  }
  else
  {
    int fim_da_fila = fl->fila[1];
    fl->fila[fim_da_fila] = valor;
    fl->fila[1] = ++fim_da_fila;
  }
}

int remove_elemento(FilaCircular *fl)
{
  if (fila_esta_vazia(*fl))

    printf("ERRO - Lista Vazia !!\n");

  int valor = fl->fila[fl->fila[0]];
  fl->fila[0] = fl->fila[0] + 1;
  return valor;
}