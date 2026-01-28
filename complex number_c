#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

int main() {
    struct Complex c1, c2, sum, product;

    // Input
    printf("Enter real and imaginary part of first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter real and imaginary part of second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);

    // Addition
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    // Multiplication
    product.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    product.imag = (c1.real * c2.imag) + (c1.imag * c2.real);

    // Output
    printf("\nSum = %.2f + %.2fi", sum.real, sum.imag);
    printf("\nProduct = %.2f + %.2fi", product.real, product.imag);

    return 0;
}
