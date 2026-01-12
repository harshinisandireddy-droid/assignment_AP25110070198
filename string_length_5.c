#include <stdio.h>

int string_length_ptr(const char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char input_string[] = "Hello";
    int length = string_length_ptr(input_string);

    printf("Input: \"%s\"\n", input_string);
    printf("Output: %d\n", length);

    return 0;
}

