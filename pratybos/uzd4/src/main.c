//LSP:2513680, dinas.zaranka@mif.stud.vu.lt 4 uzd 8 variantas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int userMenu(){
    int userChoice;
    printf("===============Programos meniu:===============\n");
    printf("0 - Sukuria tuscia sarasa\n");
    printf("1 - nuskaito duomenis is jusu nurodyto failo\n");
    printf("2 - spausdina sarasa\n");
    printf("3 - Ismeta is saraso didziausia elementa\n");
    printf("4 - istrina visa sarasa\n");
    printf("5 - iseina is programos\n");
    printf("==============================================\n");
    printf("Iveskite ka norite kad programa darytu: ");
    while(1){
    scanf("%d",&userChoice);
    
    if(userChoice < 0 || userChoice > 5){
        printf("Jusu pasirinkimas netinka, bandykite dar karta : ");
        continue;
    }
    return userChoice;
    }
}

int main(){
    Node *head=NULL;
    int userChoice;
    while(1){
        userChoice = userMenu();
        if(userChoice == 0){
            createEmptyList(&head);
        }
        
        if(userChoice == 1) {
            getFileData(&head);
        }
        if(userChoice == 2) {
            printList(head);
        }
        if(userChoice == 3){
            deleteMax(&head);
        }
        if(userChoice == 4){
            deleteList(&head);
        }
        if(userChoice == 5) break;
    }
    

    return 0;
}