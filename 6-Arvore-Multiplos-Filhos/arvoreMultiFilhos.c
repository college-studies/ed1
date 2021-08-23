#ifndef ARVORE_MULTI_FILHOS_C
#define ARVORE_MULTI_FILHOS_C

#define T 3

struct str_arvore_multi_filhos
{
  int valores[T];
  int cont;
  struct str_arvore_multi_filhos *filhos[T + 1];
};
typedef struct str_arvore_multi_filhos tipo_arvore_mFilhos;

tipo_arvore_mFilhos *alocaNovoNoArvoreMFilhos(int vl);
void insereArvoreMFilhos(tipo_arvore_mFilhos **arv, int vl);
void percursoPreOrdem(tipo_arvore_mFilhos *arv);

tipo_arvore_mFilhos *alocaNovoNoArvoreMFilhos(int vl) {
  int i;
  tipo_arvore_mFilhos *novoNo;
  novoNo = (tipo_arvore_mFilhos*) malloc(sizeof(tipo_arvore_mFilhos));
  novoNo->valores[0] = vl;
  novoNo->cont = 1;
  for (i = 0; i < T + 1; i++)
  {
    novoNo->filhos[i]=NULL;
  }
  return novoNo;
}

void insereArvoreMFilhos(tipo_arvore_mFilhos **arv, int vl) {
  int i;
  if((*arv) == NULL) {
    (*arv) = alocaNovoNoArvoreMFilhos(vl);
  } else {
    if ((*arv)->cont < T) {
      i = (*arv)->cont - 1;
      while ((i>=0) && ((*arv)->valores[i] > vl))
      {
        (*arv)->valores[i + 1] = (*arv)->valores[i];
        i--; 
      }
      (*arv)->valores[i + 1] = vl;
      (*arv)->cont++;
    } else {
      i = 0;
      while ((i < T) && ((*arv)->valores[i] < vl))
      {
        i++;
      }
      insereArvoreMFilhos(&(*arv)->filhos[i], vl);
    }
  }
}

void percursoPreOrdem(tipo_arvore_mFilhos *arv) 
{
  if (arv != NULL) 
  {
    int i;
    for (i = 0; i < arv->cont; i++)
    {
      printf("%d ", arv->valores[i]);
    }
    
    if (arv->cont == T) 
    {
      for (i = 0; i < T + 1; i++)
      {
        percursoPreOrdem(arv->filhos[i]);
      }
      
    }
    
  }
}

#endif 
