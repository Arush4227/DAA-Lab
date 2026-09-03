#include <stdio.h>
#include <math.h>

#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// (i) Find maximum element
int findMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// (ii) Find first and second largest elements
void findTwoLargest(int arr[], int n)
{
    int largest, second;

    if (arr[0] > arr[1])
    {
        largest = arr[0];
        second = arr[1];
    }
    else
    {
        largest = arr[1];
        second = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second)
        {
            second = arr[i];
        }
    }

    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", second);
}

// (iii) Find mean
double findMean(int arr[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum / n;
}

// (iv) Find median
void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

double findMedian(int arr[], int n)
{
    sortArray(arr, n);

    if (n % 2 == 1)
        return arr[n / 2];

    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}

// (v) Find standard deviation
double findStandardDeviation(int arr[], int n)
{
    double mean = findMean(arr, n);
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }

    return sqrt(sum / n);
}

// (vi) Find mode
int findMode(int arr[], int n)
{
    int mode = arr[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

// (vii) Remove all duplicates
int removeDuplicates(int arr[], int n)
{
    int newSize = 0;

    for (int i = 0; i < n; i++)
    {
        int duplicate = 0;
        for (int j = 0; j < newSize; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate)
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize;
}

// (viii) Reverse the array
void reverseArray(int arr[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
}

// (ix) Partition around pivot
void partitionArray(int arr[], int n, int pivot)
{
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    // Print the partitioned array
    printf("Elements less than pivot: ");

    for (int k = 0; k < i; k++)
        printf("%d ", arr[k]);

    printf("\nElements greater than or equal to pivot: ");

    for (int k = i; k < n; k++)
        printf("%d ", arr[k]);

    printf("\n");
}

int main()
{
    int arr[MAX];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    
    printf("\nMaximum = %d\n", findMax(arr, n));    // (i)

    findTwoLargest(arr, n);    // (ii)

    printf("Mean = %.2lf\n", findMean(arr, n));    // (iii)

    int temp[MAX];    // (iv)

    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    printf("Median = %.2lf\n", findMedian(temp, n));

    printf("Standard Deviation = %.2lf\n",    // (v)
           findStandardDeviation(arr, n));

    printf("Mode = %d\n", findMode(arr, n));    // (vi)

    for (int i = 0; i < n; i++)     // (vii)
        temp[i] = arr[i];

    int newSize = removeDuplicates(temp, n);

    printf("After removing duplicates: ");

    for (int i = 0; i < newSize; i++)
        printf("%d ", temp[i]);

    printf("\n");

    for (int i = 0; i < n; i++)    // (viii)
        temp[i] = arr[i];

    reverseArray(temp, n);

    printf("Reversed array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", temp[i]);

    printf("\n");

    // (ix)
    int pivot;

    printf("Enter pivot: ");
    scanf("%d", &pivot);

    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    partitionArray(temp, n, pivot);

    return 0;
}