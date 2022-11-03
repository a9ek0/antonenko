#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main(void)
{
    int **a;
    int *m, n, last, row , col;


    printf("Enter number of elements in side of the kube matrix: ");
    check_more_0(&n);
    row = n;
    col = n;


    a = allocate_memory_2d(n);
    m = allocate_memory_1d(n);


    fill_2d_array(a, m, row, col);


    matrix_output(a, m, n);


    printf("\n\n");
    last = a[n - 1][n - 1];


    for (int j = -1, q = n - 1; j < q; q--)
    {
        for (int i = 0, v = n - 1; i < v; v--)
        {
            a[v][q] = a[v - 1][q];
        }
        if (q - 1 >= 0)
        {
            a[0][q] = a[n - 1][q - 1];
            continue;
        }
    }


    a[0][0] = last;


    matrix_output(a, m, n);


    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(m);


    return 0;
}