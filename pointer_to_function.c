#include <stdio.h>

// Function that takes two integers and returns their sum
int add(int a, int b) {
    return a + b;
}

// Function that takes two integers and returns their difference
int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Declare a function pointer named "operation" that takes two int arguments and returns int
    int (*operation)(int, int);

    // Assign the address of the "add" function to the function pointer
    operation = add;

    // Call the function through the function pointer
    int result = operation(4, 3);
    printf("Result: %d\n", result);  // Output: 7

    // Reassign the address of the "subtract" function to the function pointer
    operation = subtract;

    // Call the function through the function pointer
    result = operation(10, 5);
    printf("Result: %d\n", result);  // Output: 5

    return 0;
}
