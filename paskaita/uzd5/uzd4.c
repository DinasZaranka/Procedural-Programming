#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

int main(){
    int x[CAPACITY];
    int n=0;
    
    printf("Iveskite skaicius. Skaiciu seka pasibaigs kai ivesite neigiama skaiciu\n");
    int input=0;
    while(input>=0){
        scanf("%d", &input);
        if(input>=0){
            x[n]=input;
            n++;
        } else {
            break;
        }
    }


    int temp[CAPACITY];
    int m=0;
    int uniquePrimes[CAPACITY];
    
    printf("Spausdinami rezultatai:\n");
    printf("Nesikartojantys pirminiai skaiciai:\n");
    
    for(int i=0; i<n; i++){
        int num = x[i];
        int isPrime = 1;
        if(num < 2){
            isPrime = 0; 
        } else {
            for(int j=2; j<num; j++){
                if(num%j==0){
                    isPrime = 0;
                    break;
                }
            }
        }
        
        if(isPrime==1){
            int alreadyExists = 0;
                for(int k=0; k<m; k++){
                    if(uniquePrimes[k]==num){
                        alreadyExists = 1;
                        break;
                    }
                }
            if(alreadyExists==0){
                uniquePrimes[m] = num;
                m++;
                printf("%d ",num);
            }
        }
    }

    if(m==0){
        printf("Jus neivede jokiu pirminiu skaiciu.");
    }

    return 0;
}