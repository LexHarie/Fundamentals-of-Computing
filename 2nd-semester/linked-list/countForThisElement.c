#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

int count(struct Node *head, int searchFor);

int main()
{
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));

  struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
  node1->value = 7;
  head->next = node1;

  struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
  node2->value = 7;
  node1->next = node2;

  struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
  node3->value = 7;
  node2->next = node3;

  struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));
  node4->value = 7;
  node3->next = node4;

  struct Node *node5 = (struct Node *)malloc(sizeof(struct Node));
  node5->value = 7;
  node4->next = node5;

  node5->next = NULL;

  int countFor = count(head, 7);

  printf("%i", countFor);
}

// Write a Count() function that counts the number of times a given int occurs in a list. The
// code for this has the classic list traversal structure as demonstrated in Length()

int count(struct Node *head, int searchFor)
{
  int count = 0;

  while (head != NULL)
  {
    if (head->value == searchFor)
      count++;
    head = head->next;
  }
  return count;
}