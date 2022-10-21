#include "mass_functions.h"

int array_input_2d(int mass[100][100], int columns, int lines)
{
    int o;
    srand(time(NULL));
    printf("Do you want to fill an array with random values?(1 - Yes/2 - No)\n");
    while (scanf("%d", &o) == 0 || o < 1 || o > 2 || getchar() !='\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
    if (o == 1)
    {
        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                mass[i][j] = -100 + rand() % (100 + 100 + 1) ;
                printf("Element number %d,%d: %d\n", i, j, mass[i][j]);
            }
        }
    }
    else
    {
        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                printf("Enter %d,%d element \n", i, j);
                while (scanf("%d", &mass[i][j]) != 1 || getchar() != '\n')
                {
                    printf("Wrong input\n");
                    rewind(stdin);
                }
            }
        }
    }
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%4d   ", mass[i][j]);
        }
        printf("\n\n");
    }
}

int min_num_miss_in_second (int x[], int y[], int z)
{
    int l;
    for (int i = 0, z = 0; i < 9; i++)
    {
        if (x[z] > x[i + 1])
            z = i + 1;
        l = z;
        for (int i = 0; i < 11; i++)
        {
            if (y[i] == x[l])
            {
                if (x[l] == 0)
                {
                    x[l] = 1;
                }
                else
                {
                    x[l] = 0;
                }
                for (int i = 0, z = 0; i < 9; i++)
                {
                    if (x[z] > x[i + 1])
                        z = i + 1;
                    l = z;
                }
            }
        }
    }
    return l;
}

int array_input_1d(int mass_name[], int num_of_elements)
{
    printf("Enter the number of array elements: ");
    while (scanf("%d", &num_of_elements) != 1 || getchar() !='\n' || num_of_elements > 100 || num_of_elements < 0 )
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
    int o, l = 0;
    srand(time(NULL));
    printf("Do you want to fill an array with random values?(1 - Yes/2 - No)\n");
        while (scanf("%d", &o) == 0 || o < 1 || o > 2 || getchar() !='\n')
        {
            printf("Wrong input");
            rewind(stdin);
        }
    if (o == 1)
    {
        for (int i = 0; i < num_of_elements; i++)
        {
            mass_name[i] = rand() % num_of_elements * 1.5 - num_of_elements;
            printf("Element number %d: %d\n", i + 1, mass_name[i]);
        }

    }
    else if (o == 2)
    {
        for (int i = 0; i < num_of_elements; i++)
        {
            printf("Enter element number %d\n", i + 1);
            if (scanf("%d", &mass_name[i]) != 1)
            {
                printf("Wrong input.\n");
                i = i - 1;
                rewind(stdin);
            }
        }
    }
    return num_of_elements;
}

int first_zero_in_mass(int mass[],int num_of_elem)
{
    int zero = num_of_elem;
    for (int i = 0, j = num_of_elem; j > i; j--)
    {
        if(mass[j] == 0)
            zero = j;
    }
    return zero;

}

int last_zero_in_mass(int mass[],int num_of_elem)
{
    int zero;
    for(int i = 0, j = num_of_elem;i < j;i++)
    {
        if (mass[i] == 0)
            zero = i;
    }
    return zero;
}

