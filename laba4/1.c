#include "stdio.h"
#include "mass_functions.h"

int main()
{
    int a[100][100], columns, lines, count = 0;
    columns = columns_1();
    lines = lines_1();
    array_input_2d(a, columns, lines);
    count = saddle_points_Lp_Jm(lines, columns, a, count);
    if (count == 0)
        printf("No saddle points(l - max;j - min)\n");
    count = 0;
    count = saddle_points_Lm_Jp(lines, columns,a, count);
    if (count == 0)
        printf("No saddle points(l - min;j - max)\n");
    return 0;
}


