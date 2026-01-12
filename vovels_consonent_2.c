#include <stdio.h>
#include <ctype.h>

void count_vowels_consonants(char *str, int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    char ch;
    
    while (*str != '\0') {
        ch = tolower(*str);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
        str++;
    }
}

int main() {
    char str[] = "Hello World! This is a test string.";
    int vowels_count, consonants_count;

    count_vowels_consonants(str, &vowels_count, &consonants_count);

    printf("String: %s\n", str);
    printf("Number of Vowels: %d\n", vowels_count);
    printf("Number of Consonants: %d\n", consonants_count);

    return 0;
}
