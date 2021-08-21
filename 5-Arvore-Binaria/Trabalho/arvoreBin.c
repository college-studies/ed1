#include <stdio.h>
#include <stdlib.h>

struct str_arvoreBin
{
  int valor;
  struct str_arvoreBin *esq;
  struct str_arvoreBin *dir;
};
typedef struct str_arvoreBin tipo_arvore_binaria;

tipo_arvore_binaria *alocaNovoNoArvoreBin(int valor);
tipo_arvore_binaria *criarArvoreBin();
void insereArvoreBin(tipo_arvore_binaria **arv, int vl);
void imprimePreOrdem(tipo_arvore_binaria *arv);
void imprimeOrdem(tipo_arvore_binaria *arv);
void imprimePosOrdem(tipo_arvore_binaria *arv);
void imprimeNivel(tipo_arvore_binaria *arv, int nivel);
void ImprimeNivelRec(tipo_arvore_binaria *arv, int nivel, int nivelPassagem);
int alturaArvoreBin(tipo_arvore_binaria *arv);
void imprimeNosFolhaArvoreBin(tipo_arvore_binaria *arv);
int contagemNosArvoreBin(tipo_arvore_binaria *arv);
// TODO
void removeValorArvoreBin(tipo_arvore_binaria **arv, int valor);
int buscaArvoreBin(tipo_arvore_binaria *arv, int vl);

tipo_arvore_binaria *alocaNovoNoArvoreBin(int valor) {
  tipo_arvore_binaria *novo_no;
  novo_no = (tipo_arvore_binaria *) malloc(sizeof(tipo_arvore_binaria));
  novo_no->valor = valor;
  novo_no->esq = NULL;
  novo_no->dir = NULL;
  return novo_no;
}

tipo_arvore_binaria *criarArvoreBin() {
  tipo_arvore_binaria *aux = NULL;
  return aux;
}

void insereArvoreBin(tipo_arvore_binaria **arv, int vl) {
  if ((*arv) == NULL) {
    (*arv) = alocaNovoNoArvoreBin(vl);
  } else {
    if (vl > (*arv)->valor) {
      insereArvoreBin( &(*arv)->dir, vl);
    } else {
      insereArvoreBin( &(*arv)->esq, vl);
    }
  }
}

void imprimePreOrdem(tipo_arvore_binaria *arv) {
  if (arv != NULL) {
    printf("%d ", arv->valor);
    imprimePreOrdem(arv->esq);
    imprimePreOrdem(arv->dir);
  }
}

void imprimeOrdem(tipo_arvore_binaria *arv) {
  if (arv != NULL) {
    imprimeOrdem(arv->esq);
    printf("%d ", arv->valor);
    imprimeOrdem(arv->dir);
  }
}

void imprimePosOrdem(tipo_arvore_binaria *arv) {
  if (arv != NULL) {
    imprimePosOrdem(arv->esq);
    imprimePosOrdem(arv->dir);
    printf("%d ", arv->valor);
  }
}

void imprimeNivel(tipo_arvore_binaria *arv, int nivel) {
  printf("[ ");
  ImprimeNivelRec(arv, nivel, 0);
  printf("]\n");
}

void ImprimeNivelRec(tipo_arvore_binaria *raiz, int nivel, int nivelPassagem) {
  tipo_arvore_binaria *aux;
  aux = raiz;
  if(raiz != NULL){
    ImprimeNivelRec(aux->esq, nivel, nivelPassagem+1);
    ImprimeNivelRec(aux->dir, nivel, nivelPassagem+1);
    if(nivel == nivelPassagem){
      printf("%d ",aux->valor);
    }
  }
}

int alturaArvoreBin(tipo_arvore_binaria *arv) {
  int resultado = -1;
  if( arv != NULL) {
    int esq = 0, dir = 0;
    esq = alturaArvoreBin(arv->esq);
    dir = alturaArvoreBin(arv->dir);
    if(esq > dir) {
      resultado = ++esq;
    } else {
      resultado = ++dir;
    }
  }
  return resultado;
}

void imprimeNosFolhaArvoreBin(tipo_arvore_binaria *arv) {
  imprimeNivel(arv, alturaArvoreBin(arv));
}

int contagemNosArvoreBin(tipo_arvore_binaria *arv) {
  if( arv != NULL) {
    int totalEsq = contagemNosArvoreBin(arv->esq);
    int totalDir = contagemNosArvoreBin(arv->dir);
    return 1 + totalEsq + totalDir;
  }
}

int buscaArvoreBin(tipo_arvore_binaria *raiz, int vl) {
  // TODO buscar valor na arvore binária
}

void removeValorArvoreBin(tipo_arvore_binaria **arv, int valor) {
  // TODO remocao do valor da arvore binária
}
