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
int Pop(struct Node **headRef);

int main()
{
  struct Node *myList = BuildOneTwoThree();

  int a = Pop(&myList);
  int b = Pop(&myList);
  int c = Pop(&myList);

  printf("%i", Length(myList));
}

/*

Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data.

*/
int Pop(struct Node **headRef)
{

  /*
  1. create a local head and assign *headRef
  2. create next node
  3. assign headRef with next node
  4. pull out the data before deallocating memory
  5. then free head
  6. return data
  */
  struct Node *head;
  head = *headRef;
  struct Node *next = head->next;
  int value = head->value;
  *headRef = next;
  free(head);

  return value;
}
/*

functions below are basic utility. start writing code above.

*/

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