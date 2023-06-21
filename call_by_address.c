#include <stdio.h>

void increment(int *num1, int num2) {
    (*num1)++;
    num2++;
}

int main() {
    int number1 = 5;
    
    int number2 = 10;

    printf("Before Increment Number1 => %d\n", number1);
    
    printf("Before Increment Number2 => %d\n", number2);

    increment(&number1, number2);

    printf("After Increment Number1 => %d\n", number1);
    
    printf("After Increment Number2 => %d\n", number2);

    return 0;
}
