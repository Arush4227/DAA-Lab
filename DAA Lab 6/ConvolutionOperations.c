#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1.0)

void swap(complex double *a, complex double *b)
{
    complex double temp = *a;
    *a = *b;
    *b = temp;
}

// FFT
// invert = 0 -> FFT
// invert = 1 -> Inverse FFT

void fft(complex double a[], int n, int invert)
{
    // Bit-reversal permutation
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;

        while (j & bit)
        {
            j ^= bit;
            bit >>= 1;
        }

        j ^= bit;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    // Divide and conquer
    for (int len = 2; len <= n; len <<= 1)
    {
        double angle = 2 * PI / len;

        if (invert)
            angle = -angle;

        complex double wlen = cos(angle) + I * sin(angle);

        for (int i = 0; i < n; i += len)
        {
            complex double w = 1;

            for (int j = 0; j < len / 2; j++)
            {
                complex double u = a[i + j];
                complex double v = a[i + j + len / 2] * w;

                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;

                w *= wlen;
            }
        }
    }

    if (invert)
    {
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}

void convolution(double A[], int m,
                 double B[], int n,
                 double C[])
{
    int size = 1;

    while (size < m + n - 1)
        size *= 2;

    complex double *fa =
        calloc(size, sizeof(complex double));

    complex double *fb =
        calloc(size, sizeof(complex double));

    for (int i = 0; i < m; i++)
        fa[i] = A[i];

    for (int i = 0; i < n; i++)
        fb[i] = B[i];

    fft(fa, size, 0);
    fft(fb, size, 0);

    for (int i = 0; i < size; i++)
        fa[i] *= fb[i];

    fft(fa, size, 1);

    for (int i = 0; i < m + n - 1; i++)
        C[i] = creal(fa[i]);

    free(fa);
    free(fb);
}

int main()
{
    int m, n;

    printf("Enter size of A: ");
    scanf("%d", &m);

    double A[m];

    printf("Enter elements of A:\n");

    for (int i = 0; i < m; i++)
        scanf("%lf", &A[i]);

    printf("Enter size of B: ");
    scanf("%d", &n);

    double B[n];

    printf("Enter elements of B:\n");

    for (int i = 0; i < n; i++)
        scanf("%lf", &B[i]);

    int resultSize = m + n - 1;

    double C[resultSize];

    convolution(A, m, B, n, C);

    printf("\nConvolution:\n");

    for (int i = 0; i < resultSize; i++)
        printf("%.2lf ", C[i]);

    printf("\n");

    return 0;
}