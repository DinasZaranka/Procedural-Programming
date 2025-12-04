#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        data[i] = low + rand() % (high - low + 1);
    }
}

int main(){
    printf("Programa uzpildo masyva atitinkamos reiksmemis pagal jusu nurodymus\n");

    int data[100];
    int size = 20;
    int low = 1;
    int high = 50;

    printf("Jusu masyvas:\n");
    generateArray(data,size,low,high);
    for(int i=0; i<size; i++){
        printf("%d\n",data[i]);
    }

    return 0;
}