#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main(void)
{
    int **a;
    int n, *m;


    printf("Enter number of rows: ");
    check_more_0(&n);


    a = allocate_memory_2d(n);
    m = allocate_memory_1d(n);


    for (int i = 0; i < n; i++)
    {
        a[i] = allocate_memory_1d(1);
        for (int j = 0, count = 1; j < count;j++, count++)
        {
            m[i] = count;
            a[i] = reallocate_memory_1d(a[i], m[i]);
            printf("a[%d][%d]= \n", i, j);
            scanf_s("%d", &a[i][j]);
            if(a[i][j] == 0)
                break;
        }
    }


    delete_min (a, m, n);


    matrix_output(a, m, n);


    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(m);


    return 0;
}