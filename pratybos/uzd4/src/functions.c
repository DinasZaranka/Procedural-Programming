#include "functions.h"

void checkDataFileName(char *inputName){
    FILE *test;
    
    printf("Prasau iveskite failo pavadinima:\n");
    
    while(1){
        scanf("%s",inputName);
        test = fopen(inputName, "r");
        if(test != NULL){
            fclose(test);
            break;
        }
        printf("Jusu ivestas failas neegzistuoja, bandykite dar karta!\n");
    }
}

void checkOutputFileName(char *outputName){
    FILE *test;
    
    printf("Prasau iveskite failo pavadinima:\n");
    
    while(1){
        scanf("%s",outputName);
        
        test = fopen(outputName, "w");
        if(test != NULL){
            fclose(test);
            break;
        }
        
        printf("Jusu rezultato failo programa nesugebejo sukurti,bandykite dar karta\n");
    }
}

struct Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if(!newNode){
        printf("Programa nesugebejo priskirti atminties!\n");
        exit(1);
    }
    
    newNode->value = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    
    return newNode;
}

void createEmptyList(Node **head){
    deleteList(head);
    
    *head = NULL;
    
    printf("Sekmingai sukurtas tuscias sarasas!\n");
    
    return;
}

void insertEnd(Node **head, int value){
    Node *newNode = createNode(value);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node *last = (*head)->prev;

    newNode->next = (*head);
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;
}

void getFileData(Node **head){
    FILE *input;
    char *dataFile = calloc(256, sizeof(char));
    checkDataFileName(dataFile);
    input = fopen(dataFile, "r");
    
    int n;
    while(fscanf(input, "%d", &n) == 1){
        insertEnd(head,n);
    }
    printf("Sekmingai nuskaitytas duomenu failas!\n");
    
    free(dataFile);
    fclose(input);
}

void printRecursive(Node *start, Node *current){
    printf("%d \n", current->value);
    
    if(current->next == start){
        return;
    }

    printRecursive(start, current->next);
}

void printRecursiveToFile(Node *start, Node *current, FILE *output){
    fprintf(output, "%d \n", current->value);
    
    if(current->next == start){
        return;
    }

    printRecursiveToFile(start, current->next, output);
}

void printToFile(Node *head){
    char *resultFile = calloc(256, sizeof(char));
    checkOutputFileName(resultFile);

    FILE *output = fopen(resultFile, "w");
    if (!output){
        printf("Nepavyko atidaryti jusu rezultato failo!\n");
    }
            
    printRecursiveToFile(head,head,output); 
    
    fclose(output);
    printf("Rezultatu failas uzpildytas sekmingai!\n");
    free(resultFile);
    
    return;
}

void deleteMax(Node **head){
    if(*head == NULL){
        printf("Sarasas yra tuscias.\n");
        return;
    }

    if((*head)->next == *head){
        printf("Pasalintas vienintelis saraso elementas: %d\n", (*head)->value);
        free(*head);
        *head = NULL; 
        return;
    }

    Node *current = *head;
    Node *largest = current;

    while(current->next != *head){
        current = current->next;
        if(current->value > largest->value){
            largest = current;
        }
    }

    if(largest == *head){
        *head = (*head)->next;
    }

    printf("Pasalintas elementas: %d\n", largest->value);

    largest->prev->next = largest->next;
    largest->next->prev = largest->prev;
    
    free(largest);
}

void deleteRecursive(Node *start, Node *current){
    Node *nextNode = current->next;

    if(nextNode == start){
        free(current);
        return;
    }

    deleteRecursive(start,nextNode);

    free(current);
}

void deleteList(Node **head){
    if(*head == NULL){
        printf("Sarasas jau yra tuscias!\n");
        return;
    }

    Node *start = *head;

    if(start->next == start){
        free(start);
        *head = NULL;
        printf("Sarasas sekmingai istrintas!\n");
        return;
    }

    deleteRecursive(start,start->next);
    free(start);
    *head = NULL;
    
    printf("Sarasas sekmingai istrintas!\n");
}

