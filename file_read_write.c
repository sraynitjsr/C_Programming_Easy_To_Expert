#include<stdio.h>

#define MAX_SIZE 100

int main() {
    char data[MAX_SIZE];

    // Open the source file in read mode
    FILE *sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Read data from the source file
    fgets(data, MAX_SIZE, sourceFile);

    // Close the source file
    fclose(sourceFile);

    // Open the destination file in write mode
    FILE *destFile = fopen("destination.txt", "w");
    if (destFile == NULL) {
        printf("Unable to open the destination file.\n");
        return 1;
    }

    // Write data to the destination file
    fputs(data, destFile);

    // Close the destination file
    fclose(destFile);

    printf("File read and write operations completed.\n");

    return 0;
}
