#include <stdio.h>

int main(){
    printf("Si programa atspausdina jusu ivestos datos savaites diena\n");

    int year,month,day;
    char ch;
    int invalid;
    //data input and validation
    while (1){
        invalid = 0;
        printf("Prasau iveskite data formatu YYYY-MM-DD:\n");

        if(scanf("%4d-%2d-%2d%c",&year,&month,&day,&ch) == 4 && ch=='\n'){
            int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if(year < 1900 || year > 2100){
                printf("Jus pateikete netinkamus metus, bandykite dar karta!\n");
                invalid=1;
            }
            if(month > 12 || month < 1){
                printf("Jus pateikete menesi netinkama, bandykite dar karta\n");
                invalid=1;
            }
            //leap year check
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
                daysInMonth[2] = 29;
            }
            if (invalid == 0) {
                if (day < 1 || day > daysInMonth[month]) {
                    printf("Jus pateikete netinkama diena, bandykite dar karta\n");
                    invalid = 1;
                }
            }
            if(invalid == 0){
                printf("Jusu pateikta data teisinga!\n");
                break;
            } 
        } else{
            printf("Jus ivedete data neteisingai! Bandykite dar karta:\n");
            while (getchar() != '\n');
            continue;
        }
    }

    //checking weekday
    //this algorithm is using the Zeller formula, meaning the week.txt file has to start from saturday
    int y = year;
    int m = month;
    if(m == 1 || m == 2){
        m += 12;
        y -= 1;
    }
    int weekDayNumber=(day + (13*(m + 1))/5 + y + y/4 - y/100 + y/400) % 7;
    
    char weekDay[20];
    FILE *myFile;
    myFile = fopen("week.txt","r");
    if(myFile != NULL){
        for(int i=0; i<=weekDayNumber; i++){
            if(fgets(weekDay,20,myFile) == NULL){
                printf("Programa nesugebejo atidaryti failo!\n");
            };
        }
    } else {
        printf("Programa nesugebejo atidaryti failo!\n");
    }
    
    printf("Spausdinami rezultatai:\n");
    printf("Jusu ivestos datos diena yra %s",weekDay);

    return 0;
}