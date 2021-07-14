#include <stdio.h>
#include <stdlib.h>

struct estru_no
{
  int valor;
  struct estru_no *prox;
};
typedef struct estru_no tipo_no;

int main()
{
  // declara e inicializa ponteiro como null
  tipo_no *fila;
  fila = NULL;

  tipo_no *novo_no;
  novo_no = (tipo_no *)malloc(sizeof(tipo_no)); //aloca memoria
  novo_no->valor = 10;                          //inicializa valor
  novo_no->prox = NULL;                         //pointeiro proximo aponta pra nulo

  fila = novo_no; // ponteiro fila aponta para o proximo no

  //inserir novo elemento
  novo_no = (tipo_no *)malloc(sizeof(tipo_no));
  novo_no->valor = 3;
  novo_no->prox = NULL;

  fila->prox = novo_no;

  printf("Valor = %d\n", fila->valor);
  printf("Valor = %d\n", fila->prox->valor);

  return 1;
}