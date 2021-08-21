#include <stdio.h>
#include <stdlib.h>

#include "heap.c"
#include "lista.c"
#include "heapSort.c"

int main()
{
  // tipo_heap heap;
  // inicializaHeap(&heap);

  // insereHeap(&heap, 10);
  // insereHeap(&heap, 5);
  // insereHeap(&heap, 15);
  // insereHeap(&heap, 20);
  // insereHeap(&heap, 17);
  // insereHeap(&heap, 8);
  // insereHeap(&heap, 25);

  // imprimeHeap(heap);

  // printf("Removido: %d\n", removeHeap(&heap));
  // imprimeHeap(heap);

  tipo_lista lista;
  inicializaLista(&lista);
  insereFim(&lista, 10);
  insereFim(&lista, 1);
  insereFim(&lista, 7);
  insereFim(&lista, 8);
  insereFim(&lista, 3);
  insereFim(&lista, 6);

  imprimeLista(lista);

  heapSort(&lista);

  imprimeLista(lista);

  return 1;
}