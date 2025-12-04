#include <stdio.h>
#include <string.h>
#include <assert.h>

int get_strlen(char *text){
    int count = 0;

    while(text[count] != '\0'){
        count++;
    }
    return count;
}

int main(){
    assert(get_strlen("abc") == 3);
    assert(get_strlen("hello") == 5);
    assert(get_strlen("") == 0);
    assert(get_strlen("a b c") == 5);

    printf("Tests passed\n");
    return 0;
}