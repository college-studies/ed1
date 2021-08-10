#include <stdio.h>
#include <stdlib.h>

#include "lista.c"
#include "metodos.c"

int main()
{
  tipo_lista lista;
  inicializaLista(&lista);

  insereFim(&lista, 7);
  insereFim(&lista, 3);
  insereFim(&lista, 8);
  insereFim(&lista, 4);
  insereFim(&lista, 1);
  insereFim(&lista, 9);
  insereFim(&lista, 5);
  insereFim(&lista, 2);
  insereFim(&lista, 6);

  imprimeLista(lista);

  // bubbleSort(&lista);
  // shellSort(&lista);
  // lista = insertSort(lista);
  // mergeSort(&lista);
  quickSort(&lista);

  imprimeLista(lista);

  return 1;
}