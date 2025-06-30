#include <stdio.h>

void repeatChar(const int numberOfTimes, const char repeatChar) {
    if (numberOfTimes <= 0)
        return;

    int index = {};

startOfLoop:
    printf("%c", repeatChar);
    ++index;
    if (index < numberOfTimes)
        goto startOfLoop;
}

static const char SYMBOL = '*';
static const char SPACE = ' ';

int main() {
    int current = 1;
    int goal;
    printf("Enter a number for the figure: ");
    scanf("%d", &goal);

startOfLoop:
    if (current == 1) { // Draw a single symbol
        repeatChar(goal / 2 - !(goal & 1), SPACE);
        printf("%c", SYMBOL);
        repeatChar(goal / 2, SPACE);
        printf("\n");
        ++current;
        goto startOfLoop;

    } else if (current == goal / 2) { // Print the final line
        repeatChar(goal, SYMBOL);

    } else { // Print part of the body of the figure
        const int padding = goal / 2 - current;

        repeatChar(padding, SPACE);
        printf("%c", SYMBOL);
        repeatChar(goal - 2 - padding * 2, SPACE);
        printf("%c", SYMBOL);
        printf("\n");

        ++current;
        goto startOfLoop;
    }

    return 0;
}
