#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    FILE *fp;
    int n;

    // Open file for reading
    fp = fopen("QuickSortfile.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read number of elements
    fscanf(fp, "%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    // Read elements from file
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    printf("Elements before sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Quick Sort
    quickSort(arr, 0, n - 1);

    printf("\n\nElements after sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}