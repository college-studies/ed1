#include <stdio.h>
#include <stdlib.h>

struct estruturaNoDuplo
{
  int valor;
  struct estruturaNoDuplo *ant;
  struct estruturaNoDuplo *prox;
};
typedef struct estruturaNoDuplo tipoNoDuplo;

void insereInicio(tipoNoDuplo **lista, int vl);
void inserePosicao(tipoNoDuplo **lista, int vl, int pos);
void insereFinal(tipoNoDuplo **lista, int vl);
int removeInicio(tipoNoDuplo **lista);
int removePosicao(tipoNoDuplo **lista, int pos);
int removeFinal(tipoNoDuplo **lista);
void imprimeLista(tipoNoDuplo *lista);
tipoNoDuplo *alocaNoDuplo(int vl);

int main() {
  tipoNoDuplo *lista;
  lista = NULL;

  insereInicio(&lista, 3);
  insereInicio(&lista, 2);
  insereInicio(&lista, 1);

  insereFinal(&lista, 7);
  insereFinal(&lista, 8);
  insereFinal(&lista, 9);

  inserePosicao(&lista, 4 , 3);
  inserePosicao(&lista, 5, 4);
  inserePosicao(&lista, 6, 5);

  imprimeLista(lista);

  printf("Valor removido: %d\n", removeInicio(&lista));
  printf("Valor removido: %d\n", removeFinal(&lista));

  imprimeLista(lista);

  printf("Valor removido: %d\n", removePosicao(&lista, 3));

  imprimeLista(lista);

  return 1;
}

void insereInicio(tipoNoDuplo **lista, int vl) {
  tipoNoDuplo *novo, *aux;
  novo = alocaNoDuplo(vl);
  if ((*lista) == NULL) {
    novo->prox = novo;
    novo->ant = novo;
    (*lista) = novo;
  } else {
    novo->prox = (*lista);
    novo->ant = (*lista)->ant;
    novo->ant->prox = novo;
    (*lista) = novo;
  }
}

void inserePosicao(tipoNoDuplo **lista, int vl, int pos) {
  tipoNoDuplo *novo, *aux;
  int cont = 1;
  novo = alocaNoDuplo(vl);
  if (pos == 0) insereInicio(lista, vl);
  else {
    aux = (*lista);
    while (aux->prox != (*lista) && cont < pos) {
      aux = aux->prox;
      cont++;
    }
    if (aux->prox != (*lista) && cont == pos) {
      novo->prox = aux->prox;
      novo->ant = aux;
      aux->prox = novo;
      novo->prox->ant = novo;
    } else if (aux->prox == *lista && cont == pos) {
      insereFinal(lista, vl);
    } else {
      printf("[ERRO]: Posicao invalida\n");
    }
  } 
}

void insereFinal(tipoNoDuplo **lista, int vl) {
  tipoNoDuplo *novo, *aux;
  novo = alocaNoDuplo(vl);
  aux = (*lista);
  if ((*lista) == NULL) {
    novo->prox = novo;
    novo->ant = novo;
    (*lista) = novo;
  } else {
    novo->prox = (*lista);
    novo->ant = (*lista)->ant;
    novo->ant->prox = novo;
    (*lista)->ant = novo;
  }
}

int removeInicio(tipoNoDuplo **lista) {
  if (*lista != NULL) {
    tipoNoDuplo *aux = *lista;
    int valor = (*lista)->valor;
    (*lista) = (*lista)->prox;
    (*lista)->ant = aux->ant;
    (*lista)->ant->prox = (*lista);
    free(aux);
    return valor;
  }else {
    printf("[ERRO]: Nao ha itens para remocao. Lista vazia!\n");
    return -1;
  }
}

int removePosicao(tipoNoDuplo **lista, int pos) {
  if (*lista != NULL) {
    tipoNoDuplo *aux = (*lista);
    int valor, cont = 0;
    if (pos == 0) return removeInicio(lista);
    else {
      while (aux->prox != (*lista) && cont < pos) {
        aux = aux->prox;
        cont++;
      }
      if (aux->prox != (*lista) && cont == pos) {
        valor = aux->valor;
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
        return valor;
      } else if (aux->prox == *lista && cont == pos) {
        return removeFinal(lista);
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

int removeFinal(tipoNoDuplo **lista) {
  if (*lista != NULL) {
    tipoNoDuplo *aux = (*lista)->ant;
    int valor;
    valor = aux->valor;
    aux->ant->prox = *lista;
    (*lista)->ant = aux->ant;
    free(aux);
    return valor;
  }else {
    printf("[ERRO]: Nao ha itens para remocao. Lista vazia!\n");
    return -1;
  }
}

tipoNoDuplo *alocaNoDuplo(int vl) {
  tipoNoDuplo *novoNo;
  novoNo = (tipoNoDuplo*) malloc(sizeof(tipoNoDuplo));
  novoNo->valor = vl;
  novoNo->prox = NULL;
  novoNo->ant = NULL;
  return novoNo;
}

void imprimeLista(tipoNoDuplo *lista)
{
  int i;
  tipoNoDuplo *aux;
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