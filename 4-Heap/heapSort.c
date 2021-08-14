#ifndef HEAP_SORT
#define HEAP_SORT

#include <stdio.h>
#include <stdlib.h>
#include "heap.c"
#include "lista.c"


void heapSort(tipo_lista *lst);

void heapSort(tipo_lista *lst) {
  tipo_heap heap;
  int i;
  inicializaHeap(&heap);

  //carega todos os elementos da lista no heap
  for (i = 0; i < lst->contador; i++)
    insereHeap(&heap, lst->lista[i]);

  //remove elemento a elemento do heap e atualiza a lista
  for (i = (lst->contador -1); i >= 0; i--) {
    lst->lista[i] = removeHeap(&heap);
  }
}

#endif