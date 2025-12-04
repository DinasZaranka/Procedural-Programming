#include <stdio.h>
#include <stdlib.h>

char *biggestFileName(int argc, char *argv[]){
    int maxSize = -1;
    int maxElementPos = -1;
    for(int i=0; i<argc; i++){
        FILE *myFile = fopen(argv[i],"rb");
        if(myFile == NULL){
            continue;
        }

        fseek(myFile,0,SEEK_END);
        int size = ftell(myFile);
        if(size>maxSize){
            maxSize = size;
            maxElementPos = i;
        }
        fclose(myFile);
    }

    if(maxElementPos == -1){
        return NULL;
    }

    return argv[maxElementPos];
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Neivedete failu\n");
        return 1;
    }

    char *largestFile = biggestFileName(argc-1,argv+1);

    if(largestFile != NULL){
        printf("Didziausias failas: %s\n",largestFile);
    } else {
        printf("Programa nesugebejo atidaryti nei vieno failo!\n");
    }

    return 0;
}