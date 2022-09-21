#include "stdio.h"

int main ()
{
    int x_coord, y_coord, result;
    printf("Enter X coordinate:");
    if(scanf("%d", &x_coord) != 1)
    {
        printf("Wrong input");
        return 0;
    }
    printf("Enter Y coordinate:");
    if(scanf("%d", &y_coord) != 1)
    {
        printf("Wrong input");
        return 0;
    }
    result = x_coord * x_coord + y_coord * y_coord;
    if (result == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}