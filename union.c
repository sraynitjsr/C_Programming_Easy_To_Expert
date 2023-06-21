#include <stdio.h>

// Define a union named MyUnion
union MyUnion {
    int intValue;
    float floatValue;
    char stringValue[20];
};

int main() {
    // Declare a variable of type MyUnion
    union MyUnion u;

    // Assign a value to the intValue member
    u.intValue = 42;
    printf("Value stored in intValue: %d\n", u.intValue);

    // Assign a value to the floatValue member
    u.floatValue = 3.14;
    printf("Value stored in floatValue: %.2f\n", u.floatValue);

    // Assign a value to the stringValue member
    strcpy(u.stringValue, "Hello, Union!");
    printf("Value stored in stringValue: %s\n", u.stringValue);

    // Accessing different members of the union
    printf("Value stored in intValue: %d\n", u.intValue);
    printf("Value stored in floatValue: %.2f\n", u.floatValue);

    return 0;
}
