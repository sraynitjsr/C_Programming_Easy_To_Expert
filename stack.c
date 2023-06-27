#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main() {
    int capacity = 5;
    Stack* stack = createStack(capacity);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Top element => %d\n", peek(stack));

    int poppedElement = pop(stack);
    printf("Popped element => %d\n", poppedElement);

    printf("Top element => %d\n", peek(stack));

    destroyStack(stack);

    return 0;
}
