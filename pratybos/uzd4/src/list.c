#include "list.h"

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
    if(*head == NULL) {
        printf("Sarasas jau tuscias!\n");
        return;
    }
    char userInput;
    while(1){
        printf("Ipsejimas! Sarase esantys duomenys bus istrinti. Testi? (y,n): ");
        scanf(" %c",&userInput);
        if(userInput == 'y'){
            deleteList(head);
            printf("Sekmingai sukurtas tuscias sarasas!\n");
            return;
        } else if(userInput == 'n'){
            printf("Procedura atsaukta!\n");
            return;
        } else{
            printf("Neteisinga ivestis, bandykite dar karta!\n");
            continue;
        }
    }
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

static void printRecursive(Node *start, Node *current, int userChoice, FILE *output){
    if(userChoice == 0){
        printf("%d \n", current->value);
    } else if(userChoice == 1){
        fprintf(output, "%d \n", current->value);
    }
    if(current->next == start){
        return;
    }

    printRecursive(start, current->next, userChoice, output);
}

void printList(Node *head){
    if(head == NULL){
        printf("Sarasas yra tuscias.\n");
        return;
    }

    int userChoice;
    printf("==============Spausdinimo meniu:==============\n");
    printf("0 - I komandine eilute\n");
    printf("1 - I faila\n");
    printf("==============================================\n");
    printf("Pasirinkite kur norite kad rezultatai butu atspusdini: ");
    
    while(1){
        scanf("%d",&userChoice);
        
        if(userChoice == 0){
            printf("Rezultatai: \n");
            printRecursive(head,head,userChoice,NULL);
            return;
        } else if(userChoice == 1){
            char *resultFile = calloc(256, sizeof(char));
            CheckOutputFileName(resultFile);

            FILE *output = fopen(resultFile, "w");
            if (!output){
                printf("Nepavyko atidaryti jusu rezultato failo!\n");
                continue;
            }
            
            printRecursive(head,head,userChoice,output); 
            fclose(output);
            printf("Rezultatu failas uzpildytas sekmingai!\n");
            return;       
        } else {
            printf("Jusu pasirinkimas netinka, bandykite dar karta : ");
            continue;
        }
    }
    
    printf("\n");
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

static void deleteRecursive(Node *start, Node *current){
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

    //confirmation message parasyti

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

void CheckOutputFileName(char *outputName){
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

void getFileData(Node **head){
    /*
    while(1){
        if(head != NULL){
        printf("===Jusu sarasas jau turi duomenis. Pasirinkite ka norite daryti:===");
        printf("0 - Nuskaityti duomenis is naujo, ir prideti prie esamu duomenu\n");
        printf("1 - Istrinti esama sarasa\n");
        printf("2 - Atsaukti procedura\n");
        printf("====================================================================\n");
        

        }
    }
    */

    FILE *input;
    char *dataFile = calloc(256, sizeof(char));
    checkDataFileName(dataFile);
    input = fopen(dataFile, "r");
    int n;
    while(fscanf(input, "%d", &n) == 1){
        insertEnd(head,n);
        n++;
    }
    printf("Sekmingai nuskaitytas duomenu failas!\n");
    
    free(dataFile);
    fclose(input);
}

