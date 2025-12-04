#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    printf("Si funkcija apkeicia dvi jusu reiksmes vietomis\n");
    int a = 5;
    int b = 10;
    printf("Dabar a yra %d, b yra %d\n",a,b);
    printf("Ivykdome funkcija\n");
    swap(&a,&b);
    printf("Dabar a yra %d, b yra %d\n",a,b);
    return 0;
}