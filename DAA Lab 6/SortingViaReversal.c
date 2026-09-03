#include <stdio.h>
#include <stdlib.h>

long long totalCost = 0;
long long totalReversals = 0;

void reverseRange(int p[], int l, int r)
{
    if (l > r)
        return;

    int length = r - l + 1;

    totalCost += length;
    totalReversals++;

    while (l < r)
    {
        int temp = p[l];
        p[l] = p[r];
        p[r] = temp;

        l++;
        r--;
    }
}

void rotateBlocks(int p[], int a, int b, int c)
{
    if (a > b || b + 1 > c)
        return;

    reverseRange(p, a, b);
    reverseRange(p, b + 1, c);
    reverseRange(p, a, c);
}

int lowerBound(int p[], int left, int right, int x)
{
    int low = left;
    int high = right + 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (p[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

void mergeUsingReversals(int p[], int l, int m, int r)
{
    int i = l;

    //Skip elements already in correct relative position.
    while (i <= m && p[i] <= p[m + 1])
        i++;

    if (i > m)
        return;

    int j = m + 1;

    while (i <= m && j <= r)
    {
        //Find first element in right half
        //that is >= p[i].
        int k = lowerBound(p, j, r, p[i]);

        if (k > j)
        {
            rotateBlocks(p, i, j - 1, k - 1);

            //Number of elements moved from right
            //half to the left of p[i].
            int shift = k - j;

            i = i + shift + 1;
            m = m + shift;
            j = k;
        }
        else
        {
            //No right-half element is smaller
            //than p[i].
            i++;
            j = m + 1;
        }
    }
}
//Merge-sort using reversal-based merging.
void reversalMergeSort(int p[], int l, int r)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    reversalMergeSort(p, l, m);
    reversalMergeSort(p, m + 1, r);

    mergeUsingReversals(p, l, m, r);
}

//Simple O(n) reversal sorting algorithm
//for demonstrating Part 1.
void simpleReversalSort(int p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;

        for (int j = i; j < n; j++)        //Find value i+1
        {
            if (p[j] == i + 1)
            {
                pos = j;
                break;
            }
        }

        if (pos != i)   //Put i+1 at position i.
            reverseRange(p, i, pos);
    }
}

void printArray(int p[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    printf("\n");
}
/*
int isSorted(int p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i] != i + 1)
            return 0;
    }

    return 1;
}
*/

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));

    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the permutation:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\nOriginal permutation:\n");
    printArray(p, n);

    //Reset statistics.
    totalCost = 0;
    totalReversals = 0;

    //Sort using O(n log^2 n) cost algorithm.
    reversalMergeSort(p, 0, n - 1);

    printf("\nSorted permutation:\n");
    printArray(p, n);

    printf("\nNumber of reversals = %lld\n", totalReversals);
    printf("Total reversal cost = %lld\n", totalCost);
/*
    if (isSorted(p, n))
        printf("Verification: SORTED CORRECTLY\n");
    else
        printf("Verification: SORTING FAILED\n");
*/
    free(p);

    return 0;
}