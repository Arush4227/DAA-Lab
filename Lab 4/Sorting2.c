#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int n, x;

    printf("Enter the size of both arrays: ");
    scanf("%d", &n);

    int S1[n], S2[n];

    printf("Enter elements of S1:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S1[i]);
    }

    printf("Enter elements of S2:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    mergeSort(S1, 0, n - 1);
    mergeSort(S2, 0, n - 1);

    printf("Sorted array S1: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", S1[i]);
    }
    printf("\n");
    printf("Sorted array S2: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", S2[i]);
    }

    printf("\n");
    printf("Enter x: ");
    scanf("%d", &x);

    int i = n - 1;
    int j = 0;

    int found = 0;

    while (i >= 0 && j < n)
    {
        int sum = S1[i] + S2[j];

        if (sum == x)
        {
            printf("Pair found: %d + %d = %d\n", S1[i], S2[j], x);
            found++;
            i--;
            j++;
        }
        else if (sum < x) // Need a larger sum
            j++;

        else // Need a smaller sum
            i--;
    }

    if (!found)
        printf("No pair found.\n");

    return 0;
}