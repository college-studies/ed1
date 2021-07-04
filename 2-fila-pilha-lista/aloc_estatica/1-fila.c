#include <stdio.h>
#define N 10

//Definição de tipo
struct est_fila
{
  int fila[N];
  int contador;
};
typedef struct est_fila tipo_fila;

//Prototipacao
void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl, int valor);
void imprimeFila(tipo_fila fl);
int removeFila(tipo_fila *fl);

int main()
{
  tipo_fila fila;
  inicializaFila(&fila);

  insereFila(&fila, 6);
  insereFila(&fila, 1);
  insereFila(&fila, 7);
  insereFila(&fila, 9);

  imprimeFila(fila);

  printf("Removendo um valor da fila: %d\n", removeFila(&fila));

  imprimeFila(fila);

  return 1;
}

void inicializaFila(tipo_fila *fl)
{
  fl->contador = 0;
}

void insereFila(tipo_fila *fl, int valor)
{
  if (fl->contador < N)
  {
    fl->fila[fl->contador] = valor;
    fl->contador++;
  }
  else
  {
    printf("ERRO Fila esta cheia");
  }
}

int removeFila(tipo_fila *fl)
{
  if (fl->contador > 0)
  {
    int aux, i;
    aux = fl->fila[0];

    // atualiza posicionamento dos valores no ventor;
    for (i = 0; i < fl->contador - 1; i++)
    {
      fl->fila[i] = fl->fila[i + 1];
    }

    fl->contador--;

    return aux;
  }
  else
  {
    printf("ERRO - Fila esta vazia!");
    return -1;
  }
}

void imprimeFila(tipo_fila fl)
{
  int i;
  printf("FILA: [");
  for (i = 0; i < fl.contador; i++)
  {
    printf("%d ", fl.fila[i]);
  }
  printf("]\n");
}