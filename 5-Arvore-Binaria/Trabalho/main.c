#include <stdio.h>
#include <stdlib.h>

#include "arvoreBin.c"

int main()
{
  tipo_arvore_binaria *arvore = criarArvoreBin();

  insereArvoreBin(&arvore, 10);
  insereArvoreBin(&arvore, 3);
  insereArvoreBin(&arvore, 9);
  insereArvoreBin(&arvore, 13);
  insereArvoreBin(&arvore, 18);
  insereArvoreBin(&arvore, 20);
  insereArvoreBin(&arvore, 40);

  printf("Pre Ordem :  ");
  imprimePreOrdem(arvore);

  printf("\nOrdem :      ");
  imprimeOrdem(arvore);

  printf("\nPos Ordem:   ");
  imprimePosOrdem(arvore);
  printf("\n");

  if (buscaPorValor(arvore, 40))
    printf("Valor presente na arvore\n\n");
  else
    printf("Valor não existe na arvore\n\n");

  int removeElemento = 40;
  printf("Remove Elemento: %d\n\nArvore Após remoção:", removeElemento);
  removeElementoArvBin(&arvore, removeElemento);
  imprimePreOrdem(arvore);
  printf("\n");

  printf("\nQuantidade de Nos: %d\n", verificaQtdNos(arvore));

  printf("\nAltura da Arvore: %d\n", alturaArv(arvore));

  int nivel = 1;
  printf("\nValores no nivel [%d] : ", nivel);
  imprimeNivel(arvore, nivel);
  printf("\n");

  printf("Nos Folhas: ");
  imprimeNosFolhaArvoreBin(arvore);

  return 1;
}