#include <stdio.h>
#include <string.h>
#include <assert.h>

char *get_strncpy(char *destination, char *source, int n){
    int i=0;
    while(i < n && source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }

    while(i < n){
        destination[i] = '\0';
        i++;
    }

    return destination;
}

int main(){
    char buffer[100];

    get_strncpy(buffer,"abc",3);
    assert(buffer[0] == 'a');
    assert(buffer[1] == 'b');
    assert(buffer[2] == 'c');

    get_strncpy(buffer,"abc",2);
    assert(buffer[0] == 'a');
    assert(buffer[1] == 'b');

    get_strncpy(buffer,"hello",6);
    assert(buffer[0] == 'h');
    assert(buffer[1] == 'e');
    assert(buffer[2] == 'l');
    assert(buffer[3] == 'l');
    assert(buffer[4] == 'o');
    assert(buffer[5] == '\0');


    printf("Tests passed\n");
    return 0;
}