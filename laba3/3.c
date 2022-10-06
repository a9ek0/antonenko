#include "stdio.h"
#include "mass_functions.h"

int main()
{
    int a[100], b[100], n = 0, k;
    printf("Filling the first array\n");
    array_input(a, 10);
    printf("Filling the second array\n");
    array_input(b, 10);
    k = min_num_miss_in_second (a, b, n);
    printf("Minimum element %d", a[k]);
}
