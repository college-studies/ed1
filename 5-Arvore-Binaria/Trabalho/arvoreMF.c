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
void percursoOrdemMF(tipo_arv_mf *arv);
void percursoPosOrdemMF(tipo_arv_mf *arv);
int buscaPorValorMF(tipo_arv_mf *arv, int valor);
void removeValorArvMF(tipo_arv_mf **arv, int valor);
int verificaNoEhFolha(tipo_arv_mf *arv);
int maior(tipo_arv_mf *arv);
int menor(tipo_arv_mf *arv);
int checaAlturaArvMF(tipo_arv_mf *arv);
int qtdValoresNaArvMF(tipo_arv_mf *arv);

// TODO: implement
void imprimeNosFolhaArvoreMF(tipo_arv_mf *arv);
void imprimeValoresPorNivelMF(tipo_arv_mf *arv, int nivel);

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
      printf(" %d ", arv->valores[i]);
    }

    if (arv->cont == T)
    {
      for (i = 0; i < T + 1; i++)
      {
        percursoPreOrdemMF(arv->filhos[i]);
      }
    }
  }
}

void percursoOrdemMF(tipo_arv_mf *arv)
{
  int i;
  if (arv != NULL)
  {
    for (i = 0; i < arv->cont; i++)
    {
      percursoOrdemMF(arv->filhos[i]);
      printf(" %d ", arv->valores[i]);
    }
    percursoOrdemMF(arv->filhos[i]);
  }
}

void percursoPosOrdemMF(tipo_arv_mf *arv)
{
  int i;

  if (arv != NULL)
  {

    for (i = 0; i < arv->cont + 1; i++)
    {
      percursoPosOrdemMF(arv->filhos[i]);
    }

    for (i = 0; i < arv->cont; i++)
    {
      printf(" %d ", arv->valores[i]);
    }
  }
}

int buscaPorValorMF(tipo_arv_mf *arv, int vl)
{
  int i;

  if (arv == NULL)
  {
    return 0;
  }
  else
  {
    i = 0;
    while ((i < arv->cont) && (arv->valores[i] < vl))
    {
      i++;
    }

    if ((i < arv->cont) && (arv->valores[i] == vl))
    {
      return 1;
    }
    else
    {
      return buscaPorValorMF(arv->filhos[i], vl);
    }
  }
}

