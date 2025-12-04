#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Si programa atspausdina jusu ivesto realiojo skaiciaus ilgi\n");
    printf("Duomenu faile in.txt pateikite toki realuji skaiciu, kuris priklauso intervalui [10;1000], ir neturi daugiau kaip 3 skaicius po kablelio\n");

    char str[20];
    char *endptr;
    float value;

    FILE *myFile;
    char fileName[50] = "in.txt";
    int valid = 0;
    while(valid==0){
        myFile = fopen(fileName, "r");
        if(myFile != NULL){
            //file initialization
            fgets(str,20,myFile);
            str[strcspn(str,"\n")] = '\0';
            //changing comma to dot for further calculations
            char *comma = strchr(str, ',');
            if(comma != NULL){
                *comma='.';
            }
            value = strtof(str,&endptr);
            
            //checking number validity
            if(endptr == str){
                printf("Pateiktas failas yra tuscias\n");
            } else if (*endptr != '\0'){
                printf("Jusu ivestis turejo raidziu,bandykite dar karta\n");
            } else if(value<10){
                printf("Jusu skaicius yra per mazas\n");
            } else if(value>1000){
                printf("Jusu skaicius yra per didelis\n");
            } else if(comma != NULL && strlen(comma+1)>3){
                printf("Jusu skaicius turi daugiau neigu 3 skaicius po kablelio\n");
            } else {
                printf("Duomenys teisingai ivesti!\n");
                valid=1;
            }
            
            if(valid == 0){
                printf("Prasau iveskite naujo failo (su teisingu skaiciu) pavadinima:\n");
                scanf("%49s", fileName);
            }
                
            
            fclose(myFile);
        } else {
            printf("Programa nesugebejo atidaryti failo\n");
            printf("Prasau iveskite naujo failo (su teisingu skaiciu) pavadinima:\n");
            scanf("%s", fileName);
            continue;
        }

    }

    if(valid==1){
        printf("Spausdinami rezultatai:\n");
        printf("Skaiciaus ilgis: %lu", strlen(str));
    }

    return 0;
}