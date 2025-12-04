#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Si programa atspausdina jusu ivestu skaiciu vidurini skaiciu(pagal reiksme)\n");
    printf("Prasau pateikite 3 skaicius, juos isskirkite kabliataskiais:\n");

    char line[100];
    FILE *myFile;
    char fileName[50];
    int validInput = 0;
    int validFile = 0;
    int a=0;
    int b=0;
    int c=0;
    int middle=0;
    while(1){
        fgets(line,100,stdin);
        line[strcspn(line, "\n")] = '\0';
        
        //program check if there are exactly three numbers
        char extra;
        int digitsCount = sscanf(line,"%d;%d;%d%c",&a,&b,&c,&extra);
        if(digitsCount > 3){
            printf("Jus ivedete per daug skaiciu/paskutinis skaitmuo neteisingai ivestas, bandykite dar karta! (programa praso 3 skaiciu):\n");
            continue;
        } else if (digitsCount == 1){
            printf("Jus padarete klaida ties antru skaiciu, bandykite dar karta! (programa praso 3 skaiciu):\n");
            continue;
        } else if(digitsCount == 2){
            printf("Jus padarete klaida ties treciu skaiciu, bandykite dar karta! (programa praso 3 skaiciu):\n");
            continue;
        } else if(digitsCount == 0){
            printf("Klaida ties pirmu skaiciu, bandykite dar karta! (programa praso 3 skaiciu):\n");
            continue;
        } else {
            printf("Duomenys nuskaityti teisingai!\n");
            validInput=1;
        }

        //file name check
        printf("Prasau iveskite failo pavadinima, i kuri norite kad rezultatai butu spausdinami (failo pavadinimas privalo baigtis .txt):\n");
        while(1){
            fgets(fileName,50,stdin);
            fileName[strcspn(fileName, "\n")] = '\0';
            if(strlen(fileName) < 4 || strcmp(fileName + strlen(fileName) - 4,".txt") != 0){
            printf("Jusu failo pavadinimas nesibaigia su .txt, iveskite kita\n");
            continue;
            } else {
                validFile=1;
                break;
            }
        }
        break;
    }

    //finding middle number
    if(validFile == 1 && validInput == 1){
        if((a >= b && a <= c) || (a <= b && a >= c)){
            middle=a;
        } else if((b >= a && b <= c) || (b <= a && b >= c)){
            middle=b;
        } else {
            middle=c;
        }
    }

    if(validFile == 1 && validInput == 1){
        printf("Jusu programos rezultatus galite surasi faile %s\n",fileName);
        myFile = fopen(fileName,"w");
        if(myFile != NULL){
            fprintf(myFile, "Rezultatas(jusu ivestu skaiciu vidurinis skaitmuo):\n%d",middle);
            fclose(myFile);
        } else {
            printf("Programa negalejo atidaryt failo\n");
        }
    }

    return 0;
}