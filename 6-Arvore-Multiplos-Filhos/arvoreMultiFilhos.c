#ifndef ARVORE_MULTI_FILHOS_C
#define ARVORE_MULTI_FILHOS_C

#define T 3

struct est_arv_mf
{
  int valores[T];
  int cont;
  struct est_arv_mf *filhos[T + 1];
};
typedef struct est_arv_mf tipo_arv_mf;

tipo_arv_mf *alocaNovoNoArvMF(int valor);
void insereArvBin(tipo_arv_mf **arv, int valor);
void percursoPreOrdemMF(tipo_arv_mf *arv);

tipo_arv_mf *alocaNovoNoArvMF(int vl)
{
  int i;
  tipo_arv_mf *novo_no;
  novo_no = (tipo_arv_mf *)malloc(sizeof(tipo_arv_mf));
  novo_no->valores[0] = vl;
  novo_no->cont = 1;

  for (i = 0; i < T + 1; i++)
  {
    novo_no->filhos[i] = NULL;
  }
  return novo_no;
}

void insereArvBin(tipo_arv_mf **arv, int valor)
{
  int i;

  if ((*arv) == NULL)
  {
    (*arv) = alocaNovoNoArvMF(valor);
  }
  else
  {
    if ((*arv)->cont < T)
    {
      i = (*arv)->cont - 1;
      // Realiza uma inserção ordenada
      while ((i >= 0) && ((*arv)->valores[i] > valor))
      {
        (*arv)->valores[i + 1] = (*arv)->valores[i];
        i--;
      }
      (*arv)->valores[i + 1] = valor;
      (*arv)->cont++;
    }
    else
    {
      // No cheio, identifica o filho correto a descer
      i = 0;
      while ((i < T) && ((*arv)->valores[i] < valor))
      {
        i++;
      }
      insereArvBin(&(*arv)->filhos[i], valor);
    }
  }
}

void percursoPreOrdemMF(tipo_arv_mf *arv)
{
  if (arv != NULL)
  {
    int i;
    for (i = 0; i < arv->cont; i++)
    {
      printf("%d ", arv->valores[i]);
    }

    // Verifica se o noh é completo e chama recursivamente para os filhos
    if (arv->cont == T)
    {
      for (i = 0; i < T + 1; i++)
      {
        percursoPreOrdemMF(arv->filhos[i]);
      }
    }
  }
}

#endif
