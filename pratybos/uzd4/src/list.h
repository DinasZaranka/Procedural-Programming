#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Ciklinio dvipusio saraso mazgo struktura
typedef struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

//Laiko rodykle i saraso pradzia
typedef struct{
    Node *head;
} List;

void initList(List *l);

void insertEnd(List *l, int value);

//saraso spausdinimas rekursyvus
void printList(const List *l);

void deleteMax(List *l);

void deleteList(List *l);

void readFromFile(List *l, const char *fileName);



#endif