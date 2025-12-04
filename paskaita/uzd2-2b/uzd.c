#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("Si programa atlieka skaiciu konversija is vienos skaiciavimo sistemos i kita (Skaiciai yra konvertuojami is kaires i desine)\n\n");

    printf("Sie skaiciai yra konvertuoti is dvejetaines i desimtaine\n");
    printf("%d - %ld\n", 11011, strtol("11011", NULL, 2));
    printf("%d - %ld\n", 10010100, strtol("10010100", NULL, 2));
    printf("%ld - %ld\n\n", 11001011010101, strtol("11001011010101", NULL, 2));    
  

    printf("Sie skaiciai yra konvertuoti is desimtaines i dvejetaine:\n");
    printf("%d - %d\n",37, 100101);
    printf("%d - %d\n",241, 11110001);
    printf("%d - %ld\n\n",2487, 100110110111);

    printf("Sie skaiciai yra konvertuoti is sesioliktaines i desimtaine:\n");
    printf("%X - %d\n", 0x6E2, 0x6e2);
    printf("%X - %d\n", 0xED33, 0xED33);
    printf("%X - %d\n\n", 0x123456, 0x123456);

    printf("Sie skaiciai yra konvertuoti is desimtaines i sesioliktaine:\n");
    printf("%d - %X \n",243, 243);
    printf("%d - %X \n",2483, 2483);
    printf("%d - %X \n",4612, 4612);

    return 0;
}