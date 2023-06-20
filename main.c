#include <stdio.h>
#include <string.h>

// Define a structure for a person
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    printf("Hello, World!\n");

    // Declare a structure variable
    struct Person person1;

    // Assign values to the structure members
    strcpy(person1.name, "John");
    person1.age = 25;
    person1.height = 1.75;

    // Access and display the structure members
    printf("Person's name: %s\n", person1.name);
    printf("Person's age: %d\n", person1.age);
    printf("Person's height: %.2f meters\n", person1.height);

    return 0;
}
