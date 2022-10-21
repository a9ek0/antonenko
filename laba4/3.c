#include "stdio.h"
#include "mass_functions.h"

int main()
{
    int a[100][100], columns, lines, sum = 0;
    columns = columns_1();
    lines = lines_1();
    array_input_2d(a, columns, lines);
    for (int j = 0, k = 0, l = columns - 1; j < l; --l, lines--, k++)
    {
        for (int i = k; i < lines; i++)
        {
            sum += a[i][l];
        }
    }
    printf("Sum of the elements situated in the second are is: %d", sum);
    return 0;
}

