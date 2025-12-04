#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

int main(){
    printf("Iveskite du skaicius: \n");
    int s,n;
    scanf("%d %d", &s, &n);
    printf("Iveskite %d teigiamas reiksmes: \n",n);

    int x[CAPACITY];
    for(int i=0; i<n; i++){
        int temp;
        do {
            scanf("%d",&temp);
            if(temp <= 0 ){
                printf("Jus ivedete neteigiama skaiciu, bandykite dar karta: \n");
            }
        } while (temp <= 0);
        x[i]=temp; 
    }
    
    printf("Programos rezultatai: \n");
    

    int found=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(x[i] * x[j] == s){
                if(found==0){
                    printf("Tinkamos poros:\n");
                }
                printf("%d %d\n",x[i],x[j]);
                found=1;
            }
        }
    }

    if(found!=1){
        printf("Tinkamu poru nebuvo rasta \n");
    }
    return 0;
}