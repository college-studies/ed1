#include <stdio.h>
#define N 10

struct est_pilha
{
  int pilha[N];
  int contador;
};
typedef struct est_pilha tipo_pilha;

//Prototipacao
void inicializaPilha(tipo_pilha *pl);
void empilha(tipo_pilha *pl, int valor);
int desempilha(tipo_pilha *pl);
int topo(tipo_pilha pl);
void imprimePilha(tipo_pilha pl);

int main()
{
  tipo_pilha pilha;

  inicializaPilha(&pilha);

  empilha(&pilha, 7);
  empilha(&pilha, 1);
  empilha(&pilha, 9);
  printf("%d desempilhado\n", desempilha(&pilha));
  empilha(&pilha, 5);
  empilha(&pilha, 4);

  printf("%d desempilhado\n", desempilha(&pilha));

  imprimePilha(pilha);

  return 1;
}

void inicializaPilha(tipo_pilha *pl)
{
  pl->contador = 0;
}

void empilha(tipo_pilha *pl, int valor)
{
  if (pl->contador < N)
  {
    pl->pilha[pl->contador++] = valor;
  }
  else
  {
    printf("ERRO - Pilha esta cheia\n");
  }
}

int desempilha(tipo_pilha *pl)
{
  if (pl->contador > 0)
  {
    return pl->pilha[--pl->contador];
  }
  else
  {
    printf("ERRO - pilha esta vazia\n");
    return -1;
  }
}

int topo(tipo_pilha pl)
{
  if (pl.contador > 0)
  {
    return pl.pilha[pl.contador - 1];
  }
  else
  {
    printf("ERRO - Pilha esta vazia!\n");
    return -1;
  }
}

void imprimePilha(tipo_pilha pl)
{
  int i;
  printf("[");

  for (i = 0; i < pl.contador; i++)
  {
    printf("%d ", pl.pilha[i]);
  }
  printf("] <- TOPO\nContador=%d\n", pl.contador);
}