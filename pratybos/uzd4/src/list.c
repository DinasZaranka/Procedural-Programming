#include "list.h"

void initList(List *l){
    l->head = NULL;
}

static Node* createNode(int value){
    Node *n = (Node*) malloc(sizeof(Node));
    if(!n){
        printf("ERROR: Memory allocation failed!");
        exit(1);
    }
    n->value = value;
    n->next = n;
    n->prev = n;
    return n;
}

void insertEnd(List *l, int value){
    Node *newNode = createNode(value);

    if(l->head == NULL){
        l->head = newNode;
        return;
    }

    Node *last = l->head->prev;

    newNode->next = l->head;
    newNode->prev = last;

    last->next = newNode;
    l->head->prev = newNode;
}