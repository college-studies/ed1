#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void bubbleSort(tipo_lista *lst);

void bubbleSort(tipo_lista *lst)
{
  int flag_troca, aux, idx;

  flag_troca = 1;

  while (flag_troca)
  {
    flag_troca = 0;
    for (idx = 0; idx < lst->contador - 1; idx++)
    {
      if (lst->lista[idx] > lst->lista[idx + 1])
      {
        aux = lst->lista[idx];
        lst->lista[idx] = lst->lista[idx + 1];
        lst->lista[idx + 1] = aux;
        flag_troca = 1;
      }
    }
  }
}

#endif
