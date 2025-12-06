#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

void createEmptyList(Node **head);

void insertEnd(Node **head, int value);

void printList(Node *head);

void deleteMax(Node **head);

void deleteList(Node **head);

void checkDataFileName(char *inputName);

void CheckOutputFileName(char *outputName);

void getFileData(Node **head);



#endif