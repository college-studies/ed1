#include <stdio.h>
#include <stdlib.h>

#include "arvoreBin.c"
#include "arvoreMF.c"

int main()
{
  // ---------------------------Arvore Binária------------------------------------- //

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

  int buscarValor = 40;
  if (buscaPorValor(arvore, buscarValor))
    printf("\nValor presente %d na arvore\n\n", buscarValor);
  else
    printf("\nValor %d não existe na arvore\n\n", buscarValor);

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

  printf("\n");

  printf("// ---------------------------Arvore MF------------------------------------- //\n");
  tipo_arv_mf *arvoreMF;
  arvoreMF = NULL;

  insereArvBin(&arvoreMF, 10);
  insereArvBin(&arvoreMF, 7);
  insereArvBin(&arvoreMF, 1);

  insereArvBin(&arvoreMF, 15);
  insereArvBin(&arvoreMF, 0);
  insereArvBin(&arvoreMF, 5);
  insereArvBin(&arvoreMF, 8);

  printf("Pre Ordem :  ");
  percursoPreOrdemMF(arvoreMF);

  printf("\nOrdem :      ");
  percursoOrdemMF(arvoreMF);

  printf("\nPos Ordem:   ");
  percursoPosOrdemMF(arvoreMF);
  printf("\n");

  int buscarValorMF = 8;
  if (buscaPorValorMF(arvoreMF, buscarValorMF))
    printf("\nValor %d presente na arvore\n\n", buscarValorMF);
  else
    printf("\nValor %d não existe na arvore\n\n", buscarValorMF);

  int removeMF = 8;
  printf("Removendo valor %d\n", removeMF);
  removeValorArvMF(&arvoreMF, 8);
  printf("\n");

  printf("Arvore MF Após remoção: ");
  percursoPreOrdemMF(arvoreMF);
  printf("\n");

  if (buscaPorValorMF(arvoreMF, buscarValorMF))
    printf("\nValor %d presente na arvore\n\n", buscarValorMF);
  else
    printf("\nValor %d não existe na arvore\n\n", buscarValorMF);

  printf("Altura Arvore MF: %d\n", checaAlturaArvMF(arvoreMF));

  printf("\nQtd total Valores na Arvore MF: %d\n", qtdValoresNaArvMF(arvoreMF));

  return 1;
}