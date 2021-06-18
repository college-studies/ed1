#include <stdio.h>

float average(float f_grade, float s_grade)
{
  float average;
  average = (f_grade + s_grade) / 2;

  return average;
}

int main()
{
  float f_value, s_value, result;

  printf("First Grade = ");
  scanf("%f", &f_value);

  printf("Second Grade = ");
  scanf("%f", &s_value);

  result = average(f_value, s_value);

  printf("Final grade = %.2f\n", result);

  return 1;
}