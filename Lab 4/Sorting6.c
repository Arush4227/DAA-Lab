#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int position;
    int type;   // +1 = start, -1 = end
} Event;

int compare(const void *a, const void *b)
{
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->position != e2->position)
        return e1->position - e2->position;

    return e2->type - e1->type; // If positions are same, start (+1) comes before end (-1)
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Event events[2 * n];

    for (int i = 0; i < n; i++)
    {
        int l, r;

        printf("Enter interval %d: ", i + 1);
        scanf("%d %d", &l, &r);

        events[2 * i].position = l; // Starting point
        events[2 * i].type = 1;

        events[2 * i + 1].position = r; // Ending point
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compare);

    int current = 0;
    int maximum = 0;
    int point = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        current += events[i].type;

        if (current > maximum)
        {
            maximum = current;
            point = events[i].position;
        }
    }

    printf("\nPoint with maximum overlap: %d\n", point);
    printf("Maximum number of intervals: %d\n", maximum);

    return 0;
}