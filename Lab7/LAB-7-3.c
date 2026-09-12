#include <stdio.h>
#include <math.h>
#include <limits.h>

int revesPuzzle(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int k = 1; k < i; k++) {
            int moves = 2 * dp[k] + (int)pow(2, i - k) - 1;
            if (moves < dp[i]) {
                dp[i] = moves;
            }
        }
    }
    return dp[n];
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    int moves = revesPuzzle(n);

    printf("\nNumber of disks : %d\n", n);
    printf("Minimum moves   : %d\n", moves);

    return 0;
}