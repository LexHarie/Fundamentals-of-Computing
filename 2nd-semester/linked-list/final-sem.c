/**************************************************************************
 * The following program illustrates display and delete operations in a   *
 * List implemented using an array representation.                        *
 *                                                                        *
 *  What to Do:                                                           *
 *  a)  Complete function displayProdList()                               *
 *  b)  Write the code for function deleteElem()                          *
 *  c)  Answer Problem #2 a, b, c in main() function.                     *
 *                                                                        *
 *  Submission File: Prob_02_lastnameXX.c  //XX is the 1st 2 letters of   *
 *                                         // your firstname              *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct
{
  char name[24]; // Chocolate name
  int weight;    // Chocolate weight in grams
} chocoDesc;

typedef struct
{
  char prodID[8];     //  product ID uniquely identifies the products;
  chocoDesc prodDesc; //  product description
  float prodPrice;    //  product price
  int prodQty;        //  product count or quantity
} product;            //  product record

// Linked List Implementations of List
typedef struct pnode
{
  product prod;
  struct pnode *plink;
} *ProdList; // Linked List implementation

/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
ProdList populateProdList(); // Complete Code Given. Populate the list implemented using linked list.

void displayHeader();                    // Display the fields of the records such as  not the data
void displayProdList(ProdList L);        // For each chocolate record of the list, this displays the ID, choco name and weight.
void deleteElem(ProdList *L, char ID[]); // The function will delete the first occurrence of the record bearing the given ID.
                                         // Succeeding elements should be moved 1 index lower.

/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/
int main()
{

  /*----------------------------------------------------------------------------------
   * 	Problem #2 :: a) Populates the list by calling populateList()                   *
   *                b) Displays the product list by calling displayProdList().        *
   *                c) Input from the keyboard an ID number, then call                *
   *                   deleteElem() and displayProdList()                             *
   *----------------------------------------------------------------------------------*/

  printf("\n\n\nProblem #1:: ");
  printf("\n------------");

  // Write your code below
  //  Problem #2 a)

  // Problem #2 b)

  // Problem #2 c)
  printf("\nEnter ID : ");

  return 0;
}

/************************************************************
 *  Problem1   :: Function Definitions                          *
 ************************************************************/
ProdList populateProdList()
{
  int count; // No. of chocolate records in data
  product data[] = {
      {"1701", {"Toblerone", 135}, 150.75, 20},
      {"1356", {"Ferrero", 200}, 250.75, 85},
      {"1109", {"Patchi", 50}, 99.75, 35},
      {"1550", {"Cadbury", 120}, 200.00, 30},
      {"1807", {"Mars", 100}, 150.75, 20},
      {"1201", {"Kitkat", 50}, 97.75, 40},
      {"1170", {"Meiji", 75}, 75.50, 60},
      {"1310", {"Nestle", 100}, 124.50, 70},
      {"1807", {"Valor", 120}, 149.50, 90},
      {"1455", {"Tango", 75}, 49.50, 100},
      {"1703", {"Toblerone", 100}, 125.75, 60},
      {"1689", {"Lindt", 100}, 250.75, 15},
      {"1688", {"Guylian", 50}, 99.75, 35},
  };
  count = sizeof(data) / sizeof(data[0]);
  int x;
  ProdList temp, L = NULL, *ptr = &L;
  for (x = 0; x < count; x++)
  {
    temp = (ProdList)malloc(sizeof(struct pnode));
    if (temp != NULL)
    {
      temp->prod = data[x];
      temp->plink = NULL;
      *ptr = temp;
      ptr = &temp->plink;
    }
  }
  return L;
}

void displayHeader()
{
  printf("\n\n%-7s", "ID");
  printf("%-12s", "Choco Name");
  printf("%-15s", "Choco Weight");
  printf("\n%-7s%-12s%-15s", "--", "----------", "------------");
}

void displayProdList(ProdList L)
{
  printf("\n\nDetails of the List :: ");
  printf("\n---------------------");
  displayHeader();

  // Write your code here. Hint: Traverse the list and for each record display the ID, choco name and weight

  // You may use this as part of your code, just complete the statement, then uncomment
  //	printf("\n%-7s",   );         //Complete this to display the ID of a choco record
  //	printf("%-12s", );            //Complete this to display the name of a choco record
  //	printf("%-15d", );            // Complete this to dispaly the weight of a choco record

  // printf("\n\nNo. of elements :: %d",    );   //Complete this line and uncomment
  printf("\n\n");
  system("Pause"); // Leave this line
}

void deleteElem(ProdList *L, char ID[])
{
  // Write your code here
}
