#ifndef ORDENACAO_C
#define ORDENACAO_C

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

// Prototipacao
void newQuickSort(tipo_lista *lst, int inicio, int fim);
int quickSort_interno_inverso(int vet[], int inicio, int fim);

void newQuickSort(tipo_lista *lst, int inicio, int fim)
{
  if (inicio < fim)
  {
    int i = quickSort_interno_inverso(lst->lista, 0, lst->contador - 1);
    newQuickSort(lst, inicio, i - 1);
    newQuickSort(lst, i + 1, fim);
  }
}

int quickSort_interno_inverso(int vet[], int inicio, int fim)
{
  int pivot = inicio + rand() % (fim - inicio);

  // troca vet[fim] com o pivo
  int temp = vet[fim];
  vet[fim] = vet[pivot];
  vet[pivot] = temp;

  int i = inicio;
  for (int j = inicio; j < fim; j++)
  {
    if (vet[j] > vet[fim])
    {
      int temp1 = vet[j];
      vet[j] = vet[i];
      vet[i] = temp1;
      i++;
    }
  }

  // troca pivo com a posicao correta
  long temp2 = vet[fim];
  vet[fim] = vet[i];
  vet[i] = temp2;

  return i;
}

#endif