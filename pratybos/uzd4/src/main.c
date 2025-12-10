//LSP:2513680, dinas.zaranka@mif.stud.vu.lt 4 uzd 8 variantas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

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
    if(scanf("%d",&userChoice) != 1){
        printf("Klaida! Turite ivesti skaiciu, bandykite dar karta: ");
        while(getchar() != '\n');
        continue;
    };
    

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
    char extraInput;
    
    while(1){
        userChoice = userMenu();
        
        switch (userChoice) {
        case 0:
            if(head == NULL) {
                printf("Sekmingai sukurtas naujas tuscias sarasas!\n");
                break;
            }
            
            while(1){
                printf("Sarasas jau egzistuoja, ar norite ji perkurti i tuscia? (y,n): ");
                scanf(" %c",&extraInput);
                if(extraInput == 'y'){
                    createEmptyList(&head);
                    break;
                } else if(extraInput == 'n'){
                    printf("Procedura atsaukta!\n");
                    break;
                } else{
                    printf("Neteisinga ivestis, bandykite dar karta!\n");
                    continue;
                }   
            }
            
            break;
        case 1:
            if(head != NULL){
                while(1){
                    printf("===Jusu sarasas jau turi duomenis. Pasirinkite ka norite daryti:===\n");
                    printf("0 - Nuskaityti duomenis is naujo, ir prideti prie esamu duomenu\n");
                    printf("1 - Istrinti esama sarasa, ir naujus duomenis\n");
                    printf("2 - Atsaukti procedura\n");
                    printf("===================================================================\n");
                    printf("Pasirinkite ka norite kad programa darytu: ");

                    scanf(" %c",&extraInput);
                    
                    if(extraInput == '0'){
                        getFileData(&head);
                        break;
                    } else if(extraInput == '1'){
                        deleteList(&head);
                        getFileData(&head);
                        break;
                    } else if(extraInput == '2'){
                        printf("Procedura atsaukta!\n");
                        break;
                    } else {
                        printf("Neteisinga ivestis, bandykite dar karta!\n");
                        continue;
                        }
                    }
                } else{
                    getFileData(&head);
                }

            break;
        case 2:
            if(head == NULL){
                printf("Sarasas yra tuscias.\n");
                break;
            }
            
            printf("==============Spausdinimo meniu:==============\n");
            printf("0 - I komandine eilute\n");
            printf("1 - I faila\n");
            printf("==============================================\n");
            printf("Pasirinkite kur norite kad rezultatai butu atspusdini: ");
            
            while(1){
                scanf(" %c",&extraInput);
                
                if(extraInput == '0'){
                    printf("Rezultatai: \n");
                    printRecursive(head,head);
                    break;
                } else if (extraInput == '1'){
                    printToFile(head);
                    break;
                } 
                else {
                    printf("Jusu pasirinkimas netinka, bandykite dar karta : ");
                    continue;
                }
            }
            
            break;
        case 3:
            deleteMax(&head);
            break;
        case 4:
            printf("Ar tikrai norite istrinti visa sarasa? (y,n): ");
            
            while(1){
                scanf(" %c",&extraInput);
                if(extraInput == 'y'){
                    deleteList(&head);
                    break;
                } else if(extraInput == 'n'){
                    printf("Procedura atsauka!\n");
                    break;
                } else{
                    printf("Jusu pasirinkimas netinka, bandykite dar karta : ");
                    continue;
                }
            }
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}