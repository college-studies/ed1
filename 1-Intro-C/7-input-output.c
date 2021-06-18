#include <stdio.h>

int main()
{
  float f_grade, s_grade;
  float average;

  printf("First Grade: ");
  scanf("%f", &f_grade);

  printf("Second Grade: ");
  scanf("%f", &s_grade);

  average = (f_grade + s_grade) / 2;

  printf("Your Final grade is : %.2f\n", average);

  return 1;
}