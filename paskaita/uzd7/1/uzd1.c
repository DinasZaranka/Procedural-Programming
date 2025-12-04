#include <stdio.h>
#include <stdbool.h>

int isInRange(int number, int low, int high){
    char isCorrect[20];
    if(low <= high){
        if(number >= low && number <= high){
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int main(){
    printf("Si programa patikrina ar jusu ivestas skaicius papuola i intervala [1;100]");
    printf("Prasau iveskite skaiciu:\n");
    
    int number=0;
    int low=1;
    int high=100;
    if(scanf("%d",&number) == 1){
        if(isInRange(number,low,high) == true){
        printf("Jusu skaicius telpa i intervala\n");
        } else {
        printf("Jusu skaicius ne telpa i intervala\n");
        }
    } else {
        printf("Jusu ivestis neteisinga\n");
    }

    return 0;
}