#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){

	struct List *myList;
	myList = malloc(sizeof(struct List));

	list_init(myList);
	list_insertNext_byValue(myList, 10);
	list_insertNext_byValue(myList, 11);
	list_insertNext_byValue(myList, 15);
	list_insertNext_byValue(myList, 20);

	list_printAll(myList);
	list_deleteFirst(myList);
	list_printAll(myList);

    return 0;
}
