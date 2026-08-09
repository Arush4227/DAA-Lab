#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int fairHeads = 0, biasedHeads = 0;

    printf("Enter the number of coin tosses: ");
    scanf("%d", &n);

    FILE *fp = fopen("coin_data.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Toss Fair_Probability Biased_Probability\n");

    srand(time(NULL));

    for(i = 1; i <= n; i++)
    {
        // Fair coin
        if(rand() % 2 == 0)
        {
            fairHeads++;
        }

        // Biased coin (70% heads)
        double r = (double)rand() / RAND_MAX;
        if(r < 0.7)
        {
            biasedHeads++;
        }

        fprintf(fp, "%d %.6f %.6f\n",
                i,
                (double)fairHeads / i,
                (double)biasedHeads / i);
    }

    fclose(fp);

    printf("Final Results:\n");
    printf("Fair Coin Probability = %.6f\n", (double)fairHeads / n);
    printf("Biased Coin Probability = %.6f\n", (double)biasedHeads / n);

    printf("\nData has been saved to coin_data.txt\n");

    return 0;
}