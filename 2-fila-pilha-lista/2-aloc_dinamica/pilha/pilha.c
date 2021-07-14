#include <stdio.h>
#include <stdlib.h>

struct estru_no
{
  int valor;
  struct estru_no *prox;
};
typedef struct estru_no tipo_no;

struct estru_resultado
{
  int valor;
  tipo_no *no;
};
typedef struct estru_resultado tipo_resultado;

// Prototipos
tipo_no *alocaNovoNo(int vl);
tipo_no *empilha(tipo_no *pl, int vl);
tipo_resultado desempilha(tipo_no *pl);
void imprimePilha(tipo_no *pl);

int main()
{
  tipo_resultado result;
  tipo_no *pilha;
  pilha = NULL;

  pilha = empilha(pilha, 7);
  pilha = empilha(pilha, 2);
  pilha = empilha(pilha, 9);

  imprimePilha(pilha);

  result = desempilha(pilha);

  printf("O valor %d foi removido da pilha\n", result.valor);
  pilha = result.no;

  imprimePilha(pilha);

  return 1;
}

void imprimePilha(tipo_no *pl)
{
  if (pl == NULL)
  {
    printf("[ERRO] Pilha esta vazia\n");
  }
  else
  {
    printf("TOPO -> [ ");
    while (pl != NULL)
    {
      printf("[%d] ", pl->valor);
      pl = pl->prox;
    }
    printf("]\n");
  }
}

tipo_no *alocaNovoNo(int vl)
{
  tipo_no *novo_no;
  novo_no = (tipo_no *)malloc(sizeof(tipo_no));
  novo_no->valor = vl;
  novo_no->prox = NULL;
  return novo_no;
}

// Funcao que aloca um novo nó e empilha
tipo_no *empilha(tipo_no *pl, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  novo_no->prox = pl;

  return novo_no;
}

// Funcao que desempilha um no
tipo_resultado desempilha(tipo_no *pl)
{
  tipo_no *topo;
  tipo_resultado result;

  result.valor = pl->valor; // guarda o valor a ser retornado
  result.no = pl->prox;     // guarda o endereco do novo nó q sera topo
  topo = pl;
  free(topo);

  return result;
}