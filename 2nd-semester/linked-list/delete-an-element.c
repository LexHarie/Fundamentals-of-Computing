#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
  int data;
  struct Node *next;
};

// Function to delete a node from the linked list
void deleteNode(struct Node **head_ref, int key)
{
  // Store head node
  struct Node *temp = *head_ref;
  struct Node *prev = NULL;

  // If head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next; // Change head
    free(temp);             // Free old head
    return;
  }

  // Search for the key to be deleted, keep track of the previous node as well
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  // If key was not present in the linked list
  if (temp == NULL)
    return;

  // Unlink the node from linked list
  prev->next = temp->next;

  // Free memory
  free(temp);
}

// Function to print the linked list
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Driver program
int main()
{
  struct Node *head = NULL;

  // Create a linked list: 3->2->1->4->5
  push(&head, 5);
  push(&head, 4);
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);

  printf("Linked list before deletion: ");
  printList(head);

  deleteNode(&head, 1); // Delete node with value 1

  printf("Linked list after deletion: ");
  printList(head);

  return 0;
}
