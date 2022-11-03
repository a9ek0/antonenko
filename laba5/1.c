#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main(void)
{
    int *a, *b;
    int n,count = 0;


    printf("Enter number of elements: \n");
    check_more_0(&n);


    a = allocate_memory_1d(n);
    b = allocate_memory_1d(n);


    fill_1d_array(n, a);


    for (int i = 0; i < n; ++i)
    {
        if(a[i] > 0 || a[i] == 0)
        {
            b[count] = a[i];
            count++;
        }
    }


    b = reallocate_memory_1d(b, count);
    free(a);


    for (int i = 0; i < count ; ++i)
        printf("Element number %d: %d\n", i, *(b + i));


    free(b);


    if (count - n == 0)
        printf("No negative elements\n");
    if(count == 0)
        printf("All elements negative");


    return 0;
}

