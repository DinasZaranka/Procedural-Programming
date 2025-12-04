//LSP:2513680, dinas.zaranka@mif.stud.vu.lt 3 uzd 4 variantas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *connectWords(char *line){
    int size = strlen(line);
    char *buffer = calloc(size+1, sizeof(char));
    if (buffer == NULL){
        return NULL;
    }
    strcpy(buffer,line);

    int capacity = 8;
    int wordCount = 0;
    int *start = calloc(capacity, sizeof(int));
    int *end = calloc(capacity, sizeof(int));
    
    int i = 0;
    while(buffer[i] != '\0'){
        if(isspace(buffer[i])){
            i++;
            continue;
        }

        if (wordCount >= capacity){
            capacity *= 2;
            start = realloc(start, capacity * sizeof(int));
            end = realloc(end, capacity * sizeof(int));
        }

        start[wordCount] = i;

        while(buffer[i] != '\0' && !isspace(buffer[i])){
            i++;
        }

        end[wordCount] = i-1;

        wordCount++;
    }

    for(int i=0; i<wordCount-1; i++){
        char lastChar = buffer[end[i]];
        char nextChar = buffer[start[i+1]];

        if(lastChar == nextChar){
            int left = end[i] + 1;
            int right = start[i+1];
            int offset=right - left;
            
            memmove(buffer + left, buffer + right, strlen(buffer + right) + 1);

            for(int j=i+1; j<wordCount; j++){
                start[j] -= offset;
                end[j] -= offset;
            }
        }
    }

    free(start);
    free(end);

    return buffer;
}


int main(){
    FILE *input;
    FILE *output;

    char *dataFile = calloc(256, sizeof(char));
    char *resultFile = calloc(256, sizeof(char));
    
    while(1){
        printf("Prasau iveskite failo pavadinima is kurio programa turetu paimti duomenis:\n");
        scanf("%s",dataFile);
        
        input = fopen(dataFile, "r");
        if(input != NULL){
            break;
        }
        printf("Jusu ivestas duomenu failas neegzistuoja, bandykite dar karta!\n");
    }
    
    while(1){
        printf("Prasau iveskite failo pavadinima i kuri programa spausdins jusu rezultatus:\n");
        scanf("%s",resultFile);
        
        output = fopen(resultFile, "w");
        if(output != NULL){
            break;
        }
        
        printf("Jusu rezultato failo programa nesugebejo sukurti\n");
    }

    char line[256];
    while(fgets(line, 256, input) != NULL){
        int len = strlen(line);
        
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        } else {
            if (!feof(input)) {
                int ch;
                do {
                    ch = fgetc(input);
                } while (ch != EOF && ch != '\n');

                line[255] = '\0';
            }
        }
        
        char *processed = connectWords(line);
        
        fputs(processed, output);
        putc('\n', output);
        free(processed);
    }


    free(dataFile);
    free(resultFile);

    fclose(input);
    fclose(output);
    return 0;
}