#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;
    int **ptrToPtr = &ptr;

    printf("Value of num => %d\n", num);
    printf("Value of ptr => %p\n", ptr);
    printf("Value of ptrToPtr => %p\n", ptrToPtr);
    printf("Value stored at the address pointed by ptrToPtr => %d\n", **ptrToPtr);

    return 0;
}
