// exemplo usando heap maximo

#ifndef HEAP_C
#define HEAP_C

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

#define N_H 20

struct heap_est
{
  int heap[N_H];
  int cont;
};
typedef struct heap_est tipo_heap;

int posPai(int);
int posFEsq(int);
int posFDir(int);
void inicializaHeap(tipo_heap *hp);
void insereHeap(tipo_heap *hp, int valor);
void sobeValor(tipo_heap *hp, int pos);
int removeHeap(tipo_heap *hp);
void desceValor(tipo_heap *hp, int pos);
void imprimeHeap(tipo_heap hp);
// ---------------------------------------------------------------- //
tipo_heap cria_heap();
int valor_maximo(tipo_heap heap);
int qtd_valores_heap(tipo_heap heap);
int valor_existe_no_heap(tipo_heap heap, int valor);
tipo_heap unifica(tipo_heap heap_a, tipo_heap heap_b);
// ---------------------------------------------------------------- //

void heap_sort(tipo_lista *lst);

void inicializaHeap(tipo_heap *hp)
{
  hp->cont = 0;
}

int posPai(int i)
{
  return (int)((i - 1) / 2);
}

int posFEsq(int i)
{
  return 2 * i + 1;
}

int posFDir(int i)
{
  return 2 * i + 2;
}

void insereHeap(tipo_heap *hp, int valor)
{
  hp->heap[hp->cont++] = valor;
  sobeValor(hp, hp->cont - 1);
}

void sobeValor(tipo_heap *hp, int pos)
{
  int aux;
  if (hp->heap[pos] > hp->heap[posPai(pos)])
  {
    aux = hp->heap[pos];
    hp->heap[pos] = hp->heap[posPai(pos)];
    hp->heap[posPai(pos)] = aux;
    if (posPai(pos) > 0)
    {
      sobeValor(hp, posPai(pos));
    }
  }
}

int removeHeap(tipo_heap *hp)
{
  int valor;
  if (hp->cont > 0)
  {
    valor = hp->heap[0];
    hp->heap[0] = hp->heap[hp->cont - 1];
    hp->cont--;
    desceValor(hp, 0);
    return valor;
  }
  else
  {
    return -1;
  }
}

void desceValor(tipo_heap *hp, int pos)
{
  int novaPos, aux;
  novaPos = -1;

  if (posFEsq(pos) < hp->cont)
  {
    if (posFDir(pos) < hp->cont)
    {
      if (hp->heap[posFEsq(pos)] > hp->heap[posFDir(pos)])
      {
        if (hp->heap[pos] < hp->heap[posFEsq(pos)])
        {
          novaPos = posFEsq(pos);
        }
      }
      else
      {
        if (hp->heap[pos] < hp->heap[posFDir(pos)])
        {
          novaPos = posFDir(pos);
        }
      }
    }
    else
    {
      if (hp->heap[pos] < hp->heap[posFEsq(pos)])
      {
        novaPos = posFEsq(pos);
      }
    }

    if (novaPos > -1)
    {
      aux = hp->heap[pos];
      hp->heap[pos] = hp->heap[novaPos];
      hp->heap[novaPos] = aux;
      desceValor(hp, novaPos);
    }
  }
}

void imprimeHeap(tipo_heap hp)
{
  int i;
  printf(" [ ");
  for (i = 0; i < hp.cont; i++)
  {
    printf("%d ", hp.heap[i]);
  }
  printf("]\n");
}

tipo_heap cria_heap()
{
  tipo_heap heap;
  inicializaHeap(&heap);
  return heap;
}

int valor_maximo(tipo_heap heap)
{
  return heap.heap[0];
}

int qtd_valores_heap(tipo_heap heap)
{
  return heap.cont;
}

int valor_existe_no_heap(tipo_heap heap, int valor)
{
  int flag = 0;

  for (int i = 0; i < heap.cont; i++)
  {
    if (heap.heap[i] == valor)
      flag = 1;
  }

  return flag;
}

tipo_heap unifica(tipo_heap heap_a, tipo_heap heap_b)
{
  tipo_heap resultado;
  resultado = cria_heap();

  for (int i = 0; i < heap_a.cont; i++)
  {
    insereHeap(&resultado, heap_a.heap[i]);
  }

  for (int i = 0; i < heap_a.cont; i++)
  {
    insereHeap(&resultado, heap_b.heap[i]);
  }

  return resultado;
}

void heap_sort(tipo_lista *lst)
{
  tipo_heap heap;

  inicializaHeap(&heap);

  for (int i = 0; i < lst->contador; i++)
  {
    insereHeap(&heap, lst->lista[i]);
  }

  for (int i = (lst->contador - 1); i >= 0; i--)
    lst->lista[i] = removeHeap(&heap);
}

#endif