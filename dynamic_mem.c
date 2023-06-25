#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int* numbers;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically for the array
    numbers = (int*)malloc(n * sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("The numbers you entered are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Deallocate the dynamically allocated memory
    free(numbers);

    return 0;
}
