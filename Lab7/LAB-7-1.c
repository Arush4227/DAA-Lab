#include <stdio.h>

int min_moves(int n) {
    return (n * (n + 1)) / 6;
}

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Rows: %d\n", n);
    printf("Minimum moves to invert: %d\n", min_moves(n));

    return 0;
}