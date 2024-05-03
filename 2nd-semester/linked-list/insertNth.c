#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

int count(struct Node *head, int searchFor);
struct Node *BuildOneTwoThree();
int Length(struct Node *head);
void Push(struct Node **headRef, int newData);
void insertNth(struct Node **headRef, int index, int data);
void show(struct Node *headRef);

int main()
{
  struct Node *myList = NULL;

  insertNth(&myList, 0, 13);
  insertNth(&myList, 1, 42);
  insertNth(&myList, 1, 5);

  show(myList);
}

/*

Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data.

*/

void insertNth(struct Node **headRef, int index, int data)
{
  if (index == 0)
  {
    // Special case for inserting at the beginning
    Push(headRef, data);
    return;
  }

  struct Node *current = *headRef;
  for (int i = 0; i < index - 1; i++)
  {
    if (current == NULL)
    {
      printf("Invalid index\n");
      return;
    }
    current = current->next;
  }
  if (current == NULL)
  {
    printf("Invalid index\n");
    return;
  }
  Push(&(current->next), data);
}

/*

functions below are basic utility. start writing code above.

*/

void show(struct Node *headRef)
{
  while (headRef != NULL)
  {
    printf("%d\n", headRef->value);
    headRef = headRef->next;
  }
}

// Given a reference (pointer to pointer) to the head
// of a list and an int, push a new node on the front of the list.
// Creates a new node with the int, links the list off the .next of the
// new node, and finally changes the head to point to the new node.

void Push(struct Node **headRef, int newData)
{
  struct Node *newNode =
      (struct Node *)malloc(sizeof(struct Node)); // allocate node
  newNode->value = newData;                       // put in the data
  newNode->next = (*headRef);                     // link the old list off the new node
  (*headRef) = newNode;                           // move the head to point to the new node
}

struct Node *BuildOneTwoThree()
{
  struct Node *head = NULL; // Start with the empty list
  Push(&head, 3);           // Use Push() to add all the data
  Push(&head, 2);
  Push(&head, 1);
  return (head);
}

int Length(struct Node *head)
{
  int count = 0;
  struct Node *current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return (count);
}