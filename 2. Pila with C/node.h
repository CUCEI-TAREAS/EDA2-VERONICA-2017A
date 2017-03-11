#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

// simulate templates
#define DATA int

struct Node {
	struct Node *next, *prev;
	DATA data;
};

// Node's methods
void node_init(struct Node *e){
	e->next = NULL;
	e->prev = NULL;
}



#endif // NODE_H_INCLUDED
