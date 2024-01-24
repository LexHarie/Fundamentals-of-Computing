#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// review of stdin, and scanf

int main()
{
  int x1, x2;
  float x3, x4;

  scanf("%d %d %f %f", &x1, &x2, &x3, &x4);

  printf("%d ", x1 + x2);
  printf("%d \n", x1 - x2);
  printf("%.1f ", x3 + x4);
  printf("%.1f", x3 - x4);

  return 0;
}