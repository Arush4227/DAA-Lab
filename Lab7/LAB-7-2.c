#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int superEggDrop(int E, int F)
{
    if (E <= 0 || F < 0)
        return -1;

    if (F == 0)
        return 0;

    int dp[E + 1][F + 1];

    for (int i = 1; i <= E; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= F; j++)
    {
        dp[1][j] = j;
    }

    for (int i = 2; i <= E; i++)
    {
        for (int j = 2; j <= F; j++)
        {
            dp[i][j] = INT_MAX;

            for (int x = 1; x <= j; x++)
            {
                int breakCase = dp[i - 1][x - 1];
                int noBreakCase = dp[i][j - x];

                int attempts = 1 + max(breakCase, noBreakCase);

                if (attempts < dp[i][j])
                {
                    dp[i][j] = attempts;
                }
            }
        }
    }

    return dp[E][F];
}

int main()
{
    int eggs, floors;

    printf("Enter number of eggs: ");
    scanf("%d", &eggs);

    printf("Enter number of floors: ");
    scanf("%d", &floors);

    int result = superEggDrop(eggs, floors);

    if (result == -1)
    {
        printf("Invalid input.\n");
    }
    else
    {
        printf("Eggs: %d, Floors: %d\n", eggs, floors);
        printf("Minimum number of droppings: %d\n", result);
    }

    return 0;
}