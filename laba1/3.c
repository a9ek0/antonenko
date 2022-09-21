#include "stdio.h"

int main()
{
    int num1, num2, num3, count=0;
    printf("Enter 3 numbers:");
    if(scanf("%d", &num1) != 1 || scanf("%d", &num2) != 1 || scanf("%d", &num3) != 1)
    {
        printf("Wrong input");
        return 0;
    }
    if (num1 > 0)
        count++;
    if (num2 > 0)
        count++;
    if (num3 > 0)
        count++;
    printf("Number of positive numbers: %d", count);
    return 0;
}