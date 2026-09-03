#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify the subtree rooted at index i */
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

/* Heap Sort */
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current largest to the end
        swap(&arr[0], &arr[i]);

        // Restore heap property
        heapify(arr, i, 0);
    }
}

int main()
{
    FILE *fp;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Generate random numbers */
    srand(time(NULL));

    /* Open file for writing */
    fp = fopen("numbers.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    /* Generate and store random numbers in file */
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    /* Display generated numbers */
    printf("\nRandom numbers stored in file:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    /* Open file for reading */
    fp = fopen("HeapSortFile.txt", "r");

    if (fp == NULL)
    {
        printf("\nError opening file.\n");
        free(arr);
        return 1;
    }

    /* Read numbers from file */
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    /* Apply Heap Sort */
    heapSort(arr, n);

    /* Display sorted numbers */
    printf("\n\nNumbers after Heap Sort:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}