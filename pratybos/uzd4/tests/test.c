#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/functions.h"

int countElements(Node *head) {
    if (head == NULL) return 0;

    int count = 1;
    Node *current = head->next;

    while (current != head) {
        count++;
        current = current->next;
    }
    return count;
}

int listMatches(Node *head, int *arr, int len) {
    if (head == NULL && len == 0) return 1;
    if (head == NULL && len != 0) return 0;

    Node *current = head;

    for (int i = 0; i < len; i++) {
        if (current->value != arr[i]){
            return 0;
        }
        current = current->next;
    }

    if (current != head)
        return 0;

    return 1;
}

void test_insertEnd() {
    Node *head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 10);
    insertEnd(&head, 20);


    int correct[] = {5, 10, 20};
    assert(listMatches(head, correct, 3));

    deleteList(&head);
    assert(head == NULL);

    printf("[OK] insertEnd test passed\n");
}

void test_deleteMax() {
    Node *head = NULL;

    insertEnd(&head, 3);
    insertEnd(&head, 15);
    insertEnd(&head, 7);
    insertEnd(&head, 1);

    deleteMax(&head);

    int correct[] = {3, 7, 1};
    assert(listMatches(head, correct, 3));

    deleteList(&head);
    assert(head == NULL);

    printf("[OK] deleteMax test passed\n");
}

void test_deleteList() {
    Node *head = NULL;

    insertEnd(&head, 2);
    insertEnd(&head, 4);
    insertEnd(&head, 8);

    deleteList(&head);

    assert(head == NULL);

    printf("[OK] deleteList test passed\n");
}

int main(){
    test_insertEnd();
    printf("\n\n");
    test_deleteMax();
    printf("\n\n");
    test_deleteList();
    
    return 0;
}
