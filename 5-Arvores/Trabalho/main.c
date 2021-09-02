#include <stdio.h>
#include <stdlib.h>

#include "arvoreBin.c"
#include "arvoreMF.c"

int main()
{
  printf("// ---------------------------Arvore Binária------------------------------------- //\n\n");

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

  printf("// ---------------------------Arvore MF------------------------------------- //\n\n");
  tipo_arv_mf *arvoreMF;
  arvoreMF = NULL;

  insereArvMF(&arvoreMF, 10);
  insereArvMF(&arvoreMF, 7);
  insereArvMF(&arvoreMF, 1);

  insereArvMF(&arvoreMF, 15);
  insereArvMF(&arvoreMF, 0);
  insereArvMF(&arvoreMF, 5);
  insereArvMF(&arvoreMF, 8);

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

  int nivelMF = 0;
  printf("\nImpressao de valores no nivel %d: ", nivel);
  imprimeValoresPorNivelMF(arvoreMF, nivelMF);

  printf("\nImpressao de nos folha: ");
  imprimeNosFolhaArvoreMF(arvoreMF);

  return 1;
}