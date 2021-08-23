#include <stdio.h>
#include <stdlib.h>

#include "arvoreMultiFilhos.c"
#include "lista.c"


int main()
{
  tipo_arvore_mFilhos *arvore = NULL;

  insereArvoreMFilhos(&arvore, 10);
  insereArvoreMFilhos(&arvore, 7);
  insereArvoreMFilhos(&arvore, 1);

  insereArvoreMFilhos(&arvore, 15);
  insereArvoreMFilhos(&arvore, 0);
  insereArvoreMFilhos(&arvore, 5);
  insereArvoreMFilhos(&arvore, 8);

  percursoPreOrdem(arvore);
  printf("\n");

  return 1;
}