#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x,y;
} Point;

typedef struct{
    Point *data;
    int size;
} Stack;

double getDistance(Point a, Point b){
    double distance = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
    return distance;
}

void initStack(Stack *stack){
    stack->data = NULL;
    stack->size = 0;
}

void printStack(Stack *stack){
    Point start={0,0};
    for(int i=0; i<stack->size; i++){
        Point a = stack->data[i];
        printf("\nTasku koordinates : (%.0f,%.0f)\nAtstumas nuo pradzios tasko: %f\n", a.x, a.y, getDistance(start,a));
    }
    printf("\n");
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, Point value){
    stack->data = realloc(stack->data, (stack->size + 1) * sizeof(Point));
    
    stack->data[stack->size] = value;
    stack->size++;
}

Point top(Stack *stack){
    Point empty={0,0};
    if(stack->size == 0){
        return empty;
    }
    return stack->data[stack->size-1];
    
}

Point pop(Stack *stack){
    Point value = top(stack);
    stack->size--;
    stack->data = realloc(stack->data, stack->size * sizeof(Point));
    return value;
}

void destroyStack(Stack *stack){
    free(stack->data);
    stack->data = NULL;
    stack->size=0;
}

int main(){
    Stack s;
    initStack(&s);
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};
    Point p4 = {2, 8};
    Point p5 = {7, 1};

    push(&s, p1);
    push(&s, p2);
    push(&s, p3);
    push(&s, p4);
    push(&s, p5);

    printStack(&s);

    return 0;
}