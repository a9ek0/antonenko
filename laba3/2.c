#include "stdio.h"
#include "mass_functions.h"

int main()
{
    int a[100], n, k;
    printf("Enter number of elements ");
    scanf("%d", &n);
    n = zeros_after_even(a,n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
