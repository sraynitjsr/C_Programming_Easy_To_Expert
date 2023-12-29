void reverseString(char *str) {
    char *start = str;
    char *end = start + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello";
    reverseString(str);
    printf("%s\n", str);
    return 0;
}
