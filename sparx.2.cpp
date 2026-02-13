#include <stdio.h>

/* Convert normal matrix to sparse (3-tuple) form */
void convertToSparse(int m, int n, int mat[10][10], int sparse[100][3])
{
    int i, j, k = 1;

    sparse[0][0] = m;
    sparse[0][1] = n;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;   // number of non-zero elements
}

/* Print sparse matrix */
void printSparse(int s[100][3])
{
    int i;
    printf("\nRow  Col  Val\n");
    for(i = 0; i <= s[0][2]; i++)
    {
        printf("%d    %d    %d\n", s[i][0], s[i][1], s[i][2]);
    }
}

/* Add two sparse matrices */
void addSparse(int a[100][3], int b[100][3], int c[100][3])
{
    int i = 1, j = 1, k = 1;
    int t1 = a[0][2], t2 = b[0][2];

    /* Check order */
    if(a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        printf("Matrix addition not possible\n");
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while(i <= t1 && j <= t2)
    {
        if(a[i][0] < b[j][0] ||
          (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else if(b[j][0] < a[i][0] ||
               (b[j][0] == a[i][0] && b[j][1] < a[i][1]))
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
        else
        {
            int sum = a[i][2] + b[j][2];
            if(sum != 0)
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    while(i <= t1)
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }

    while(j <= t2)
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][2] = k - 1;
}

int main()
{
    int m, n;
    int A[10][10], B[10][10];
    int SA[100][3], SB[100][3], SC[100][3];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    /* Matrix A input */
    printf("\nEnter Matrix A:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    /* Matrix B input */
    printf("\nEnter Matrix B:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    /* Convert to sparse */
    convertToSparse(m, n, A, SA);
    convertToSparse(m, n, B, SB);

    printf("\nSparse Matrix A:\n");
    printSparse(SA);

    printf("\nSparse Matrix B:\n");
    printSparse(SB);

    /* Addition */
    addSparse(SA, SB, SC);

    printf("\nResultant Sparse Matrix After Addition:\n");
    printSparse(SC);

    return 0;
}
