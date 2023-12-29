#include <stdio.h>
#include <stdlib.h>

int *createIntArray() {
    int arr[] = {1, 2, 3, 4, 5};
    return arr; // Returning a pointer to a local array, which will be deallocated
}

int main() {
    int *danglingPointer;

    // Creating a dangling pointer
    danglingPointer = createIntArray();

    // Accessing the memory through the dangling pointer
    printf("%d\n", danglingPointer[0]); // Undefined behavior

    // The memory that the dangling pointer points to has been deallocated,
    // and attempting to access it can result in unpredictable behavior.

    return 0;
}
