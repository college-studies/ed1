#include <stdio.h>
#include <stdlib.h>

struct estruturaNo
{
  int valor;
  struct estruturaNo *prox;
};
typedef struct estruturaNo tipoNo;

void insereInicio(tipoNo **lista, int vl);
void inserePosicao(tipoNo **lista, int vl, int pos);
void insereFinal(tipoNo **lista, int vl);
int removeInicio(tipoNo **lista);
int removePosicao(tipoNo **lista, int pos);
int removeFinal(tipoNo **lista);
void imprimeLista(tipoNo *lista);
tipoNo *alocaNo(int vl);

int main()
{
  tipoNo *lista;
  lista = NULL;

  insereInicio(&lista, 4);
  insereInicio(&lista, 3);
  insereInicio(&lista, 2);
  insereInicio(&lista, 1);

  insereFinal(&lista, 7);
  insereFinal(&lista, 8);

  inserePosicao(&lista, 5, 4);
  inserePosicao(&lista, 6, 5);

  imprimeLista(lista);

  printf("Valor removido: %d\n", removeInicio(&lista));
  printf("Valor removido: %d\n", removeFinal(&lista));
  printf("Valor removido: %d\n", removePosicao(&lista, 6));

  imprimeLista(lista);

  return 1;
}

void insereInicio(tipoNo **lista, int vl)
{
  tipoNo *novo, *aux;
  novo = alocaNo(vl);
  aux = (*lista);

  if ((*lista) == NULL)
  {
    novo->prox = novo;
    (*lista) = novo;
  }
  else
  {
    novo->prox = (*lista);
    while (aux->prox != (*lista))
    {
      aux = aux->prox;
    }
    aux->prox = novo;
    (*lista) = novo;
  }
}

void inserePosicao(tipoNo **lista, int vl, int pos) 
{
  tipoNo *novo, *aux, *aux2;
  int cont = 0;
  novo = alocaNo(vl);
  if (pos == 0) insereInicio(lista, vl);
  else {
    aux = (*lista);
    while (aux->prox != (*lista) && cont < pos) {
      aux2 = aux;
      aux = aux->prox;
      cont++;
    }
    if (aux->prox != (*lista) && cont == pos) {
      novo = alocaNo(vl);
      novo->prox = aux;
      aux2->prox = novo;
    } else if (aux->prox == *lista && cont + 1 == pos) {
      insereFinal(lista, vl);
    } else {
      printf("[ERRO]: Posicao invalida\n");
    }
  } 
}

void insereFinal(tipoNo **lista, int vl) 
{
  tipoNo *novo, *aux;
  novo = alocaNo(vl);
  aux = (*lista);

  if ((*lista) == NULL)
  {
    novo->prox = novo;
    (*lista) = novo;
  }
  else
  {
    novo->prox = (*lista);
    while (aux->prox != (*lista))
    {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

int removeInicio(tipoNo **lista) {
  if (*lista != NULL) {
    tipoNo *aux = *lista, *aux2;
    int valor = (*lista)->valor;
    while (aux->prox != (*lista)) {
      aux = aux->prox;
    }
    aux2 = *lista;
    (*lista) = (*lista)->prox;
    aux->prox = (*lista);
    free(aux2);
    return valor;
  }else {
    printf("[ERRO]: Nao ha itens para remocao. Lista vazia!\n");
    return -1;
  }
}

int removePosicao(tipoNo **lista, int pos) {
  if (*lista != NULL) {
    tipoNo *aux = (*lista), *aux2;
    int valor, cont = 0;
    if (pos == 0) return removeInicio(lista);
    else {
      while (aux->prox != (*lista) && cont < pos) {
        aux2 = aux;
        aux = aux->prox;
        cont++;
      }
      if (aux != (*lista) && cont == pos) {
        valor = aux->valor;
        aux2->prox = aux->prox;
        free(aux);
        return valor;
      } else if (aux == *lista && cont == pos) {
        return removeInicio(lista);
      } else {
        printf("[ERRO]: Posicao invalida\n");
        return -1;
      }
    }
  }else {
    printf("[ERRO]: Nao ha itens para remocao. Lista vazia!\n");
    return -1;
  }
}

int removeFinal(tipoNo **lista) {
  if (*lista != NULL) {
    tipoNo *aux = *lista, *aux2;
    int valor;
    while (aux->prox != (*lista)) {
      aux2 = aux;
      aux = aux->prox;
    }
    valor = aux->valor;
    aux2->prox = *lista;
    free(aux);
    return valor;
  }else {
    printf("[ERRO]: Nao ha itens para remocao. Lista vazia!\n");
    return -1;
  }
}

tipoNo *alocaNo(int vl) {
  tipoNo *novoNo;
  novoNo = (tipoNo*) malloc(sizeof(tipoNo));
  novoNo->valor = vl;
  novoNo->prox = NULL;
  return novoNo;
}

void imprimeLista(tipoNo *lista)
{
  int i;
  tipoNo *aux;
  if (lista == NULL)
  {
    printf("ERRO - LISTA VAZIA\n");
  }
  else
  {
    aux = lista;
    printf("Lista Circular: [ ");
    while (aux->prox != lista)
    {
      printf("%d ", aux->valor);
      i++;
      aux = aux->prox;
    }
    printf("%d ]\n", aux->valor);
  }
}