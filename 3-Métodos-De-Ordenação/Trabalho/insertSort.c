#ifndef INSERT_SORT
#define INSERT_SORT

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

tipo_lista insertSort(tipo_lista lst);

tipo_lista insertSort(tipo_lista lst)
{
  int idx_lst, idx;
  tipo_lista lst_ordenada;
  inicializaLista(&lst_ordenada);
  for (idx_lst = 0; idx_lst < lst.contador; idx_lst++)
  {
    if (lst_ordenada.contador == 0)
    {
      insereFim(&lst_ordenada, lst.lista[idx_lst]);
    }
    else
    {
      idx = lst_ordenada.contador - 1;
      while ((idx >= 0) && (lst.lista[idx_lst] < lst_ordenada.lista[idx]))
      {
        idx--;
      }
      inserePosicao(&lst_ordenada, lst.lista[idx_lst], idx + 1);
    }
  }
  return lst_ordenada;
}

#endif
