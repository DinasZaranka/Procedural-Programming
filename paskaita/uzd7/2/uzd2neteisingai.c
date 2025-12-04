#include <stdio.h>

int getFactorial(int number){
    int factorial = 1;
    if(number < 0){
        return 0;
    }

    for(int i=1; i<=number; i++){
        factorial = factorial * i;
    }
    return factorial;    
}

int main(){
    printf("Si programa suskaiciuoja jusu duoto skaiciaus faktoriala\n");
    printf("Prasau iveskite skaiciu\n");

    int number = 0;
    if(scanf("%d",&number) == 1){
        int factorial = getFactorial(number);
        if(getFactorial(number) != 0){
            printf("Jusu skaiciaus faktorialas yra %d",factorial);
        } else {
            printf("Programa nesugebejo suskaiciuoti jusu skaiciaus faktorialo\n");
        }
    } else {
        printf("Jusu ivestis ne teisinga\n");
    }


    return 0;
}