#include <stdio.h>

void printNumber(int number) {
    printf("Number: %d\n", number);
}

void printString(const char* string) {
    printf("String: %s\n", string);
}

int main() {
    // Declare a function pointer for printNumber function
    void (*numberPrinter)(int);

    // Assign the address of printNumber to the function pointer
    numberPrinter = printNumber;

    // Call the function through the function pointer
    numberPrinter(42);

    // Declare a function pointer for printString function
    void (*stringPrinter)(const char*);

    // Assign the address of printString to the function pointer
    stringPrinter = printString;

    // Call the function through the function pointer
    stringPrinter("Hello, World!");

    return 0;
}
