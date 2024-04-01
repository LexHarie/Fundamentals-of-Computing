#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
void printThis(struct node *trav)
{
  while (trav->next != NULL)
  {
    trav = trav->next;
    printf("%i\n", trav->data);
  }
}
void insertAtTheEnd(struct node *trav, int newData)
{
  // 1.  create the new node and populate it
  // 2.  connect the head to the new node if the the list is empty
  // 3.  if list is not empty, traverse to the end
  // 4.  connect the end to the new node
  struct node *tempNode = (struct node *)malloc(sizeof(struct node));

  tempNode->data = newData;
  tempNode->next = NULL;
  if (trav->next == NULL)
  {
    trav->next = tempNode;
  }
  else
  {
    for (; trav->next != NULL; trav = trav->next)
    {
    }
    trav->next = tempNode;
  }
}

void insertAfter(struct node *trav, int newData)
{
  struct node *temp = trav;
  if (trav->next == NULL)
  {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    trav->next = new;
    trav->data = newData;
    new->next = NULL;
    return;
  }

  while (trav->next != NULL)
    trav = trav->next;
  struct node *new = (struct node *)malloc(sizeof(struct node));
  trav->next = new;
  trav->data = newData;
  new->next = NULL;
}
void insertAtStart(struct node *trav, int newData)
{
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->next = trav->next;
  new->data = newData;
  trav->next = new;
}
void insertSorted(struct node *trav, int newData)
{
  struct node *tempNode = (struct node *)malloc(sizeof(struct node));
  tempNode->data = newData;
  tempNode->next = NULL;

  for (; trav->next != NULL && (newData > (trav->next)->data); trav = trav->next)
  {
  }
  tempNode->next = trav->next;
  trav->next = tempNode;
}
int main()
{
  struct node *head = (struct node *)malloc(sizeof(struct node));

  insertSorted(head, 1231);
  insertSorted(head, 321);
  insertSorted(head, 21);
  insertSorted(head, 121);

  printThis(head);

  return 0;
}