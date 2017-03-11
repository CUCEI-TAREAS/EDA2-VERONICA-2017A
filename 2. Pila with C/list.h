#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "node.h"

#define LIST_EMPTY      1
#define LIST_NOT_EMPTY  0

struct List {
    struct Node *first;
    short elements;
};

// List's methods
void list_init(struct List*);
short list_isEmpty(struct List*);
void list_insertNext_byValue(struct List*, DATA);
struct Node* list_getLatestPosition(struct List*);
struct Node* list_getByPosition(struct List*, short);
DATA list_deleteLatestElement(struct List*);
void list_copy(struct List*, struct List*);

// lifo methods
void lifo_push(struct List*, DATA);
void lifo_pop(struct List*);
DATA lifo_top(struct List*);


/// List's Definition
void list_init(struct List* list) {
    list->first = NULL;
    list->elements =  0;
}
short list_isEmpty(struct List *list) {
    if (list->first != NULL)
        return LIST_NOT_EMPTY;
    else
        return LIST_EMPTY;
}

void list_insertNext_byValue(struct List* list, DATA value) {

    if(list_isEmpty(list)) {
        list->first = malloc(sizeof(struct Node));
        node_init(list->first);
        list->first->data = value;
        list->elements = 1;
    } else {
        struct Node *aux = list->first;

        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = malloc(sizeof(struct Node));
        node_init(aux->next);
        aux->next->data = value;
        aux = NULL;
        free(aux);
        list->elements++;
    }
}

struct Node* list_getLatestPosition(struct List* list) {

    if(list_isEmpty(list))
        return NULL;

    struct Node *aux = list->first;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    return aux;
}

DATA list_deleteLatestElement(struct List *list) {

    if(list_isEmpty(list)) {
        return ;
    } else {

        struct Node *aux = list->first;
        struct Node *prev = list->first;
        //struct Node *prev = list->first;

        while (aux->next != NULL) {
            aux = aux->next;
        }

        /// sava data
        DATA x =  aux->data;

        /// to delete element
        if (aux != list->first ) { /// find previus pointer to aux
            while (prev->next != aux) {
                prev= prev->next;
            }
        } else { /// if is only the first element
            list_deleteFirst(list);
        }

        prev->next = NULL;
        aux = NULL;
        free(aux);
        return x;
    }
}

/// method is native for lists
void list_copy(struct List *source, struct List *destination) {

    if (list_isEmpty(source))
        return;

    /// to copy all list
    struct Node *auxSource = source->first;

    while (auxSource != NULL) {
        list_insertNext_byValue(destination, auxSource->data);
        auxSource = auxSource->next;
    }

    /// cleaning memory
    auxSource = NULL;
    free(auxSource);
}


/// lifo definitions
void lifo_push(struct List *list, DATA x) {
    // simple list method to add
    list_insertNext_byValue(list, x);
}

void lifo_pop(struct List *list) {
    // delete latest element
    list_deleteLatestElement(list);
}

DATA lifo_top(struct List *list) {
    // delete and return the latest element
    return list_deleteLatestElement(list);
}

/// PENDINGS TO REVISION
void list_deleteFirst(struct List *list) {
    if(!list_isEmpty(list)) {
        list->first = list->first->next;
        list->elements--;
    }
}

struct Node* list_getByPosition(struct List *list, short position) {
    if (list_isEmpty(list)) {
        printf(" LIST EMPTY  ");
        return;
    } else if ( position > list->elements ) {
        printf(" POSITION INVALID");
        return;
    }
}

void list_printAll(struct List *list) {
    struct Node *aux = malloc(sizeof(struct Node));
    aux = list->first;

    while (aux != NULL) {
        printf("\n %d", aux->data);
        aux = aux->next;
    }
    aux = NULL;
    free(aux);
}
#endif // LIST_H_INCLUDED
