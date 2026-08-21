#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n];
    Interval result[n];

    printf("Enter the intervals:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(Interval), compare); // Sort intervals by starting point

    int count = 0;

    // Start with the first interval
    result[count] = intervals[0];
    count++;

    for (int i = 1; i < n; i++)
    {
        // Check if current interval overlaps with the last result interval
        if (intervals[i].start <= result[count - 1].end) 
        {
            if (intervals[i].end > result[count - 1].end) // Merge the intervals
            {
                result[count - 1].end = intervals[i].end;
            }
        }
        else // No overlap, add a new interval
        {
            result[count] = intervals[i];
            count++;
        }
    }

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++)
    {
        printf("(%d, %d)\n", result[i].start, result[i].end);
    }

    return 0;
}