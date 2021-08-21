#include <stdio.h>
#include <stdlib.h>

#include "heap.c"
#include "lista.c"

int main()
{
  tipo_heap heap_a = cria_heap();
  tipo_heap heap_b = cria_heap();

  insereHeap(&heap_a, 4);
  insereHeap(&heap_a, 6);
  insereHeap(&heap_a, 2);
  insereHeap(&heap_a, 1);
  insereHeap(&heap_a, 3);
  insereHeap(&heap_a, 5);

  insereHeap(&heap_b, 10);
  insereHeap(&heap_b, 7);
  insereHeap(&heap_b, 13);
  insereHeap(&heap_b, 11);
  insereHeap(&heap_b, 8);
  insereHeap(&heap_b, 12);

  imprimeHeap(heap_a);
  imprimeHeap(heap_b);

  printf("\nMaior valor do Heap_a : %d\n", valor_maximo(heap_a));
  printf("Maior valor do Heap_b : %d\n", valor_maximo(heap_b));

  printf("\nRemove valor %d do heap_a\n", removeHeap(&heap_a));
  printf("Remove valor %d do heap_b\n\n", removeHeap(&heap_b));

  imprimeHeap(heap_a);
  imprimeHeap(heap_b);

  printf("\nTamanho do heap_a: %d\n", qtd_valores_heap(heap_a));
  printf("Tamanho do heap_b: %d\n\n", qtd_valores_heap(heap_b));

  if (valor_existe_no_heap(heap_a, 1))
    printf("Valor presente no heap\n\n");
  else
    printf("Valor não existe no heap\n\n");

  tipo_heap unificaHeaps = unifica(heap_a, heap_b);
  printf("Heap_a + Heap_b = ");
  imprimeHeap(unificaHeaps);

  tipo_lista lista;
  inicializaLista(&lista);
  insereFim(&lista, 4);
  insereFim(&lista, 6);
  insereFim(&lista, 2);
  insereFim(&lista, 1);
  insereFim(&lista, 3);
  insereFim(&lista, 5);

  printf("\nLista Desordenada: ");
  imprimeLista(lista);

  printf("Lista Ordenada: ");
  heap_sort(&lista);
  imprimeLista(lista);
}