#include <stdio.h>

typedef int myInt;  // Define "myInt" as an alias for the type "int"

typedef struct {
    int x;
    int y;
} Point;  // Define "Point" as an alias for the struct type

typedef void (*MyFunctionPointer)(int);  // Define "MyFunctionPointer" as an alias for a function pointer

void printNumber(int number) {
    printf("Number: %d\n", number);
}

int main() {
    myInt num = 42;
    printf("Number: %d\n", num);

    Point p;
    p.x = 10;
    p.y = 20;
    printf("Point: (%d, %d)\n", p.x, p.y);

    MyFunctionPointer func = printNumber;
    func(100);

    return 0;
}
