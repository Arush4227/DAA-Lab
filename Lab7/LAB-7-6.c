#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type;
} Event;

int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->year != e2->year)
        return e1->year - e2->year;
    return e1->type - e2->type;
}

int bestTimeToBeAlive(int births[], int deaths[], int n, int *best_year) {
    Event *events = malloc(2 * n * sizeof(Event));
    for (int i = 0; i < n; i++) {
        events[2 * i].year = births[i];
        events[2 * i].type = 1;
        events[2 * i + 1].year = deaths[i];
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int max_alive = 0, current_alive = 0;
    *best_year = events[0].year;

    for (int i = 0; i < 2 * n; i++) {
        current_alive += events[i].type;
        if (current_alive > max_alive) {
            max_alive = current_alive;
            *best_year = events[i].year;
        }
    }

    free(events);
    return max_alive;
}

int main()
{
    int n;

    printf("Enter the number of scientists: ");
    scanf("%d", &n);

    int *births = malloc(n * sizeof(int));
    int *deaths = malloc(n * sizeof(int));

    if (births == NULL || deaths == NULL)
    {
        printf("Memory allocation failed.\n");
        free(births);
        free(deaths);
        return 1;
    }

    printf("\nEnter birth year and death year for each scientist:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Scientist %d birth year: ", i + 1);
        scanf("%d", &births[i]);

        printf("Scientist %d death year: ", i + 1);
        scanf("%d", &deaths[i]);

        if (deaths[i] < births[i])
        {
            printf("Invalid input: death year cannot be earlier than birth year.\n");
            free(births);
            free(deaths);
            return 1;
        }
    }

    int best_year;
    int max_scientists = bestTimeToBeAlive(births, deaths, n, &best_year);

    printf("\n========== Result ==========\n");
    printf("Best year to be alive       : %d\n", best_year);
    printf("Maximum scientists alive   : %d\n", max_scientists);

    free(births);
    free(deaths);

    return 0;
}