#ifndef QUICK_SORT
#define QUICK_SORT

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void quickSort(tipo_lista *lst);
void quickSort_interno(int vet[], int inicio, int fim);

// Funcao que implementa o metodo quicksort;
void quickSort(tipo_lista *lst)
{
  quickSort_interno(lst->lista, 0, lst->contador - 1);
}

//Funcao interna do quicksort
void quickSort_interno(int vet[], int inicio, int fim)
{
  int pivot, i, j, aux;

  if (inicio < fim)
  {
    pivot = inicio;
    i = inicio;
    j = fim;
    while (i < j)
    {

      while (vet[i] <= vet[pivot] && i <= fim)
        i++;

      while (vet[j] > vet[pivot] && j >= inicio)
        j--;

      if (i < j)
      {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
    }

    aux = vet[j];
    vet[j] = vet[pivot];
    vet[pivot] = aux;

    quickSort_interno(vet, inicio, j - 1);
    quickSort_interno(vet, j + 1, fim);
  }
}

#endif
