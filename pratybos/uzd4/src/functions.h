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

void checkDataFileName(char *inputName);

void checkOutputFileName(char *outputName);

void createEmptyList(Node **head);

void insertEnd(Node **head, int value);

void getFileData(Node **head);

void printRecursive(Node *start, Node *current);

void printRecursiveToFile(Node *start, Node *current, FILE *output);

void printToFile(Node *head);

void deleteMax(Node **head);

void deleteRecursive(Node *start, Node *current);

void deleteList(Node **head);

#endif