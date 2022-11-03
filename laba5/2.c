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
    for(int i = 1, min; i < n;i += 2)
    {
        min = a[i][0];
        for (int j = 0; j < m[i] - 1; j++)
        {
            if(min > a[i][j])
                min = a[i][j];
        }
        delete_element_1d(a[i], min, &m[i]);
    }
    matrix_output(a, m, n);
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(m);
    return 0;
}