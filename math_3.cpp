#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float div(int a, int b) { return (float)a / b; }

int main() {
    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("1.Add  2.Subtract  3.Multiply  4.Divide\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("Result = %d", add(a,b)); break;
        case 2: printf("Result = %d", sub(a,b)); break;
        case 3: printf("Result = %d", mul(a,b)); break;
        case 4: printf("Result = %.2f", div(a,b)); break;
        default: printf("Invalid choice");
    }

    return 0;
}
