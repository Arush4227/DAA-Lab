#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return 1;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return 0;
}

int findKSum(int arr[], int n, int k, int target, int start, int count, int sum)
{
    // We have selected k-1 elements
    if (count == k - 1)
    {
        int required = target - sum;

        return binarySearch(arr, n, required);
    }

    for (int i = start; i < n; i++)
    {
        if (findKSum(arr, n, k, target,
                     i + 1, count + 1, sum + arr[i]))
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n, k, T;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int S[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%d", &T);

    // Sort the set
    qsort(S, n, sizeof(int), compare);

    if (k < 1 || k > n)
    {
        printf("Invalid value of k.\n");
        return 0;
    }

    if (findKSum(S, n, k, T, 0, 0, 0))
        printf("YES: %d elements can add up to %d.\n", k, T);
    else
        printf("NO: No combination of %d elements adds up to %d.\n", k, T);

    return 0;
}