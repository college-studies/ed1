#ifndef ORDENACAO_C
#define ORDENACAO_C

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

// Prototipacao
void bubbleSort(tipo_lista *lst);
void shellSort(tipo_lista *lst);

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

void shellSort(tipo_lista *lst)
{
  int flag_troca, aux, idx, k;

  k = lst->contador / 2;
  flag_troca = 1;

  while (k > 1)
  {
    idx = 0;
    while (idx + k < lst->contador)
    {
      if (lst->lista[idx] > lst->lista[idx + k])
      {
        aux = lst->lista[idx];
        lst->lista[idx] = lst->lista[idx + k];
        lst->lista[idx + k] = aux;
      }
      idx++;
    }
    k--;
  }
  while (flag_troca)
  {
    flag_troca = 0;
    idx = 0;
    while (idx < lst->contador - 1)
    {
      if (lst->lista[idx] > lst->lista[idx + 1])
      {
        aux = lst->lista[idx];
        lst->lista[idx] = lst->lista[idx + 1];
        lst->lista[idx + 1] = aux;
        flag_troca = 1;
      }
      idx++;
    }
  }
}

#endif