#include<stdio.h>
#include<string.h>

struct Person {
    char name[20];
    int age;
    float height;
};

union Data {
    int number;
    float decimal;
    char character;
};

int main() {
    printf("\nPrinting struct data\n");
    
    struct Person person;
    strcpy(person.name, "Subhradeep Ray");
    person.age = 25;
    person.height = 175;

    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f\n", person.height);

    printf("\nPrinting union data\n");

    union Data data;
    data.number = 10;
    printf("Number: %d\n", data.number);

    data.decimal = 3.14;
    printf("Decimal: %.2f\n", data.decimal);

    data.character = 'X';
    printf("Character: %c\n", data.character);

    return 0;
}
