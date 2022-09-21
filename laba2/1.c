#include "stdio.h"

int main()
{
    float day;
    for (float money = 10000;money < 20001;day++)
    {
        money = money + (money * 0.0000821917808);
    }
    printf ("After %1.2f days", day);
    return 0;
}