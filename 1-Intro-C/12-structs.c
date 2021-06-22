#include <stdio.h>

struct ponto
{
  int x;
  int y;
};

typedef struct ponto tipo_ponto;

struct linha
{
  tipo_ponto p1;
  tipo_ponto p2;
};

typedef struct linha tipo_linha;

//prototype
tipo_ponto somaPontos(tipo_ponto a, tipo_ponto b);

int main()
{
  tipo_ponto p1, p2, p_novo;
  tipo_linha linha1;
  p1.x = 2;
  p1.y = 3;
  p2.x = 4;
  p2.y = 5;

  printf("Ponto 1 = (%d, %d)\n", p1.x, p1.y);
  printf("Ponto 2 = (%d, %d)\n", p2.x, p2.y);

  p_novo = somaPontos(p1, p2);
  printf("Ponto Novo = (%d, %d)\n", p_novo.x, p_novo.y);

  linha1.p1 = p1;
  linha1.p2 = p_novo;

  printf("Linha: [(%d, %d), (%d, %d)]\n", linha1.p1.x, linha1.p1.y, linha1.p2.x, linha1.p2.y);

  return 1;
}

tipo_ponto somaPontos(tipo_ponto a, tipo_ponto b)
{
  tipo_ponto total;
  total.x = a.x + b.x;
  total.y = a.y + b.y;

  return total;
}