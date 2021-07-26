#include <stdio.h>
#include <stdlib.h>

#define N 10

struct est_fila
{
  int fila[N];
  int cont;
};
typedef struct est_fila Fila;

void inicializa_fila(Fila *fl);
void insere(Fila *fl, int valor);
void imprime(Fila fl);
int remocao(Fila *fl);

int main()
{
  int opt = 1, menu_selec;
  int cont_exatas = 0;
  int cont_saude = 0;
  int cont_humanas = 0;

  int aten_exatas = 0;
  int aten_saude = 0;
  int aten_humanas = 0;

  int pg1, pg2, pg3, pg4;

  Fila fila;
  inicializa_fila(&fila);

  Fila exatas, humanas, saude;

  inicializa_fila(&exatas);
  inicializa_fila(&saude);
  inicializa_fila(&humanas);

  while (opt == 1)
  {
    printf("=============================================\n");
    printf("Filas de Espera: \nExatas: %d \nSaude: %d\nHumanas: %d\n", cont_exatas, cont_saude, cont_humanas);
    printf("=============================================\n\n");
    printf("1: Atendimento\n2: Senha\n0: Sair\n");
    printf("Selecione uma opção: ");
    scanf("%d", &menu_selec);

    if (menu_selec == 1)
    {
      pg4 = 0;
      while (pg4 != 1)
      {
        printf("=============================================\n\n");
        printf("0 - Voltar \n1 - Exatas \n2 - Saude \n3 - Humanas\n");
        printf("Selecione A area de atendimento: ");
        scanf("%d", &pg1);

        if (pg1 == 1)
        {
          if (cont_exatas > 0)
          {
            printf("Quantos estudantes deseja atender:");
            scanf("%d", &aten_exatas);
            if (aten_exatas < cont_exatas)
            {
              printf("Senhas atendidas: [ ");
              int i;
              for (i = 0; i < aten_exatas; i++)
              {
                printf("%d ", remocao(&exatas));
                cont_exatas--;
              }
              printf(" ]\n");
            }
            else
            {
              printf("Estudantes insuficientes para atendimento\n");
            }
          }
          else
          {
            printf("Fila de atendimento vazia\n");
          }
        }
        else if (pg1 == 2)
        {
          if (cont_saude > 0)
          {
            printf("Quantos estudantes deseja atender:");
            scanf("%d", &aten_saude);
            if (aten_saude < cont_saude)
            {
              printf("Senhas atendidas: [ ");
              int i;
              for (i = 0; i < aten_saude; i++)
              {
                printf("%d ", remocao(&saude));
                cont_saude--;
              }
              printf(" ]\n");
            }
            else
            {
              printf("Estudantes insuficientes para atendimento\n");
            }
          }
          else
          {
            printf("Fila de atendimento vazia\n");
          }
        }
        else if (pg1 == 3)
        {
          if (cont_humanas > 0)
          {
            printf("Quantos estudantes deseja atender:");
            scanf("%d", &aten_humanas);
            if (aten_humanas < cont_humanas)
            {
              printf("Senhas atendidas: [ ");
              int i;
              for (i = 0; i < aten_humanas; i++)
              {
                printf("%d ", remocao(&saude));
                cont_humanas--;
              }
              printf(" ]\n");
            }
            else
            {
              printf("Estudantes insuficientes para atendimento\n");
            }
          }
          else
          {
            printf("Fila de atendimento vazia\n");
          }
        }
        else
        {
          pg4 = 1;
        }
      }
    }

    else if (menu_selec == 2)
    {
      pg3 = 0;
      while (pg3 != 1)
      {
        printf("=============================================\n\n");
        printf("Departamento do Estudante:\n0 - Voltar\n4 - Exatas\n5 - Saude\n6 - Humanas\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &pg2);

        if (pg2 == 4)
        {
          insere(&exatas, ++cont_exatas);
          printf("\nSenha: %d\n", cont_exatas);
          printf("=============================================\n");
        }
        else if (pg2 == 5)
        {
          insere(&humanas, ++cont_saude);
          printf("Senha: %d\n", cont_saude);
        }
        else if (pg2 == 6)
        {
          insere(&humanas, ++cont_humanas);
          printf("Senha: %d\n", cont_humanas);
        }
        else
        {
          pg3 = 1;
        }
      }
    }
    else
    {
      break;
    }
  }

  return 1;
}

void inicializa_fila(Fila *fl)
{
  fl->cont = 0;
}

void imprime(Fila fl)
{
  printf("[ ");
  for (int i = 0; i < fl.cont; i++)
    printf(" [%d] ", fl.fila[i]);

  printf(" ] \n");
}

void insere(Fila *fl, int valor)
{
  if (fl->cont < N)
  {
    fl->fila[fl->cont] = valor;
    fl->cont++;
  }
  else
  {
    printf("ERRO - Fila Cheia\n");
  }
}

int remocao(Fila *fl)
{
  if (fl->cont > 0)
  {
    int aux;
    aux = fl->fila[0];

    for (int i = 0; i < fl->cont - 1; i++)
    {
      fl->fila[i] = fl->fila[i + 1];
    }
    fl->cont--;
    return aux;
  }
  else
  {
    printf("Erro - Fila Vazia\n");
    return -1;
  }
}