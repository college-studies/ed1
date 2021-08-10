#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.c"

#include "bubbleSort.c"
#include "insertSort.c"
#include "mergeSort.c"
#include "quickSort.c"
#include "shellSort.c"

// Para alterar o valor de Números gerados, basta alterar a constante N em "lista.c"

void insereValoresAleatorios(tipo_lista *lst);

int main()
{
  clock_t inicio, fim;
  double tempoCPU;

  tipo_lista lista;
  inicializaLista(&lista);

  insereValoresAleatorios(&lista);

  printf("Lista Desordenada: \n");
  imprimeLista(lista);

  inicio = clock();
  // Basta Descomentar o método que quiser testar;
  // bubbleSort(&lista);
  // shellSort(&lista);
  // lista = insertSort(lista);
  // mergeSort(&lista);
  quickSort(&lista);
  fim = clock();
  tempoCPU = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  printf("\nLista Ordenada: \n");
  imprimeLista(lista);
  printf("\nO método levou %fs para ordenar \n", tempoCPU);

  return 1;
}

void insereValoresAleatorios(tipo_lista *lst)
{
  while (lst->contador != N)
  {
    insereFim(lst, rand() % 10000);
  }
}