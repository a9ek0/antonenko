#include "stdio.h"

int main() {
    int x, a, b, free_part, y;
    printf("Enter a and b value(a>b):");
    scanf("%d %d", &x, &y);
    if (x < y) {
        printf((" Wrong input"));
        return 0;
    }
    for (a = x; b < a; b = b + y);
    free_part = a - b;
    if (free_part == 0)
        printf("Free part = %d", free_part);
    else
        printf("Free part = %d", free_part + y);
    return 0;
}