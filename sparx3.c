#include <stdio.h>

int main() {
    int poly1[20][2], poly2[20][2], result[40][2];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter terms of first polynomial (coefficient exponent):\n");
    for(i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i][0], &poly1[i][1]);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter terms of second polynomial (coefficient exponent):\n");
    for(j = 0; j < n2; j++) {
        scanf("%d %d", &poly2[j][0], &poly2[j][1]);
    }

    i = 0;
    j = 0;
    k = 0;

    while(i < n1 && j < n2) {
        if(poly1[i][1] > poly2[j][1]) {
            result[k][0] = poly1[i][0];
            result[k][1] = poly1[i][1];
            i++; k++;
        }
        else if(poly1[i][1] < poly2[j][1]) {
            result[k][0] = poly2[j][0];
            result[k][1] = poly2[j][1];
            j++; k++;
        }
        else {
            result[k][0] = poly1[i][0] + poly2[j][0];
            result[k][1] = poly1[i][1];
            i++; j++; k++;
        }
    }

    while(i < n1) {
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++; k++;
    }

    while(j < n2) {
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++; k++;
    }

    printf("\nResultant Polynomial after Addition:\n");
    for(i = 0; i < k; i++) {
        printf("%dx^%d", result[i][0], result[i][1]);
        if(i != k - 1)
            printf(" + ");
    }

    printf("\n");
    return 0;
}
