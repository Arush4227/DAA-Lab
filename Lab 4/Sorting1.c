#include <stdio.h>
#include <stdlib.h>

struct Item{
    int number;
    int colour;   // Colour Code - 0 = Red, 1 = Blue, 2 = Yellow
};

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item red[n], blue[n], yellow[n];

    int redCount = 0;
    int blueCount = 0;
    int yellowCount = 0;

    printf("Enter %d items (number colour):\n", n);

    for (int i = 0; i < n; i++) {
        int number;
        char colour;

        scanf("%d %c", &number, &colour);

        if (colour == 'R') {
            red[redCount].number = number;
            red[redCount].colour = 0;
            redCount++;
        }
        else if (colour == 'B') {
            blue[blueCount].number = number;
            blue[blueCount].colour = 1;
            blueCount++;
        }
        else if (colour == 'Y') {
            yellow[yellowCount].number = number;
            yellow[yellowCount].colour = 2;
            yellowCount++;
        }
    }

    printf("\nItems sorted by colour:\n");

    for (int i = 0; i < redCount; i++) {
        printf("%d R\n", red[i].number);
    }

    for (int i = 0; i < blueCount; i++) {
        printf("%d B\n", blue[i].number);
    }

    for (int i = 0; i < yellowCount; i++) {
        printf("%d Y\n", yellow[i].number);
    }

    return 0;
}