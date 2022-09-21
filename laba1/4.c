#include "stdio.h"
int main()
{
    int num_of_month;
    printf("Enter month number:");
    if(scanf("%d", &num_of_month) != 1)
    {
        printf("Wrong input");
        return 0;
    }
    switch (num_of_month)
    {
        case 1:
            printf("Winter");
            break;
        case 2:
            printf("Winter");
            break;
        case 3:
            printf("Spring");
            break;
        case 4:
            printf("Spring");
            break;
        case 5:
            printf("Spring");
            break;
        case 6:
            printf("Summer");
            break;
        case 7:
            printf("Summer");
            break;
        case 8:
            printf("Summer");
            break;
        case 9:
            printf("Fall");
            break;
        case 10:
            printf("Fall");
            break;
        case 11:
            printf("Fall");
            break;
        case 12:
            printf("Winter");
            break;
    }
    return 0;

}