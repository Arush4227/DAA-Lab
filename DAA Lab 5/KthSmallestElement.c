#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

int quickSelect(int arr[], int low, int high, int k)
{
    while (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
        {
            return arr[pivotIndex];
        }
        else if (k < pivotIndex)
        {
            high = pivotIndex - 1;
        }
        else
        {
            low = pivotIndex + 1;
        }
    }

    return -1;
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 1 || k > n)
    {
        printf("Invalid value of k\n");
        return 0;
    }

    // k-th smallest corresponds to index k-1
    int answer = quickSelect(arr, 0, n - 1, k - 1);

    printf("%dth smallest element = %d\n", k, answer);

    return 0;
}