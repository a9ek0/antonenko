#include <stdio.h>
#include "arrays.h"

int main(void) {
    int **a = NULL, *b, **sum_arr = NULL, **sum_array2 = NULL;
    int n, m, sum = 0;
    srand(time(NULL));

    printf("Enter number of rows");
    check_more_0(&n);
    printf("Enter number of columns");
    check_more_0(&m);

    sum_array2 = allocate_memory_2d(2);
    sum_arr = allocate_memory_2d(2);
    a = allocate_memory_2d(n);
    b = allocate_memory_1d(m);

    fill_array_2d(a, n, m, b);

    matrix_output(a, b, n);

    sum_numbers(sum_arr, a, n, m);
    copy(sum_arr, sum_array2, m, 2);

    quick_sort(sum_arr[1], 0, m - 1);

    ///////////////////////////////////////////////
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
        if(sum_arr[1][i] == sum_array2[1][j])
        {
            sum_arr[0][i] = sum_array2[0][j];
            break;
        }
        }
    }
    ///////////////////////////////////////////////
    print(sum_arr[0], m); //roflan dla vivoda nomerov

    indent();

    print(sum_arr[1], m); //roflan dla vivoda summi

    indent();

    switch_columns(a,sum_arr, n, m);

    indent();

    matrix_output(a, b, n);

    free_2d(a, n);
    free(sum_arr);
    free(sum_array2);
    return 0;
}

