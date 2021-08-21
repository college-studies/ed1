#include <stdio.h>
#include <stdlib.h>

#include "arvoreBin.c"
#include "lista.c"


int main()
{
  tipo_arvore_binaria *arvore = NULL;

  insereArvoreBin(&arvore, 10);
  insereArvoreBin(&arvore, 3);
  insereArvoreBin(&arvore, 9);
  insereArvoreBin(&arvore, 13);
  insereArvoreBin(&arvore, 18);
  insereArvoreBin(&arvore, 20);
  insereArvoreBin(&arvore, 40);

  imprimePreOrdem(arvore);
  printf("\n");
  imprimeOrdem(arvore);
  printf("\n");
  imprimePosOrdem(arvore);
  printf("\n");

  return 1;
}