void removeValorArvMF(tipo_arv_mf **arv, int valor)
{
  int i, aux, indiceFilho, indicePai;

  if ((*arv) != NULL)
  {
    //Busca por valor
    i = 0;
    while ((i < (*arv)->cont) && ((*arv)->valores[i] < valor))
      i++;

    if (i < (*arv)->cont)
    {
      //Verifica se encontramos o filho e descemos
      if (valor < (*arv)->valores[i])
      {
        removeValorArvMF(&(*arv)->filhos[i], valor);
      }

      else
      {
        //Se o valor foi encontrado, verificar se é folha
        if (verificaNoEhFolha(*arv))
        {

          // Verifica se tem 1 unico valor
          if ((*arv)->cont == 1)
          {
            free(*arv);
            (*arv) = NULL;
          }

          else
          {
            // Caso tenha mais de 1
            while (i < ((*arv)->cont - 1))
            {
              (*arv)->valores[i] = (*arv)->valores[i + 1];
              i++;
            }
            (*arv)->cont--;
          }
        }

        else
        {
          //Verifica se possui filho esq caso o no não seja folha
          if ((*arv)->filhos[i] != NULL)
          {
            aux = maior((*arv)->filhos[i]);
            (*arv)->valores[i] = aux;
            removeValorArvMF(&(*arv)->filhos[i], aux);
          }

          else if ((*arv)->filhos[i + 1] != NULL)
          {
            // Verifica se existe filho a direita
            aux = menor((*arv)->filhos[i + 1]);
            (*arv)->valores[i] = aux;
            removeValorArvMF(&(*arv)->filhos[i + 1], aux);
          }

          else
          {

            //Se n tem filho, verifica qual a posicao do primeiro disponivel
            indiceFilho = 0;
            while ((indiceFilho <= (*arv)->cont) && ((*arv)->filhos[indiceFilho] == NULL))
            {
              indiceFilho++;
            }

            // Verifica pai em relacao ao filho
            if (indiceFilho < (*arv)->cont)
            {
              indicePai = indiceFilho;
            }
            else
            {
              indicePai = indiceFilho - 1;
            }

            //Verifica se o filho disponivel esta a direita ou esquerda em relacao ao valor
            if (i < indicePai)
            {

              // Caso esteja a direita, reposicionar valores do no e trazer ao inicio
              if (indicePai == indiceFilho)
              {
                //Filho esquerdo
                while (i < indicePai - 1)
                {
                  (*arv)->valores[i] = (*arv)->valores[i + 1];
                  (*arv)->filhos[i] = (*arv)->filhos[i + 1];
                  i++;
                }
              }

              else
              {

                // Caso seja o ultimo filho do no
                while (i < indicePai)
                {
                  (*arv)->valores[i] = (*arv)->valores[i + 1];
                  i++;
                }
              }

              aux = menor((*arv)->filhos[indiceFilho]);
              (*arv)->valores[i] = aux;
              removeValorArvMF(&(*arv)->filhos[indiceFilho], aux);
            }

            else
            {

              //Filho a esquerda -> Reposicionar valor no no e levar para tras
              while (i > indicePai)
              {
                (*arv)->valores[i] = (*arv)->valores[i - 1];
                (*arv)->filhos[i] = (*arv)->filhos[i - 1];
                i--;
              }

              aux = maior((*arv)->filhos[indiceFilho]);
              (*arv)->valores[i] = aux;
              removeValorArvMF(&(*arv)->filhos[indiceFilho], aux);
            }
          }
        }
      }
    }

    else
    {
      // Vai ate o ultimo filho do no
      removeValorArvMF(&(*arv)->filhos[i], valor);
    }
  }
}

int verificaNoEhFolha(tipo_arv_mf *arv)
{
  int i;
  for (i = 0; i <= arv->cont; i++)
    if (arv->filhos[i] != NULL)
      return 0;
  return 1;
}

int maior(tipo_arv_mf *arv)
{
  if (arv != NULL)
  {
    if (arv->filhos[arv->cont] == NULL)
      return arv->valores[(arv->cont) - 1];
    else
      return maior(arv->filhos[arv->cont]);
  }
  return 1;
}
int menor(tipo_arv_mf *arv)
{
  if (arv != NULL)
  {
    if (arv->filhos[0] == NULL)
      return arv->valores[0];
    else
      return menor(arv->filhos[0]);
  }
  return 1;
}

int checaAlturaArvMF(tipo_arv_mf *arv)
{
  if (arv == NULL)
  {
    return 0;
  }

  else
  {
    int i, maiorAltura, alturaDoFilho;
    maiorAltura = 0;

    for (i = 0; i <= arv->cont; i++)
    {
      alturaDoFilho = checaAlturaArvMF(arv->filhos[i]);

      if (alturaDoFilho > maiorAltura)
      {
        maiorAltura = alturaDoFilho;
      }
      return maiorAltura + 1;
    }
  }
  return 1;
}

int qtdValoresNaArvMF(tipo_arv_mf *arv)
{
  if (arv == NULL)
  {
    return 0;
  }

  else
  {
    int i, cont = 0;

    for (i = 0; i <= arv->cont; i++)
    {
      cont = cont + qtdValoresNaArvMF(arv->filhos[i]);
    }

    return (cont + arv->cont);
  }
}

void imprimeNosFolhaArvoreMF(tipo_arv_mf *arv)
{
}

void imprimeValoresPorNivelMF(tipo_arv_mf *arv, int nivel)
{
}

#endif
