#include <stdio.h>

int main()
{
  int matrice[3][4], row, column;

  // Initialize matrice;
  for (row = 0; row < 3; row++)
  {
    for (column = 0; column < 4; column++)
    {
      matrice[row][column] = 0;
    }
  }

  // Set values for the matrice;
  for (row = 0; row < 3; row++)
  {
    for (column = 0; column < 4; column++)
    {
      printf("Input value at position [%d] [%d] = ", row, column);
      scanf("%d", &matrice[row][column]);
    }
  }

  // Show matrice values;
  for (row = 0; row < 3; row++)
  {
    for (column = 0; column < 4; column++)
    {
      printf("[%d][%d] = [%d]\n", row, column, matrice[row][column]);
    }
  }
}
