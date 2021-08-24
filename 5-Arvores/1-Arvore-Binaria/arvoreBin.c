#ifndef ARVBIN_C
#define ARVBIN_C

struct str_arvoreBin
{
  int valor;
  struct str_arvoreBin *esq;
  struct str_arvoreBin *dir;
};
typedef struct str_arvoreBin tipo_arvore_binaria;

tipo_arvore_binaria *alocaNovoNoArvoreBin(int valor);
void insereArvoreBin(tipo_arvore_binaria **arv, int vl);
void imprimePreOrdem(tipo_arvore_binaria *arv);
void imprimeOrdem(tipo_arvore_binaria *arv);
void imprimePosOrdem(tipo_arvore_binaria *arv);

tipo_arvore_binaria *alocaNovoNoArvoreBin(int valor)
{
  tipo_arvore_binaria *novo_no;
  novo_no = (tipo_arvore_binaria *)malloc(sizeof(tipo_arvore_binaria));
  novo_no->valor = valor;
  novo_no->esq = NULL;
  novo_no->dir = NULL;
  return novo_no;
}

void insereArvoreBin(tipo_arvore_binaria **arv, int vl)
{
  if ((*arv) == NULL)
  {
    (*arv) = alocaNovoNoArvoreBin(vl);
  }
  else
  {
    if (vl > (*arv)->valor)
    {
      insereArvoreBin(&(*arv)->dir, vl);
    }
    else
    {
      insereArvoreBin(&(*arv)->esq, vl);
    }
  }
}

void imprimePreOrdem(tipo_arvore_binaria *arv)
{
  if (arv != NULL)
  {
    printf("%d ", arv->valor);
    imprimePreOrdem(arv->esq);
    imprimePreOrdem(arv->dir);
  }
}

void imprimeOrdem(tipo_arvore_binaria *arv)
{
  if (arv != NULL)
  {
    imprimeOrdem(arv->esq);
    printf("%d ", arv->valor);
    imprimeOrdem(arv->dir);
  }
}

void imprimePosOrdem(tipo_arvore_binaria *arv)
{
  if (arv != NULL)
  {
    imprimePosOrdem(arv->esq);
    imprimePosOrdem(arv->dir);
    printf("%d ", arv->valor);
  }
}

#endif