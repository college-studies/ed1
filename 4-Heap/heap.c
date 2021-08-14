// exemplo usando heap maximo

#ifndef HEAP_C
#define HEAP_C

#include <stdio.h>
#include <stdlib.h>

#define N 20

struct heap_est {
  int heap[N];
  int cont;
};
typedef struct heap_est tipo_heap;

int posPai(int);
int posFEsq(int);
int posFDir(int);
void inicializaHeap(tipo_heap *hp);
void insereHeap(tipo_heap *hp, int valor);
int removeHeap(tipo_heap *hp);
void desceValor(tipo_heap *hp, int pos);
void sobeValor(tipo_heap *hp, int pos);
void imprimeHeap(tipo_heap hp);

void inicializaHeap(tipo_heap *hp) {
  hp->cont = 0;
}

int posPai(int i) {
  return (int)((i-1)/2);
}

int posFEsq(int i){
  return 2*i*1;
}

int posFDir(int i) {
  return 2*i+2;
}

void insereHeap(tipo_heap *hp, int valor) {
  hp->heap[hp->cont++] = valor;
  sobeValor(hp, hp->cont-1);
}

void sobeValor(tipo_heap *hp, int pos) {
  int aux;
  if (hp->heap[pos] > hp->heap[posPai(pos)]) {
    aux = hp->heap[pos];
    hp->heap[pos] = hp->heap[posPai(pos)];
    hp->heap[posPai(pos)] = aux;
    if (posPai(pos) > 0) {
      sobeValor(hp, posPai(pos));
    }
  }
}


int removeHeap(tipo_heap *hp) {
  int valor;
  if (hp->cont > 0) {
    valor = hp->heap[0];
    hp->heap[0] = hp->heap[hp->cont-1];
    hp->cont--;
    desceValor(hp,0);
    return valor;
  } else {
    return -1;
  }
}

void desceValor(tipo_heap *hp, int pos)
{
  int novaPos, aux;
  novaPos = -1;

  if (posFEsq(pos) < hp->cont) {
    if (posFDir(pos) < hp->cont) {
      if (hp->heap[posFEsq(pos)] > hp->heap[posFDir(pos)]){
        if (hp->heap[pos] < hp->heap[posFEsq(pos)]){
          novaPos = posFEsq(pos);
        }
      }else {
        if (hp->heap[pos] < hp->heap[posFDir(pos)]){
          novaPos = posFDir(pos);
        }
      } 
    } else {
      if (hp->heap[pos] < hp->heap[posFEsq(pos)]){
        novaPos = posFEsq(pos);
      }
    }

    if (novaPos > -1) {
      aux = hp->heap[pos];
      hp->heap[pos] = hp->heap[novaPos];
      hp->heap[novaPos] = aux;
      desceValor(hp, novaPos);
    }
  }
}


void imprimeHeap(tipo_heap hp) {
  int i;
  printf(" [ ");
  for (i = 0; i < hp.cont; i++) {
    printf("%d ", hp.heap[i]);
  }
  printf("]\n");
}

#endif