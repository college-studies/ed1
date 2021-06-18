#include <stdio.h>

int main()
{
  int arr[5], i, value;

  //Initialize array;
  for (i = 0; i < 5; i++)
  {
    arr[i] = 0;
  }

  // Read values and store them in arr;
  for (i = 0; i < 5; i++)
  {
    printf("Input value at position %d = ", i);
    scanf("%d", &value);
    arr[i] = value;
  }

  //Show the stored array
  for (i = 0; i < 5; i++)
  {
    printf("[%d]", arr[i]);
  }
  printf("\n");
}