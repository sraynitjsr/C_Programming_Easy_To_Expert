#include <stdio.h>

// Definition of the callback function type
typedef void (*Callback)(int, int);

// Function that takes a callback function as an argument
void performOperation(int value, Callback callback) {
    printf("Performing area calculation with radius => %d\n", value);
    
    // Call the callback function
    callback(value, 3.14*value*value);
}

// Callback function to be passed
void callbackFunctionAreaOfCircle(int radius, int area) {
    printf("Area of the circle with radius %d is => %d \n", radius, area);
}

int main() {
    int data = 10;

    // Call performOperation and pass the callback function
    performOperation(data, callbackFunctionAreaOfCircle);

    return 0;
}
