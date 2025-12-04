#include <stdio.h>
#include <string.h>
#include <assert.h>

char *get_strchr(char *str, int character){
    while(*str != '\0'){
        if(*str == character){
            return str;
        }
        str++;
    }

    return NULL;
}

int main(){
    char *result;
    result = get_strchr("abcde", 'c');
    assert(result != NULL);
    assert(*result == 'c');

    result = get_strchr("hello", 'l');
    assert(*result == 'l');

    result = get_strchr("hello", 'z');
    assert(result == NULL);

    printf("Tests passed\n");
    return 0;
}