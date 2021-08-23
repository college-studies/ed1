#include <stdio.h>
#include <stdlib.h>

#include "arvoreMultiFilhos.c"

int main()
{
  tipo_arv_mf *arvore;
  arvore = NULL;

  insereArvBin(&arvore, 10);
  insereArvBin(&arvore, 7);
  insereArvBin(&arvore, 1);

  insereArvBin(&arvore, 15);
  insereArvBin(&arvore, 0);
  insereArvBin(&arvore, 5);
  insereArvBin(&arvore, 8);

  percursoPreOrdemMF(arvore);
  printf("\n");

  return 1;
}