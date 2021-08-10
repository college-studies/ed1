#ifndef MERGE_SORT
#define MERGE_SORT

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void mergeSort(tipo_lista *lst);
void mergeSort_div(int vet[], int tam);
void merge(int vet[], int tam);

void mergeSort(tipo_lista *lst)
{
  mergeSort_div(lst->lista, lst->contador);
}

// Função de Divisão do mergeSort por Recursão
void mergeSort_div(int vet[], int tam)
{
  int meio;
  if (tam > 1)
  {
    meio = tam / 2;
    mergeSort_div(vet, meio);
    mergeSort_div(&(vet[meio]), tam - meio);
    merge(vet, tam);
  }
}

//Funcao de Junção/merge do merge sort
void merge(int vet[], int tam)
{
  int *vet_aux;
  int i, j, meio, idx_aux;

  vet_aux = (int *)malloc(sizeof(int) * tam);

  meio = tam / 2;
  i = 0;
  j = meio;
  idx_aux = 0;

  while ((i < meio) && (j < tam))
  {
    if (vet[i] < vet[j])
    {
      vet_aux[idx_aux++] = vet[i++];
    }
    else
    {
      vet_aux[idx_aux++] = vet[j++];
    }
  }

  while (i < meio)
  {
    vet_aux[idx_aux++] = vet[i++];
  }

  while (j < tam)
  {
    vet_aux[idx_aux++] = vet[j++];
  }

  for (i = 0; i < tam; i++)
  {
    vet[i] = vet_aux[i];
  }
  free(vet_aux);
}

#endif
