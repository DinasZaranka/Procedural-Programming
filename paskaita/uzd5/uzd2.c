#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 1000


int main(){
    srand(time(NULL));
    int x[CAPACITY];

    int a,b,c;
    printf("irasykite tris skaicius [a,b] kad nustatyti rezius ir c kad nustatyti kiek norite skaiciu: \n");
    scanf("%d %d %d", &a,&b,&c);
    while(c<=0 || c>1000){
        printf("Jusu trecias skaicius nepriklauso intervalui (0,1000), prasau iveskite visus tris skaicius dar karta: \n");
        scanf("%d %d %d", &a,&b,&c);
    }
    while(a>=b){
        printf("a turi buti mazesnis uz b, prasau iveskite visus tris skaicius dar karta: \n");
        scanf("%d %d %d", &a,&b,&c);
    }
    
    //masyvo pildymas
    for(int i=0; i<c; i++){
        x[i]= a + rand() % (b - a + 1);
    }

    //masyvo spausdinimas
    printf("Spausdinamas jusu sukutas masyvas:\n");
    for(int i=0; i<c; i++){
        printf("%d ",x[i]);
    }
    return 0;
}