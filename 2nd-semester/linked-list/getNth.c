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
int getNth(struct Node *head, int index);

int main()
{
  struct Node *myList = BuildOneTwoThree();

  printf("%i", getNth(myList, 1));
}

/*

Write a GetNth() function that takes a linked list and an integer index and returns the data
value stored in the node at that index position.

*/

int getNth(struct Node *head, int index)
{
  int count = 0;
  while (head != NULL)
  {
    if (count == index)
      return head->value;
    head = head->next;
    count++;
  }
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