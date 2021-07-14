#include <stdio.h>
#include <stdlib.h>

struct estru_no
{
  int valor;
  struct estru_no *prox;
};
typedef struct estru_no tipo_no;

// Prototipos
tipo_no *alocaNovoNo(int vl);
void insereFinal(tipo_no **fl, int vl);
tipo_no *insereFinal_opcao2(tipo_no *fl, int vl);
int removeInicio(tipo_no **fl);
tipo_no *removeInicio_opcao2(tipo_no *fl);
void imprimeFila(tipo_no *fl);

int main()
{
  // declara e inicializa ponteiro como null
  tipo_no *fila;
  fila = NULL;

  insereFinal(&fila, 7);
  insereFinal(&fila, 10);
  fila = insereFinal_opcao2(fila, 20);

  imprimeFila(fila);

  printf("Valor removido - %d\n", removeInicio(&fila));
  fila = removeInicio_opcao2(fila);

  imprimeFila(fila);

  return 1;
}

void imprimeFila(tipo_no *fl)
{
  printf("Saida <- [ ");
  while (fl != NULL)
  {
    printf("[%d]", fl->valor);
    fl = fl->prox;
  }
  printf(" ] <- Entrada\n");
}

// Funcao que aloca memoria para um TIPO_NO
tipo_no *alocaNovoNo(int vl)
{
  tipo_no *novo_no;
  novo_no = (tipo_no *)malloc(sizeof(tipo_no));
  novo_no->valor = vl;
  novo_no->prox = NULL;

  return novo_no;
}

// funcao que insere novo valor na estrutura encadeada, inserindo no final e usando ponteiro de ponteiro
void insereFinal(tipo_no **fl, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);

  if ((*fl) == NULL)
  {
    (*fl) = novo_no;
  }
  else
  {
    tipo_no *aux;
    aux = (*fl);

    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

// funcao que insere novo valor na estrutura encadeada, retornando endereço do primeiro no
tipo_no *insereFinal_opcao2(tipo_no *fl, int vl)
{
  tipo_no *novo_no, *aux;
  novo_no = alocaNovoNo(vl);

  if (fl == NULL)
  {
    return novo_no; // caso da fila vazia
  }
  else
  {
    aux = fl;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo_no;
    return fl;
  }
}

// Funcao que remove o primeiro no da estrutura encadeada, usando ponteiro para ponteiro
int removeInicio(tipo_no **fl)
{
  tipo_no *aux;
  int vl;

  if ((*fl) != NULL)
  {
    aux = (*fl);
    vl = (*fl)->valor;
    (*fl) = (*fl)->prox;
    free(aux);
    return vl;
  }
  else
  {
    return -1;
  }
}

// Funcao que remove o primeiro no da estrutura encadeada, retornando o endereco de memoria do primeiro nó
tipo_no *removeInicio_opcao2(tipo_no *fl)
{
  tipo_no *aux;

  if (fl != NULL)
  {
    aux = fl;
    fl = fl->prox;
    free(aux);
    return fl;
  }
  else
  {
    return NULL;
  }
}