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
void Push(struct Node **headRef, int newvalue);
void show(struct Node *headRef);
void RecursiveReverse(struct Node **headRef);

int main()
{
  struct Node *myList = BuildOneTwoThree();
  Push(&myList, 8);
  Push(&myList, 10);
  show(myList);

  RecursiveReverse(&myList);
  printf("New List: \n");
  show(myList);
}

/*

Write an InsertSort() function which given a list, rearranges its Nodes so they are sorted in
increasing order. It should use SortedInsert().

*/

void RecursiveReverse(struct Node **headRef)
{
  struct Node *first;
  struct Node *rest;
  if (*headRef == NULL)
    return;           // empty list base case
  first = *headRef;   // suppose first = {1, 2, 3}
  rest = first->next; // rest = {2, 3}
  if (rest == NULL)
    return;                // empty rest base case
  RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3} case
  // after: rest = {3, 2}
  first->next->next = first; // put the first elem on the end of the list
  first->next = NULL;        // (tricky step -- make a drawing)
  *headRef = rest;           // fix the head pointer
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
// of a list and an int, push a new Node on the front of the list.
// Creates a new Node with the int, links the list off the .next of the
// new Node, and finally changes the head to point to the new Node.

void Push(struct Node **headRef, int newvalue)
{
  struct Node *newNode =
      (struct Node *)malloc(sizeof(struct Node)); // allocate Node
  newNode->value = newvalue;                      // put in the value
  newNode->next = (*headRef);                     // link the old list off the new Node
  (*headRef) = newNode;                           // move the head to point to the new Node
}

struct Node *BuildOneTwoThree()
{
  struct Node *head = NULL; // Start with the empty list
  Push(&head, 3);           // Use Push() to add all the value
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