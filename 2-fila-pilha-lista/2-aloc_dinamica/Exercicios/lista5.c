// Aluno: Fillipe Augusto de Siqueira Gomes - RGA: 201811722002
// LISTA 5

// ---------------------------PROBLEMA 1-----------------------------------
// Quais as vantagens e desvantagens de representar um grupo de dados utilizando um vetor versus uma lista ligada linear ?

// Resposta: A lista ligada tem como vantagem o fato de que os elementos podem ser adicionados indefinitivamente,
// enquanto que o vetor chegara num ponto em que precisara ser redimensionado para continuar adicionando elementos
// e em certos casos isso pode ter um certo custo. Outra comparação é o fato de que na lista ligada podemos remover
// mais facilmente os elementos e reposicionar a lista, enquanto que no vetor sobrara espaços vazios, assim desperdicando memoria

// ---------------------------PROBLEMA 2-----------------------------------

#include <stdio.h>
#include <stdlib.h>

struct estru_no
{
  int valor;
  struct estru_no *prox;
};
typedef struct estru_no tipo_no;

// Prototipação
tipo_no *alocaNovoNo(int vl);
void imprimeLista(tipo_no *lst);
void insereInicio(tipo_no **lst, int vl);
void insereFim(tipo_no **lst, int vl);
void inserePosicao(tipo_no **lst, int vl, int pos);
int removeInicio(tipo_no **lst);
int removeFim(tipo_no **lst);
int removePosicao(tipo_no **lst, int pos);

tipo_no *concatenar_listas(tipo_no *lst1, tipo_no *lst2);
tipo_no *copia_lista(tipo_no *lst);
void liberar_lista(tipo_no **lst);
void inverter_lista(tipo_no **lst);
tipo_no *combinar_listas_ordenadas(tipo_no *lst1, tipo_no *lst2);
tipo_no *lst_contendo_interseccao(tipo_no *lst1, tipo_no *lst2);
int qtd_elementos_na_lista(tipo_no *lst);
tipo_no *endereco_do_no(tipo_no *lst, int valor);
void deslocar_posicao_no(tipo_no **lst, int valor, int pos);

int main()
{
  tipo_no *lst1 = NULL;
  tipo_no *lst2 = NULL;
  tipo_no *lst3 = NULL;

  insereInicio(&lst1, 1);
  insereInicio(&lst1, 4);
  insereInicio(&lst1, 7);
  insereInicio(&lst1, 3);
  insereInicio(&lst1, 2);
  insereInicio(&lst1, 3);
  insereInicio(&lst1, 9);

  // Lista 1
  printf("Lista 1:");
  imprimeLista(lst1);

  insereFim(&lst2, 4);
  insereFim(&lst2, 1);
  insereFim(&lst2, 4);
  insereFim(&lst2, 12);
  insereFim(&lst2, 5);

  // Lista 2
  printf("\nLista 2:");
  imprimeLista(lst2);

  // Exercício 1
  printf("\nLista Concatenada:");
  lst3 = concatenar_listas(lst1, lst2);
  imprimeLista(lst3);

  //Exercício 2
  liberar_lista(&lst3);
  printf("\nLista Liberar nós:");
  imprimeLista(lst3);

  // Exercício 3
  tipo_no *lst_invertida = lst1;
  inverter_lista(&lst_invertida);
  printf("\nLista Invertida:");
  imprimeLista(lst_invertida);

  // Exercicio 4
  tipo_no *lst_ordenada = NULL;
  lst_ordenada = combinar_listas_ordenadas(lst2, lst3);
  printf("\nLista Combinada e Ordeanda :");
  imprimeLista(lst_ordenada);

  // Exercício 5
  tipo_no *lst_interseccao = NULL;
  lst_interseccao = lst_contendo_interseccao(lst1, lst2);
  printf("\nLista Interseccao:");
  imprimeLista(lst_interseccao);

  // Exercício 6
  inserePosicao(&lst2, 100, 4);
  printf("\nLista Enesimo termo:");
  imprimeLista(lst2);

  // Exercício 7
  printf("\nLista Quantidade Elementos:");
  imprimeLista(lst2);
  printf("Qtd Elementos = %d elementos na lista\n", qtd_elementos_na_lista(lst2));

  // Exercício 8
  tipo_no *encontrar_no;
  encontrar_no = endereco_do_no(lst2, 100);
  if (encontrar_no == NULL)
    printf("\nValor nao encontrado\n");
  printf("\nValor %d encontrado\n", encontrar_no->valor);

  // Exercicio 9
  deslocar_posicao_no(&lst2, 100, 1);
  printf("\nLista Deslocar nó:");
  imprimeLista(lst2);

  // Exercicio 100
  tipo_no *listaCopiada = copia_lista(lst2);
  printf("\nLista Coppia:");
  imprimeLista(listaCopiada);
}

