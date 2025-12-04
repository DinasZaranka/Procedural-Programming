#include <stdio.h>
#include <stdlib.h>

int splitData(int *arr, int size, int firstHalfSize, int *firstArray[], int *secondArray[]){
    if(firstHalfSize > size){
        return -1;
    }
    if(*secondArray || *firstArray != NULL){
        return -1;
    }
    int secondHalfSize = size - firstHalfSize;
    *firstArray = (int *)malloc(firstHalfSize * sizeof(int));
    *secondArray = (int *)malloc(secondHalfSize * sizeof(int));
    for(int i=0; i<firstHalfSize; i++){
        (*firstArray)[i]=arr[i];
    }
    for(int i=0; i < secondHalfSize; i++){
        (*secondArray)[i]=arr[firstHalfSize + i];
    }
    return 0;
}

int main(){
    int size = 11;
    int firstHalfSize = 5;
    int *arr = (int *)malloc(size * sizeof(int));
    arr[0] = 4;
    arr[1] = 5;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 8;
    arr[5] = 5;
    arr[6] = 9;
    arr[7] = 1;
    arr[8] = 2;
    arr[9] = 4;
    arr[10] = 7;
    printf("Duotas array:\n");
    for(int i=0; i<size; i++){
        printf("%d\n",arr[i]);
    }
    int *firstArray = NULL;
    int *secondArray = NULL;
    
    if(splitData(arr,size,firstHalfSize,&firstArray,&secondArray) != 0){
        printf("Programoje ivyko klaida!\n");
        return 1;
    }

    printf("\nfirstHalf array:\n");
    for(int i=0; i<firstHalfSize; i++){
        printf("%d\n",firstArray[i]);
    }

    printf("\nsecondHalf array:\n");
    for(int i=0; i<size - firstHalfSize; i++){
        printf("%d\n",secondArray[i]);
    }

    free(arr);
    free(firstArray);
    free(secondArray);
    return 0;
}