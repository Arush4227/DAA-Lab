#include <stdio.h>

void findTarget(int n) {
    printf("Shooting sequence for n=%d: ", n);
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter total number of shots: ");
    scanf("%d", &n);
    findTarget(n);
    printf("Total shots: %d\n", 2 * (n - 2));

    return 0;
}