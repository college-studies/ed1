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
void sobeValor(tipo_heap *hp, int pos);
void imprimeHeap(tipo_heap hp);

void inicializaHeap(tipo_heap *hp) {
  hp->cont = 0;
}

int posPai(int i) {
  return (int) ((i-1)/2);
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

void imprimeHeap(tipo_heap hp) {
  int i;
  printf(" [ ");
  for (i =0; i < hp.cont; i++) {
    printf("%d ", hp.heap[i]);
  }
  printf("]\n");
}


#endif