// Funcao que aloca memoria para um tipo_no
tipo_no *alocaNovoNo(int vl)
{
  tipo_no *novo_no;
  novo_no = (tipo_no *)malloc(sizeof(tipo_no));
  novo_no->valor = vl;
  novo_no->prox = NULL;
  return novo_no;
}

// Funcao de impressao da lista
void imprimeLista(tipo_no *lst)
{
  printf(" [ ");
  while (lst != NULL)
  {
    printf("%d ", lst->valor);
    lst = lst->prox;
  }
  printf("]\n");
}

// --------------------------Funções Inserção Lista-------------------------------------- //

//Funcao que insere no inicio da lista
void insereInicio(tipo_no **lst, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);
  novo_no->prox = (*lst);
  (*lst) = novo_no;
}

// Funcao que insere no final da lista
void insereFim(tipo_no **lst, int vl)
{
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);

  if ((*lst) == NULL)
  {
    (*lst) = novo_no;
  }
  else
  {
    tipo_no *aux;
    aux = *lst;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

// Funcao que insere por posicao
void inserePosicao(tipo_no **lst, int vl, int pos)
{
  tipo_no *novo_no, *aux, *aux2;
  int contador;

  if (pos == 0)
  {
    insereInicio(lst, vl);
  }
  else
  {
    aux = (*lst);
    contador = 0;
    while ((aux != NULL) && (contador < pos))
    {
      aux2 = aux;
      aux = aux->prox;
      contador++;
    }
    if ((aux != NULL) && (contador == pos))
    {
      novo_no = alocaNovoNo(vl);
      novo_no->prox = aux;
      aux2->prox = novo_no;
    }
    else if ((aux == NULL) && (contador == pos))
    {
      novo_no = alocaNovoNo(vl);
      aux2->prox = novo_no;
    }
    else
    {
      printf("[ERRO] - POSICAO (%d) INVALIDA PARA INSERCAO DE VALOR (%d) NA LISTA\n", pos, vl);
    }
  }
}

// ------------------------------------------------------------------------------ //
// Funcao que remove o primeiro no da lista
int removeInicio(tipo_no **lst)
{
  tipo_no *aux;
  int vl;

  if ((*lst) != NULL)
  {
    aux = (*lst);
    vl = (*lst)->valor;
    (*lst) = (*lst)->prox;
    free(aux);
    return vl;
  }
  else
  {
    return -1;
  }
}

// Funcao que remove o ultimo no da lista
int removeFim(tipo_no **lst)
{
  tipo_no *aux, *aux2;
  int valor;

  if (*lst != NULL)
  {
    if ((*lst)->prox == NULL)
    {
      return removeInicio(&(*lst));
    }
    else
    {
      aux = (*lst);
      while (aux->prox != NULL)
      {
        aux2 = aux;
        aux = aux->prox;
      }
      valor = aux->valor;
      free(aux);
      aux2->prox = NULL;
      return valor;
    }
  }
  else
  {
    return -1;
  }
}

// Funcao que remove no em posicao especifica
int removePosicao(tipo_no **lst, int pos)
{
  tipo_no *aux, *aux2;
  int contador, vl;

  if ((*lst) != NULL)
  {
    if (pos == 0)
    {
      return removeInicio(lst);
    }
    else
    {
      aux = (*lst);
      contador = 0;
      while ((aux != NULL) && (contador < pos))
      {
        aux2 = aux;
        aux = aux->prox;
        contador++;
      }
      if (aux != NULL)
      {
        vl = aux->valor;
        aux2->prox = aux->prox;
        free(aux);
        return vl;
      }
      else
      {
        printf("ERRO - POSICAO (%d) Invalida para remocao\n", pos);
        return -1;
      }
    }
  }
  else
  {
    printf("ERRO - Lista esta vazia\n");
    return -1;
  }
}

// -------------------------------------- OPERAÇÕES ------------------------------------------- //
// 1 -  Concatenar duas listas (juntá-las, {Lista1+Lista2});
tipo_no *concatenar_listas(tipo_no *lst1, tipo_no *lst2)
{
  tipo_no *resultado = copia_lista(lst1), *aux, *copia_res = NULL;
  copia_res = copia_lista(lst2);

  aux = resultado;
  if (aux == NULL)
  {
    resultado = copia_res;
  }
  else
  {
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = copia_res;
  }
  return resultado;
}

// 2 - Liberar nós da lista
void liberar_lista(tipo_no **lst)
{
  tipo_no *aux = *lst;
  while (aux != NULL)
  {
    *lst = (*lst)->prox;
    free(aux);
    aux = *lst;
  }
}

// 3 - inverter uma lista de modo que o último elemento se torne o primeiro e assim por diante;
void inverter_lista(tipo_no **lst)
{
  tipo_no *invertida = NULL;
  int valor;

  while (*lst != NULL)
  {
    valor = removeFim(&(*lst));
    insereFim(&invertida, valor);
  }
  *lst = invertida;
}

// 4 - Combinar duas listas ja ordenadas numa unica lista ordenada.
tipo_no *combinar_listas_ordenadas(tipo_no *lst1, tipo_no *lst2)
{
  tipo_no *lstCombinadaOrdenada = NULL;

  if (lst1->valor < lst1->prox->valor)
  {
    while (lst1 != NULL && lst2 != NULL)
    {
      if (lst1->valor < lst2->valor)
      {
        insereFim(&lstCombinadaOrdenada, lst1->valor);
        lst1 = lst1->prox;
      }
      else
      {
        insereFim(&lstCombinadaOrdenada, lst2->valor);
        lst2 = lst2->prox;
      }
    }
  }
  else
  {
    while (lst1 != NULL && lst2 != NULL)
    {
      if (lst1->valor > lst2->valor)
      {
        insereFim(&lstCombinadaOrdenada, lst1->valor);
        lst1 = lst1->prox;
      }
      else
      {
        insereFim(&lstCombinadaOrdenada, lst2->valor);
        lst2 = lst2->prox;
      }
    }
  }

  if (lst1 == NULL && lst2 != NULL)
  {
    while (lst2 != NULL)
    {
      insereFim(&lstCombinadaOrdenada, lst2->valor);
      lst2 = lst2->prox;
    }
  }

  if (lst1 != NULL && lst2 == NULL)
  {
    while (lst1 != NULL)
    {
      insereFim(&lstCombinadaOrdenada, lst1->valor);
      lst1 = lst1->prox;
    }
  }

  return lstCombinadaOrdenada;
}

// 5 - Formar uma lista contendo a interseção dos elementos de duas listas (apenas os valores comuns);
tipo_no *lst_contendo_interseccao(tipo_no *lst1, tipo_no *lst2)
{
  tipo_no *lstInterseccao = NULL;
  tipo_no *aux = lst1, *aux2;

  while (aux != NULL)
  {
    aux2 = lst2;

    while (aux2 != NULL)
    {
      if (aux->valor == aux2->valor)
      {
        insereFim(&lstInterseccao, aux2->valor);
      }
      aux2 = aux2->prox;
    }
    aux = aux->prox;
  }

  return lstInterseccao;
}

// 6 - Insereir um elemento depois do enensimo elemento de uma lista;
// --- Feita utilizando a implementacao de inserção por posição

// 7 - Retornar o número de elementos da lista
int qtd_elementos_na_lista(tipo_no *lst)
{
  int cont = 0;

  while (lst != NULL)
  {
    cont++;
    lst = lst->prox;
  }
  return cont;
}

// 8 - Retorne um ponteiro (endereço de memória) para o nó com o valor do dado igual a x (parametro);
tipo_no *endereco_do_no(tipo_no *lst, int valor)
{
  while (lst != NULL && valor != lst->valor)
  {
    lst = lst->prox;
  }

  if ((lst != NULL) && (valor = lst->valor))
  {
    return lst;
  }
  return NULL;
}

// 9 - Deslocar um dterminado nó com o dado igual a x (parametro), para n (parametro) posições a frente (sempre da posicao dele para a frente - indices maiores)
void deslocar_posicao_no(tipo_no **lst, int valor, int pos)
{
  tipo_no *aux = *lst;
  tipo_no *aux2;
  tipo_no *aux3;
  int cont;

  while (aux != NULL && (valor != aux->valor))
  {
    aux2 = aux;
    aux = aux->prox;
  }

  if (aux != NULL && (valor == aux->valor))
  {
    aux3 = aux;
    aux2->prox = aux->prox;
    aux = aux->prox;
    while (aux != NULL && (cont < pos))
    {
      aux2 = aux;
      aux = aux->prox;
      cont++;
    }
    if (cont == pos)
    {
      aux2->prox = aux3;
      aux3->prox = aux;
    }
    else
    {
      printf("[ERRO] - Posicao invalida\n");
    }
  }
  else
  {
    printf("[ERRO] - Valor não encontrado\n");
  }
}

// 10 - Criar copia de uma Lista
tipo_no *copia_lista(tipo_no *lst)
{
  tipo_no *listaCopia = NULL;

  if (lst == NULL)
  {
    return listaCopia;
  }
  else
  {
    tipo_no *aux = lst;
    while (aux != NULL)
    {
      insereFim(&listaCopia, aux->valor);
      aux = aux->prox;
    }
    return listaCopia;
  }
}