#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define PRINT_MSG(msg) printf("Message: %s\n", msg)

int main() {
    int x = 10;
    int y = 20;

    int max_val = MAX(x, y);
    printf("Maximum value: %d\n", max_val);

    PRINT_MSG("Hello, world!");

    return 0;
}
