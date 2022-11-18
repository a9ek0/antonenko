#include <time.h>
#include <stdio.h>
#include "arrays.h"

int main(void)
{
    int *a = NULL, *b = NULL;
    int n, n_2, min_f, min_l, chose;

    printf("Enter number of elements");
    check_more_0(&n);

    a = allocate_memory_1d(n);
    b = allocate_memory_1d(n);

    fill_array(a, n);

    output_1d_array(a, n);

    min_last(a, n, &min_l);
    min_first(a, n, &min_f);

    if (min_l == min_f)
        printf("\nNo identical minimum elements\n");

    for (int i = min_f + 1, k = 0; i < min_l; i++, k++)
    {
        if(a[i] % 2 != 0)
            b[k] = a[i];
        else
            k--;
        n_2 = k + 1;
    }

    free(a);

    reallocate_memory_1d(b, n_2);

    printf("\nChose sorting(1 - Insertion sort; 2 - Bubble sort)\n");
    scanf_s("%d", &chose);
    switch (chose)
    {
        case 1:
            insertion_sort(b, -1, n_2);
        case 2:
            bubble_sort(b, n_2);
    }
    //insertion_sort(b, -1, n_2);
    //bubble_sort(b, n_2);

    output_1d_array(b, n_2);

    free(b);

    return 0;
}
