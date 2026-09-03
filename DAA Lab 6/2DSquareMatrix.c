#include <stdio.h>
#include <math.h>

#define MAX 100

void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int isZeroMatrix(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
                return 0;
        }
    }

    return 1;
}

int isSymmetric(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
                return 0;
        }
    }

    return 1;
}

double determinant(int A[MAX][MAX], int n)
{
    double temp[MAX][MAX];

    // Copy matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = A[i][j];
        }
    }

    double det = 1;

    for (int i = 0; i < n; i++)
    {
        // Find pivot
        int pivot = i;

        for (int j = i + 1; j < n; j++)
        {
            if (fabs(temp[j][i]) > fabs(temp[pivot][i]))
                pivot = j;
        }

        // If pivot is zero, determinant is zero
        if (fabs(temp[pivot][i]) < 1e-9)
            return 0;

        // Swap rows
        if (pivot != i)
        {
            for (int j = 0; j < n; j++)
            {
                double t = temp[i][j];
                temp[i][j] = temp[pivot][j];
                temp[pivot][j] = t;
            }

            det = -det;
        }

        det *= temp[i][i];

        // Eliminate below
        for (int j = i + 1; j < n; j++)
        {
            double factor = temp[j][i] / temp[i][i];

            for (int k = i; k < n; k++)
            {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    return det;
}

void transpose(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void printMatrix(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int n;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    printf("Enter size of matrices: ");
    scanf("%d", &n);

    printf("\nEnter Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    addMatrix(A, B, C, n);

    printf("\nMatrix Addition:\n");
    printMatrix(C, n);

    multiplyMatrix(A, B, C, n);

    printf("\nMatrix Multiplication:\n");
    printMatrix(C, n);

    if (isZeroMatrix(A, n))
        printf("\nA is a zero matrix.\n");
    else
        printf("\nA is not a zero matrix.\n");

    if (isSymmetric(A, n))
        printf("A is a symmetric matrix.\n");
    else
        printf("A is not a symmetric matrix.\n");

    printf("Determinant of A = %.2lf\n",
           determinant(A, n));

    transpose(A, n);

    printf("\nTranspose of A:\n");
    printMatrix(A, n);

    return 0;
}