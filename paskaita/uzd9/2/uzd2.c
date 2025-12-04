#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int size;
} Stack;

void initStack(Stack *stack){
    stack->data = NULL;
    stack->size = 0;
}

void printStack(Stack *stack){

    printf("Steko elementai: ");
    for(int i=0; i<stack->size; i++){
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, int value){
    stack->data = realloc(stack->data, (stack->size + 1) * sizeof(int));
    
    stack->data[stack->size] = value;
    stack->size++;
}

int top(Stack *stack){
    if(stack->size == 0){
        return 0;
    }
    return stack->data[stack->size-1];
    
}

int pop(Stack *stack){
    int value = top(stack);
    stack->size--;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
    return value;
}

void destroyStack(Stack *stack){
    free(stack->data);
    stack->data = NULL;
    stack->size=0;
}

int main(){
    Stack s;
    
    return 0;
}