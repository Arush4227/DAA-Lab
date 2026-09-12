#include <stdio.h>

int moves = 0;

void turnOn(int n);
void turnOff(int n);

void turnOff(int n) {
    if (n == 0) return;
    if (n == 1) {
        moves++;
        return;
    }
    turnOff(n - 2);
    moves++;
    turnOn(n - 2);
    turnOff(n - 1);
}

void turnOn(int n) {
    if (n == 0) return;
    if (n == 1) {
        moves++;
        return;
    }
    turnOn(n - 1);
    turnOff(n - 2);
    moves++;
    turnOn(n - 2);
}

int main() {
    int n;
    printf("Enter number of switches: ");
    scanf("%d", &n);
    turnOff(n);
    printf("Number of switches: %d\n", n);
    printf("Minimum moves to turn all off: %d\n", moves);

    return 0;
}