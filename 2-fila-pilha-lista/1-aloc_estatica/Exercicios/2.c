// Aluno - Fillipe Augusto de Siqueira Gomes

// Ao inves de termos que sempre monitorar e deslocar os elementos no momento de uma remoção poderemos
// ir mantendo a adicao dos elementos ate a ultima posicao do vetor e só quando estiver com a ultima
// posicao do vetor ocupada é que iremos deslocar TODOS os elementos de uma unica vez, dessa forma
// diminuindo a quantidade de deslocamentos a cada operação.

#include <stdio.h>
#include <stdlib.h>

#define N 10

struct est_fila
{
  int fila[N];
  int cont;
  int inicio;
};
typedef struct est_fila tipo_fila;

void inicializa_fila(tipo_fila *fl);
void imprime_fila(tipo_fila fl);
void insere_elemento(tipo_fila *fl, int valor);
int remove_elemento(tipo_fila *fl);

int main()
{
  tipo_fila fila;
  inicializa_fila(&fila);

  int i = 0;
  while (i < N)
  {
    int r = rand() % 20;
    insere_elemento(&fila, r);
    i++;
  }

  imprime_fila(fila);

  printf("\nRemove: [%d]\n\n", remove_elemento(&fila));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila));
  printf("\nRemove: [%d]\n\n", remove_elemento(&fila));

  imprime_fila(fila);

  insere_elemento(&fila, 1);
  insere_elemento(&fila, 2);
  insere_elemento(&fila, 3);

  imprime_fila(fila);

  return 0;
}

void inicializa_fila(tipo_fila *fl)
{
  fl->cont = 0;
  fl->inicio = 0;
}

void imprime_fila(tipo_fila fl)
{
  int i;
  printf("Fila: [ ");
  for (i = fl.inicio; i < fl.cont; i++)
  {
    printf("[%d] ", fl.fila[i]);
  }
  printf("]\n");
}

void insere_elemento(tipo_fila *fl, int valor)
{
  if (fl->cont == N) // checa se a fila esta cheia
  {

    if (fl->inicio == 0)
      printf("ERRO - Fila Cheia \n");
    else
    {
      int i = 0;
      int vl = fl->cont - fl->inicio + 1;

      while (i < vl)
      {
        fl->fila[i] = fl->fila[fl->inicio + i];
        i++;
      }

      fl->inicio = 0;
      fl->fila[--vl] = valor;
      fl->cont = ++vl;
    }
  }
  else
  {
    fl->fila[fl->cont] = valor;
    fl->cont++;
  }
}

int remove_elemento(tipo_fila *fl)
{
  if (fl->cont == fl->inicio) // checa se a fila esta vazia
  {
    printf("ERRO - Lista vazia\n");
    return 0;
  }
  else
  {
    int vl = fl->fila[fl->inicio];
    fl->inicio++;

    return vl;
  }
}
