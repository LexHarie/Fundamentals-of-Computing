#include <stdio.h>
#include <string.h>

// how to print a sentence in C with scanf

int main()
{
  char ch;
  scanf(" %c", &ch); // to note the space before %c to consume the newline
  printf("%c\n", ch);

  char s[100];
  scanf("%s", s);
  printf("%s\n", s);

  char sen[10000];
  getchar(); // Consume the newline character left in the buffer
  // it will still work without the getchar
  fgets(sen, sizeof(sen), stdin);
  printf("%s", sen);
  return 0;
}