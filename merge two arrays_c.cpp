#include <stdio.h>

int main() {
    int a[50], b[50], c[100];
    int n1, n2, i, j;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");
    for(j = 0; j < n2; j++) {
        scanf("%d", &b[j]);
        c[i] = b[j];
        i++;
    }

    printf("Merged array:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
