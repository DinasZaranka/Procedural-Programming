#include <stdio.h>
#define CAPACITY 100

int main(){
    //a)
    int A[10]={0};
    
    //b)
    for(int i=0; i<10; i++){
        printf("%d\n",A[i]);
    }
    
    //c)
    A[0]=1;
    A[3]=2;
    A[9]=3;
    
    //d)
    for(int i=2; i<9; i++){
        A[i]=A[i+1];
    }
    
    //e)
    for(int i=9; i>6; --i){
        A[i]=A[i-1];
    }
    A[6]=4;
    
    //f
    printf("\n\n");
    for(int i=0; i<10; i++){
        printf("%d\n",A[i]);
    }
    
    //g
    printf("Iveskite du skaicius:\n");
    int x,y;
    scanf("%d %d",&x,&y);
    
    while(1){
        if(x>=0 && x<10){
            A[x]=y;
            break;
        } else {
            printf("Jusu pirmas ivestas skaicius negali virsyti masyvo ribos, prasau iveskite du skaicius dar karta, pirmas skaicius priklauso [0,9] intervalui:\n");
            scanf("%d %d",&x,&y);
        }
    }
    
    //h
    printf("Iveskite viena skaiciu:\n");
    scanf("%d",&x);
    while(x < 0 ||   x >= 10){
        printf("Jusu ivestas skaicius virsija ribas [0,9], bandykite dar karta:\n");
        scanf("%d", &x);
    }
    for(int i=x; i<9; i++){
        A[i]=A[i+1];
    }
    
    //i
    printf("Iveskite du skaicius:\n");
    scanf("%d %d", &x,&y);
 
    while(1){
        if(x>=0 && x<10){
            for(int i=9; i>x; --i){
            A[i]=A[i-1];
            }
            A[x]=y;
        break;
        } else {
            printf("Jusu pirmas ivestas skaicius negali virsyti masyvo ribos, prasau iveskite du skaicius dar karta, pirmas skaicius priklauso [0,9] intervalui:\n");
            scanf("%d %d",&x,&y);
        }
    }

    //j
    printf("\n\n");
    for(int i=0; i<10; i++){
        printf("%d\n",A[i]);
    }

    return 0;
}