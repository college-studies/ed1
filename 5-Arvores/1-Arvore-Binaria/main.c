#include <stdio.h>
#include <stdlib.h>

#include "arvoreBin.c"

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

  printf("Pre Ordem: ");
  imprimePreOrdem(arvore);

  printf("\nOrdem: ");
  imprimeOrdem(arvore);

  printf("\nPos Ordem: ");
  imprimePosOrdem(arvore);
  printf("\n");

  return 1;
}