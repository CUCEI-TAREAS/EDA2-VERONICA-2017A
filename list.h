#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>

// simulate templates
#define DATA int

struct Node {
	struct Node *next, *prev;
	DATA data;
};

struct List {
	struct Node *first;
};

// Node's methods
void node_init(struct Node *e){
	e->next = NULL;
	e->prev = NULL;
}

/*
void node_setNext(struct Node *e, struct Node *f){
	e->next = f;
}

void node_setPrev(struct Node *e, struct Node *f){
	e->prev = f;
}

struct Node* node_getNext(struct Node* e){
	return e->next;
}

struct Node* node_getPrev(struct Node* e){
	return e->prev;
}

*/

// List's methods
void list_init(struct List* list){
	list->first = NULL;
}

void list_insertNext_byValue(struct List* list, DATA value){

	if(list->first == NULL ){
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
short list_isEmpty(struct List *list){

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
