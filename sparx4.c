#include <stdio.h>

int main() {
    int poly1[20][2], poly2[20][2], result[40][2];
    int n1, n2;
    int i, j, k = 0;
    int x;   

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter terms of first polynomial (coefficient exponent):\n");
    for(i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i][0], &poly1[i][1]);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter terms of second polynomial (coefficient exponent):\n");
    for(i = 0; i < n2; i++) {
        scanf("%d %d", &poly2[i][0], &poly2[i][1]);
    }

  
    for(i = 0; i < 40; i++) {
        result[i][0] = 0;
        result[i][1] = 0;
    }

    for(i = 0; i < n1; i++) {
        for(j = 0; j < n2; j++) {

            int coeff = poly1[i][0] * poly2[j][0];
            int exp   = poly1[i][1] + poly2[j][1];

            int found = 0;

            
            for(x = 0; x < k; x++) {
                if(result[x][1] == exp) {
                    result[x][0] += coeff;
                    found = 1;
                    break;
                }
            }

            if(!found) {
                result[k][0] = coeff;
                result[k][1] = exp;
                k++;
            }
        }
    }

    printf("\nResultant Polynomial after Multiplication:\n");
    for(i = 0; i < k; i++) {
        printf("%dx^%d", result[i][0], result[i][1]);
        if(i != k - 1)
            printf(" + ");
    }

    printf("\n");
    return 0;
}
