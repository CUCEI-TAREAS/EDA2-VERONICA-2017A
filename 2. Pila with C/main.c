#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/// Felipe de Jesus Ruiz Garcia
/// en esta actividad estoy reutilizando la lista para usarla con metodos de la pila

int main(){

	struct List *myPila, *myPilaParaCopiar;

	myPila = malloc(sizeof(struct List));
	myPilaParaCopiar = malloc(sizeof(struct List));

	list_init(myPila);
	list_init(myPilaParaCopiar);

    lifo_push(myPila, 1);
    lifo_push(myPila, 2);
    lifo_push(myPila, 3);
    lifo_push(myPila, 4);

    list_copy(myPila, myPilaParaCopiar);

    lifo_pop(myPila);
    lifo_pop(myPila);


	list_printAll(myPila);
	list_printAll(myPilaParaCopiar);

    return 0;
}
