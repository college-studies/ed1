#include <stdio.h>

#define PROFIT 10.0

int main()
{
  float price, sellPrice;

  printf("Buy Price = $ ");
  scanf("%f", &price);

  sellPrice = price + (price * PROFIT / 100);

  printf("Sell Price = $ %.2f\n", sellPrice);
}