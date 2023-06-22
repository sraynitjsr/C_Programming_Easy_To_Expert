#include <stdio.h>

// Definition of the callback function type
typedef void (*Callback)(int);

// Function that takes a callback function as an argument
void performOperation(int value, Callback callback) {
    printf("Performing operation with value: %d\n", value);
    
    // Call the callback function
    callback(value*2);
}

// Callback function to be passed
void callbackFunction(int value) {
    printf("Callback function called with value: %d\n", value);
}

int main() {
    int data = 10;

    // Call performOperation and pass the callback function
    performOperation(data, callbackFunction);

    return 0;
}
