#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include "node.h"

#define LIST_EMPTY      1
#define LIST_NOT_EMPTY  0

struct List {
	struct Node *first;
};

// List's methods
void list_init(struct List*);
short list_isEmpty(struct List*);
void list_insertNext_byValue(struct List*, DATA);

// List's Definition
void list_init(struct List* list){
	list->first = NULL;
}
short list_isEmpty(struct List *list){
    if (list->first != NULL)
        return LIST_NOT_EMPTY;
    else
        return LIST_EMPTY;
}

void list_insertNext_byValue(struct List* list, DATA value){

	if(list_isEmpty(list)){
		list->first = malloc(sizeof(struct Node));
		node_init(list->first);
		list->first->data = value;
	}
	else {
        struct Node *aux = list->first;

        while (aux->next != NULL){
            aux = aux->next;
        }

        aux->next = malloc(sizeof(struct Node));
        node_init(aux->next);
        aux->next->data = value;
        aux = NULL;
        free(aux);
	}
}

void list_deleteFirst(struct List *list){
    if(list->first != NULL ){
        //struct Node *aux = malloc(sizeof(struct Node));
        list->first = list->first->next;
    }
}

void list_printByPosition(struct List *list, int position){

}
void list_printAll(struct List *list){
        struct Node *aux = malloc(sizeof(struct Node));
        aux = list->first;

        while (aux != NULL){
            printf("\n %d", aux->data);
            aux = aux->next;
        }
        aux = NULL;
        free(aux);
}
#endif // LIST_H_INCLUDED
