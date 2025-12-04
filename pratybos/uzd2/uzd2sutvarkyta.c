//LSP:2513680, dinas.zaranka@mif.stud.vu.lt 2 uzd 2 variantas
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getInt(){
    int n;

    while(1){
        char ch;
        if(scanf("%d%c",&n,&ch) == 2){
            if(ch == '\n' && n > 0){
                printf("Sekmingai nuskaitytas skaicius!\n");
                return n;
            } else if(n < 0){
                printf("Jusu skaicius negali buti maziau 1\nIveskite kita skaiciu!\n");
                scanf("%*[^\n]");
            } else {
                printf("Jus ivedete netinkama skaiciu\nIveskite kita skaiciu!\n");
                scanf("%*[^\n]");
            }
        } else {
            printf("Jusu ivestis neteisinga\nIveskite kita skaiciu!\n");
            scanf("%*[^\n]");
        }
    }
}

void readArray(int n, int arr[]){
    printf("Iveskite savo skaiciu seka:\n");
    for(int i = 0; i < n; i++){
        arr[i] = getInt();
    }
}

int mostRecurrentNumber(int n, int arr[]){
    int mostSeenCount=0;
    int leastSeenCount = n;
    int mostSeenNumber = *arr;
    for(int i=0; i<n; i++){
        int count=0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count>mostSeenCount){
            mostSeenCount=count;
            mostSeenNumber=*(arr + i);
        }
        if(count<leastSeenCount){
            leastSeenCount = count;
        }
    }
    if(mostSeenCount == leastSeenCount){
        return INT_MIN;
    }
    return mostSeenNumber;
}

int main(){
    printf("Si programa tarp jusu ivestu skaiciu suras daugiausiai pasikartojanti\n");
    printf("Prasau iveskite sveika skaiciu, kuris nurodo kokio ilgio bus jusu skaiciu seka\n");

    int n = getInt();
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Nepavyko priskirti masyvui atminties");
        return 1;
    }

    readArray(n,arr);


    if(n == 1){
        printf("Jus ivedete tik viena skaiciu, kuris yra %d\n",*arr);
    } else{
        int result = mostRecurrentNumber(n,arr);
        if(result == INT_MIN){
            printf("Visi jusu ivesti skaiciai pasikartoja tiek pat kartu\n");
        } else {
            printf("Jusu ivestos sekos, dazniausiai pasikartojantis skaicius yra %d\n",result);
        }
    } 

    free(arr);
    return 0;
}