#include "stdio.h"

int split_number(int);
int main()
{
    int i,target;
    int arr[11] = {11,13,17, 19, 23, 29, 31 };
    for (i = 0; i < 12; i++)
    {
        if (split_number(arr[i]) == 1)
        {
            printf("%d\n", arr[i]*arr[i]);
        }
    }
    return 0;
}
int split_number(int i)
{
    int p;
    p = i * i;
    int a, b, c;
    a = (p / 100) % 10;
    b = (p % 100) / 10;
    c = p % 10;
    if (a < b && b < c)
        return 1;
    else
        return 0;

}