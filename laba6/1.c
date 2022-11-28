#include <time.h>
#include <stdio.h>
#include "arrays.h"

int main(void) {
    int *a = NULL, *b = NULL;
    int n, n_2, min_f, min_l, chose, roflan;

    printf("\nChose sorting(1 - Insertion sort; 2 - Bubble sort;)\n");
    check(&chose);

    printf("Enter number of elements");
    check_more_0(&n);

    a = allocate_memory_1d(n);
    b = allocate_memory_1d(n);

    //fill_array(a, n);
    //output_1d_array(a, n);
    printf("sorted array - 1; array in reverse order - 2; default input - 3;");
    check(&roflan);
    switch (roflan)
    {
    //ROFLAN DLA NORM MASIVA
    case 1:
    {
        for (int i = 0, k = n; i < k;)
        {
            i++;
            a[i] = i;
        }
        a[0] = -1;
        a[n - 1] = -1;
        //output_1d_array(a, n);
        break;
    }
    //ROFLAN DLA OBRATNOGO PORADKA
    case 2:
    {
        for (int i = 0,z = 0, k = n; i < k; k--, z++)
        {
            a[k] = z;
        }
        a[0] = -1;
        a[n - 1] = -1;
        //output_1d_array(a, n);
        break;
    }
        case 3:
            fill_array(a, n);
    }

    min_last(a, n, &min_l);
    min_first(a, n, &min_f);

    if (min_l == min_f)
    {
        printf("\nNo identical minimum elements\n");
        return 0;
    }

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

    switch (chose)
    {
        case 1:
            insertion_sort(b, -1, n_2);
            break;
        case 2:
            bubble_sort(b, n_2);
    }

    //output_1d_array(b, n_2);

    free(b);

    return 0;
}
