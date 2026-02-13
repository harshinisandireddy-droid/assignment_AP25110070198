#include <stdio.h>

#define MAX 100
#define SIZE 10
void convertToSparse(int rows, int cols, int mat[SIZE][SIZE], int sparse[MAX][3])
{
    int i, j;
    int k = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;
}

/* Print sparse matrix */
void printSparse(int sparse[MAX][3])
{
    int i;
    int totalNonZero = sparse[0][2];

    printf("Row\tCol\tValue\n");

    for (i = 0; i <= totalNonZero; i++) {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
}

/* Transpose sparse matrix */
void transpose(int sparse[MAX][3], int trans[MAX][3])
{
    int rows, cols, num;
    int i, col;
    int k = 1;

    rows = sparse[0][0];
    cols = sparse[0][1];
    num  = sparse[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = num;

    for (col = 0; col < cols; col++) {
        for (i = 1; i <= num; i++) {
            if (sparse[i][1] == col) {
                trans[k][0] = sparse[i][1];
                trans[k][1] = sparse[i][0];
                trans[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}
int main()
{
    int rows, cols;
    int i, j;
    int mat[SIZE][SIZE];
    int sparse[MAX][3], trans[MAX][3];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    convertToSparse(rows, cols, mat, sparse);

    printf("\nSparse Matrix (3-tuple form):\n");
    printSparse(sparse);

    transpose(sparse, trans);

    printf("\nTranspose Sparse Matrix (3-tuple form):\n");
    printSparse(trans);

    return 0;
}