int zeros_after_even(int mass_name[], int num_of_elements)
{
    printf("Enter the number of array elements: ");
    while (scanf("%d", &num_of_elements) != 1 || getchar() !='\n' || num_of_elements > 100 || num_of_elements < 0 )
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
    int o, l = 0;
    srand(time(NULL));
    printf("Do you want to fill an array with random values?(1 - Yes/2 - No)\n");
    while (scanf("%d", &o) == 0 || o < 1 || o > 2 || getchar() !='\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
    if (o == 1)
    {
        for (int i = 0; i < num_of_elements; i++)
        {
            mass_name[i] = rand() % num_of_elements * 1.5 - num_of_elements;
            printf("Element number %d: %d\n", i + 1, mass_name[i]);
            if (mass_name[i] % 2 == 0)
            {
                mass_name[i + 1] = 0;
                num_of_elements++;
                i++;
            }
        }

    }
    else if (o == 2)
    {
        for (int i = 0, j = 0; i < num_of_elements; i++, j++)
        {
            printf("Enter element number %d\n", j + 1);
            if (scanf("%d", &mass_name[i]) != 1)
            {
                printf("Wrong input.\nTry again\n");
                i = i - 1;
                rewind(stdin);
            }
            if (mass_name[i] % 2 == 0)
            {
                mass_name[i + 1] = 0;
                num_of_elements++;
                i++;
            }
        }
    }
    return num_of_elements;
}

int columns_1 ()
{
    int columns;
    printf("Enter number of columns \n");
    while (scanf("%d", &columns) != 1 || getchar() != '\n' || columns > 100 || columns < 0)
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
    return columns;
}

int lines_1 ()
{
    int lines;
    printf("Enter number of lines \n");
    while (scanf("%d", &lines) != 1 || getchar() != '\n' || lines > 100 || lines < 0)
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
    return lines;
}

int saddle_points_Lm_Jp(int lines, int columns, int main_mass[100][100], int count)
{
    int min, mi, max, ma, c[100], b[100], d[100][100], e[100][100];
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            d[i][j] = 0;
            e[i][j] = 0;
        }
    }
    for (int i = 0; i < lines; i++)
    {
        min = main_mass[i][0];
        for (int j = 0; j < columns; j++)
        {
            if (min == main_mass[i][j])
            {
                min = main_mass[i][j];
                mi = j;
                d[i][mi] = min;
            }
            if (min < main_mass[i][j])
            {
                min = main_mass[i][j];
                mi = j;
            }
        }
        c[i] = mi;
        d[i][mi] = min;
    }
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(d[i][c[i]] == d[i][j])
                continue;
            if (d[i][c[i]] > d[i][j])
                d[i][j] =0;
        }
    }
    for (int j = 0; j < columns; j++)
    {
        ma = 0;
        max = main_mass[0][j];
        for (int i = 0; i < lines; i++)
        {
            if (max == main_mass[i][j])
            {
                ma = i;
                max = main_mass[i][j];
                e[ma][j] = max;
            }
            if (max > main_mass[i][j])
            {
                ma = i;
                max = main_mass[i][j];
            }
        }
        b[j] = ma;
        e[ma][j] = max;
    }
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < lines; i++)
        {
            if (e[b[j]][j] == e[i][j])
                continue;
            if (e[b[j]][j] < e[i][j])
                e[i][j] =0;
        }
    }
    for (int i = 0; i < lines; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            if (e[i][j] == d[i][j] & e[i][j] != 0 & d[i][j] != 0)
            {
                printf("Saddle point(l - max;j - min) %d %d\n", i, j);
                count++;
            }
        }
    }
    return count;
}

int saddle_points_Lp_Jm(int lines, int columns, int main_mass[100][100], int count)
{
    int min, mi, max, ma, c[100], b[100], d[100][100], e[100][100];
    for (int i = 0; i < lines; i++)
    {
        min = main_mass[i][0];
        for (int j = 0; j < columns; j++)
        {
            if (min == main_mass[i][j])
            {
                min = main_mass[i][j];
                mi = j;
                d[i][mi] = min;
            }
            if (min > main_mass[i][j])
            {
                min = main_mass[i][j];
                mi = j;
            }
        }
        c[i] = mi;
        d[i][mi] = min;
    }
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(d[i][c[i]] == d[i][j])
                continue;
            if (d[i][c[i]] < d[i][j])
                d[i][j] =0;
        }
    }
    for (int j = 0; j < columns; j++)
    {
        ma = 0;
        max = main_mass[0][j];
        for (int i = 0; i < lines; i++)
        {
            if (max == main_mass[i][j])
            {
                ma = i;
                max = main_mass[i][j];
                e[ma][j] = max;
            }
            if (max < main_mass[i][j])
            {
                ma = i;
                max = main_mass[i][j];
            }
        }
        b[j] = ma;
        e[ma][j] = max;
    }
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < lines; i++)
        {
            if (e[b[j]][j] == e[i][j])
                continue;
            if (e[b[j]][j] > e[i][j])
                e[i][j] =0;
        }
    }
    for (int i = 0; i < lines; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            if (e[i][j] == d[i][j] & e[i][j] != 0 & d[i][j] != 0)
            {
                printf("Saddle point(l - min;j - max) %d %d\n", i, j);
                count++;
            }
        }
    }
    return count;
}