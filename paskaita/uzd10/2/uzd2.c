#include <stdio.h>
#include <string.h>
#include <assert.h>

char *get_strcpy(char *originalText, char *Copy){
    int i=0;
    while(originalText[i] != '\0'){
        Copy[i] = originalText[i];
        i++;
    }
    Copy[i]='\0';
    return Copy;
}

int main(){
    char buffer[100];

    assert(strcmp(get_strcpy("abc", buffer), "abc") == 0);
    assert(strcmp(get_strcpy("Hello", buffer), "Hello") == 0);
    assert(strcmp(get_strcpy("", buffer), "") == 0);

    printf("Tests passed\n");
    return 0;
}