#include <stdio.h>
#include "function.printing-and-asking.h"
#include "function.recursion.h"

#define MAX_NUMBERS 10
#define EVEN_NUMBERS 4

int main()
{
  int numbers[MAX_NUMBERS] = {14, 6, 8, 22, 33, 11, 60};
  int even[EVEN_NUMBERS];
  int count = 0;
  int i = 0;

  recursivePrinting(numbers, MAX_NUMBERS, i);

  return 0;
}