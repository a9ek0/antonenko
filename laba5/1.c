#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main(void)
{
    int *a;
    int n, l, check = 0;
    printf("Enter number of elements: \n");
    check_more_0(&n);
    a = allocate_memory_1d(n);
    fill_1d_array(n, a);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            l = a[i];
            i--;
            check++;
        delete_element_1d(a, l, &n);
        a = reallocate_memory_1d(a, n);
        }
    }
    output_1d_array(a, n);
    free(a);
    if (check == 0)
    {
        printf("\n\n");
        printf("No negative elements");
    }
    return 0;
}

