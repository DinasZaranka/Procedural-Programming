#include <stdio.h>

long getFileSize(char *fileName){
    FILE *myFile = fopen(fileName,"rb");
    long size = 0;
    if(myFile != NULL){
        fseek(myFile,0,SEEK_END);
        size = ftell(myFile);
        return size;
    } else{
        return -1;
    }
}

int main(){
    printf("Programa grazina failo dydi(baitais)\n");
    char fileName[] = "failas.txt";
    
    long size = getFileSize(fileName);
    printf("Failo dydis: %li\n",size);

    return 0;
}