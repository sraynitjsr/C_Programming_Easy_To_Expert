#include <stdio.h>

int main() {
    int num = 10;       // Declare an integer variable
    int *ptr = &num;    // Declare a pointer and initialize it with the address of 'num'

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr: %p\n", ptr);
    printf("Value stored at the address pointed by ptr: %d\n", *ptr);

    return 0;
}
