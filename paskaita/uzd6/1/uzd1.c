#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Si programa atspausdina jusu ivesto skaicio faktoriala\n");
    printf("Iveskite viena teigiama skaiciu:\n");
    
    
    char str[20];
    char *endptr;
    long value;

    do{
        fgets(str,20,stdin);
        value = strtol(str, &endptr, 10);
        str[strcspn(str, "\n")] = '\0';
        if(endptr == str){
            printf("Jus nieko neivedete, bandykite dar karta\n");
            continue;
        } else if (*endptr != '\0'){
            printf("Jusu ivestis turejo raidziu,bandykite dar karta\n");
            continue;
        } else if (value < 0){
            printf("Jus ivedete neigiama skaiciu,bandykite dar karta\n");
            continue;
        } else {
            printf("Programa sekmingai nuskaite duomenis!\n");
            break;
        }
    } while (1);
    
    //calculating the factorial value of our number
    int factorial=1;
    for(int i=1; i<=value; i++){
        factorial = factorial * i;
    }

    printf("Jusu gautas rezultatas: %d\n",factorial);

    //failo apdorojimas
    FILE *myFile;

    myFile = fopen("out.txt", "w");
    if(myFile != NULL){
        fprintf(myFile, "Jusu skaiciaus faktorialas yra %d\n",factorial);
        fclose(myFile);
        printf("Programos rezultatus galima rasti faile out.txt\n");
    } else {
        printf("Nepavyko atidaryti failo!\n");
    }
    
    
    return 0;
}