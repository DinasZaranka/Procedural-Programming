#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *createArray(int size, int low, int high){
    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL){
        return NULL;
    }
    for(int i=0; i<size; i++){
        arr[i] = low + rand() % (high - low + 1);
    }
    
    return arr;
}

int main(){
    srand(time(NULL));
    int size = 5;
    int low = 5;
    int high = 15;
    int *arr = createArray(size,low,high);
    if(arr == NULL){
        printf("Nepavyko priskirti masyvui atminties");
        return 1;
    }

    for(int i=0; i<size; i++){
        printf("%d\n",arr[i]);
    }  
    free(arr);
    return 0;
}