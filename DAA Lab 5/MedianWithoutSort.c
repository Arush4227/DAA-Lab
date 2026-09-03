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
            return arr[pivotIndex];

        else if (k < pivotIndex)
            high = pivotIndex - 1;

        else
            low = pivotIndex + 1;
    }

    return -1;
}

double findMedian(int arr[], int n)
{
    if (n % 2 == 1)
    {
        // Middle element
        return quickSelect(arr, 0, n - 1, n / 2);
    }
    else
    {
        // Two middle elements
        int left = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int right = quickSelect(arr, 0, n - 1, n / 2);

        return (left + right) / 2.0;
    }
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Median = %.2f\n", findMedian(arr, n));

    return 0;
}