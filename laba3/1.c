#include "stdio.h"
#include "mass_functions.h"

int main()
{
    int a[100], n, product = 1, first_zero = 0, last_zero = 0, sum = 0;
    n = array_input(a,n);
    for(int i = 0;i < n;i = i + 2)
        product = product * a[i];
    last_zero = last_zero_in_mass(a, n);
    first_zero = first_zero_in_mass(a, n);
    if (last_zero == n || last_zero > n || first_zero == n || first_zero == last_zero)
        printf("One or no zeros\n");
    else{
        for (int i = first_zero, j = last_zero; i < j; i++)
        {
            sum = sum + a[i];
        }
        printf("The sum of the array elements located between the first and last zero elements: %d\n", sum);
        }
    printf("Product of array elements with even numbers: %d\n", product);
    return 0;
}
