#ifndef ARVORE_BIN_S
#define ARVORE_BIN_S
struct str_arvoreBin
{
  int valor;
  struct str_arvoreBin *esq;
  struct str_arvoreBin *dir;
};
typedef struct str_arvoreBin tipo_arvore_binaria;

// Prototipos
tipo_arvore_binaria *alocaNovoNoArvoreBin(int valor);
tipo_arvore_binaria *criarArvoreBin();
void insereArvoreBin(tipo_arvore_binaria **arv, int vl);
void imprimePreOrdem(tipo_arvore_binaria *arv);
void imprimeOrdem(tipo_arvore_binaria *arv);
void imprimePosOrdem(tipo_arvore_binaria *arv);
int buscaPorValor(tipo_arvore_binaria *arv, int vl);
void removeElementoArvBin(tipo_arvore_binaria **arv, int vl);
int verificaQtdNos(tipo_arvore_binaria *arv);
int alturaArv(tipo_arvore_binaria *arv);
int encontraMaiorValorArv(tipo_arvore_binaria *arv);
int encontraMenorValorArv(tipo_arvore_binaria *arv);
int calculaAltura(tipo_arvore_binaria *arv);
void imprimeNivel(tipo_arvore_binaria *arv, int nivel);
void ImprimeNivelRec(tipo_arvore_binaria *raiz, int nivel, int nivelPassagem);
void imprimeNosFolhas(tipo_arvore_binaria *arv);
void imprimeNosFolhaArvoreBin(tipo_arvore_binaria *arv);

tipo_arvore_binaria *alocaNovoNoArvoreBin(int valor)
{
  tipo_arvore_binaria *novo_no;
  novo_no = (tipo_arvore_binaria *)malloc(sizeof(tipo_arvore_binaria));
  novo_no->valor = valor;
  novo_no->esq = NULL;
  novo_no->dir = NULL;
  return novo_no;
}

tipo_arvore_binaria *criarArvoreBin()
{
  tipo_arvore_binaria *aux = NULL;
  return aux;
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
    printf(" %d ", arv->valor);
    imprimePreOrdem(arv->esq);
    imprimePreOrdem(arv->dir);
  }
}

void imprimeOrdem(tipo_arvore_binaria *arv)
{
  if (arv != NULL)
  {
    imprimeOrdem(arv->esq);
    printf(" %d ", arv->valor);
    imprimeOrdem(arv->dir);
  }
}

void imprimePosOrdem(tipo_arvore_binaria *arv)
{
  if (arv != NULL)
  {
    imprimePosOrdem(arv->esq);
    imprimePosOrdem(arv->dir);
    printf(" %d ", arv->valor);
  }
}

int buscaPorValor(tipo_arvore_binaria *arv, int vl)
{
  if (arv == NULL)
  {
    return 0;
  }
  else
  {
    if (arv->valor == vl)
    {
      return 1;
    }
    else
    {
      if (vl < arv->valor)
      {
        return buscaPorValor(arv->esq, vl);
      }
      else
      {
        return buscaPorValor(arv->dir, vl);
      }
    }
  }
}

int encontraMaiorValorArv(tipo_arvore_binaria *arv)
{
  if (arv->dir == NULL)
    return arv->valor;
  else
    return encontraMaiorValorArv(arv->dir);
}

int encontraMenorValorArv(tipo_arvore_binaria *arv)
{
  if (arv->esq == NULL)
    return arv->valor;
  else
    return encontraMenorValorArv(arv->esq);
}

void removeElementoArvBin(tipo_arvore_binaria **arv, int vl)
{
  int aux;
  if ((*arv) != NULL)
  {
    //Busca valor
    if ((*arv)->valor != vl)
    {
      if (vl < (*arv)->valor)
        removeElementoArvBin(&(*arv)->esq, vl);
      else
        removeElementoArvBin(&(*arv)->dir, vl);
    }
    else
    {
      //Caso encontrado e noh for folha, desaloca e atualiza ponteiro
      if (((*arv)->esq == NULL) && ((*arv)->dir == NULL))
      {
        free((*arv));
        (*arv) = NULL;

      } //Caso exista apenas filho esquerdo
      else if (((*arv)->esq != NULL) && ((*arv)->dir == NULL))
      {
        aux = encontraMaiorValorArv((*arv)->esq);
        (*arv)->valor = aux;
        removeElementoArvBin(&(*arv)->esq, aux);
      }

      //Caso tenha dois filhos ou só o direito
      else
      {
        aux = encontraMenorValorArv((*arv)->dir);
        (*arv)->valor = aux;
        removeElementoArvBin(&(*arv)->dir, aux);
      }
    }
  }
}

int verificaQtdNos(tipo_arvore_binaria *arv)
{
  if (arv == NULL)
  {
    return 0;
  }
  else
  {
    return (1 + verificaQtdNos(arv->esq) + verificaQtdNos(arv->dir));
  }
}

int alturaArv(tipo_arvore_binaria *arv)
{
  int alturaEsq, alturaDir;

  if (arv == NULL)
  {
    return 0;
  }
  else
  {
    alturaEsq = calculaAltura(arv->esq);
    alturaDir = calculaAltura(arv->dir);

    if (alturaEsq > alturaDir)
    {
      return alturaEsq;
    }
    else
    {
      return alturaDir;
    }
  }
}

int calculaAltura(tipo_arvore_binaria *arv)
{
  int alturaEsq, alturaDir;

  if (arv == NULL)
  {
    return 0;
  }
  else
  {
    alturaEsq = calculaAltura(arv->esq);
    alturaDir = calculaAltura(arv->dir);
    if (alturaEsq > alturaDir)
      return (alturaEsq + 1);
    else
      return (alturaDir + 1);
  }
}

void imprimeNosFolhas(tipo_arvore_binaria *arv)
{
  imprimeNivel(arv, alturaArv(arv));
}

void imprimeNivel(tipo_arvore_binaria *arv, int nivel)
{
  printf("[ ");
  ImprimeNivelRec(arv, nivel, 0);
  printf("]\n");
}

void ImprimeNivelRec(tipo_arvore_binaria *raiz, int nivel, int nivelPassagem)
{
  tipo_arvore_binaria *aux;
  aux = raiz;
  if (raiz != NULL)
  {
    ImprimeNivelRec(aux->esq, nivel, nivelPassagem + 1);
    ImprimeNivelRec(aux->dir, nivel, nivelPassagem + 1);
    if (nivel == nivelPassagem)
    {
      printf("%d ", aux->valor);
    }
  }
}

void imprimeNosFolhaArvoreBin(tipo_arvore_binaria *arv)
{
  imprimeNivel(arv, alturaArv(arv));
}

#endif
