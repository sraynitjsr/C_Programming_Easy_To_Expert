#include <stdio.h>

#define DEBUG_MODE 1

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(msg) printf("Debug: %s\n", msg)
#else
    #define DEBUG_PRINT(msg)
#endif

#ifndef NDEBUG
    #define ASSERT(condition) \
        if (!(condition)) { \
            printf("Assertion failed at %s:%d\n", __FILE__, __LINE__); \
            exit(1); \
        }
#else
    #define ASSERT(condition)
#endif

int main() {
    int x = 10;
    int y = 20;

    DEBUG_PRINT("Debug message");

    int max_val = MAX(x, y);
    printf("Maximum value: %d\n", max_val);

    ASSERT(x > 0);

    return 0;
}
