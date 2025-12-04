#include <stdio.h>
#include <string.h>
#include <assert.h>

void *get_memset(void *ptr, int character, size_t n){
    unsigned char *p = ptr;
    unsigned char value = character;

    for(int i=0; i<n; i++){
        p[i] = value;
    }

    return ptr;
}

int main(){
    char buffer[100];

    get_memset(buffer, 'a', 5);
    assert(buffer[0] == 'a');
    assert(buffer[1] == 'a');
    assert(buffer[2] == 'a');
    assert(buffer[3] == 'a');
    assert(buffer[4] == 'a');

    get_memset(buffer, 0, 10);
    for(int i=0; i<10; i++){
        assert(buffer[i] == 0);
    }

    get_memset(buffer, 255, 3);
    assert((unsigned char)buffer[0] == 255);
    assert((unsigned char)buffer[1] == 255);
    assert((unsigned char)buffer[2] == 255);

    printf("Tests passed\n");
    return 0;
}