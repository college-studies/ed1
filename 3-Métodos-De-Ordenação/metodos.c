#ifndef ORDENACAO_C
#define ORDENACAO_C

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

// Prototipacao
void bubbleSort(tipo_lista *lst);
void shellSort(tipo_lista *lst);
tipo_lista insertSort(tipo_lista lst);
void mergeSort(tipo_lista *lst);
void mergeSort_div(int vet[], int tam);
void merge(int vet[], int tam);

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