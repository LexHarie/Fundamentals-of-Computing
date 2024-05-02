#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ORDEREDLL.H"

//open project file when using devc

void main(){
	LIST head;
	init(&head);
	
	insertSorted(&head, "Xerxes");
	insertSorted(&head, "Nikko");
	insertSorted(&head, "Angelou");
	insertSorted(&head, "Julie Christy");
	insertSorted(&head, "Nichole Vhine");
	insertSorted(&head, "Gerund Red");
	insertSorted(&head, "Sareljohn");
	insertSorted(&head, "asdf");
	show(head);
	printf("\n");
	del(&head, "asdf");
	show(head);
	printf("\n");
	edit(&head, "Angelou", "Angelou Sereno");
	show(head);
}
