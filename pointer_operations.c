#include <stdio.h>

int main() {
    int a = 2, b = 3, c = 5;
    
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;

    int result_plus1 = *ptr_a + *ptr_b + *ptr_c;
    int result_plus2 = *ptr_a + *ptr_b - *ptr_c;

    int result_minus1 = *ptr_a - *ptr_b - *ptr_c;
    int result_minus2 = *ptr_a - *ptr_b + *ptr_c;

    printf("Result (a + b + c): %d\n", result_plus1);
    printf("Result (a + b - c): %d\n", result_plus2);
    printf("Result (a - b - c): %d\n", result_minus1);
    printf("Result (a - b + c): %d\n", result_minus2);

    return 0;
}
