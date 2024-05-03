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
void SortedInsert(struct Node **headRef, struct Node *newNode);
void SortedInsert2(struct Node **headRef, struct Node *newNode);
void SortedInsert3(struct Node **headRef, struct Node *newNode);

int main()
{
  struct Node *myList = BuildOneTwoThree();
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->value = 2;
  newNode->next = NULL;
  show(myList);

  SortedInsert(&myList, newNode);
  printf("New List: \n");
  show(myList);
}

/*

Write a SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. There are many possible solutions to this
problem.

*/

void SortedInsert(struct Node **headRef, struct Node *newNode)
{
  // Special case for the head end
  if (*headRef == NULL || (*headRef)->value >= newNode->value)
  {
    newNode->next = *headRef;
    *headRef = newNode;
  }
  else
  {
    // Locate the node before the point of insertion
    struct Node *current = *headRef;
    while (current->next != NULL && current->next->value < newNode->value)
    {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

// Dummy node strategy for the head end
void SortedInsert2(struct Node **headRef, struct Node *newNode)
{
  struct Node dummy;
  struct Node *current = &dummy;
  dummy.next = *headRef;
  while (current->next != NULL && current->next->value < newNode->value)
  {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
  *headRef = dummy.next;
}

void SortedInsert3(struct Node **headRef, struct Node *newNode)
{
  struct Node **currentRef = headRef;
  while (*currentRef != NULL && (*currentRef)->value < newNode->value)
  {
    currentRef = &((*currentRef)->next);
  }
  newNode->next = *currentRef; // Bug: this line used to have
  // an incorrect (*currRef)->next
  *currentRef = newNode;
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

void Push(struct Node **headRef, int newvalue)
{
  struct Node *newNode =
      (struct Node *)malloc(sizeof(struct Node)); // allocate node
  newNode->value = newvalue;                      // put in the value
  newNode->next = (*headRef);                     // link the old list off the new node
  (*headRef) = newNode;                           // move the head to point to the new node
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