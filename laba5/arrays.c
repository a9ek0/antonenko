#include "arrays.h"

void check_more_0(int *value)
{
    while (scanf("%d", value) == 0 || *value < 0 || getchar() !='\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void check(int *value)
{
    while (scanf("%d", value) == 0 || getchar() !='\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void fill_1d_array (int elem_num, int *array)
{
    for (int i = 0; i < elem_num; ++i)
    {
        print_for_array_input(i);
        check((array+ i));
    }
}

void rand_fill_1d_array(int elem_num, int *array)
{
    srand(time(NULL));
    for (int j = 0; j < elem_num; j++)
    {
        array[j] = -100 + rand() % (100 + 100 + 1) ;
    }
}

void delete_element(int **array, int element, int *row_array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < row_array[i]; j++)
        {
            if (array[i][j] == element)
            {
                for (int k = j; k < row_array[i]; k++)
                array[i][k] = array[i][k + 1];
                count++;
            }
        }
        row_array[i] = row_array[i] - count;
        array[i] = realloc(array[i], row_array[i] * sizeof(int*));
        if(count != 0)
            i = i - 1;
        count = 0;
    }
}

int* allocate_memory_1d(int size)
{
    return malloc(size * sizeof(int));
}

int** allocate_memory_2d(int size)
{
    return malloc(size * sizeof(int*));
}

int* reallocate_memory_1d(int * array, int size)
{
    return realloc(array, size * sizeof(int));
}

int** reallocate_memory_2d(int ** array, int size)
{
    return realloc(array, size * sizeof(int*));
}

void matrix_output(int **arr_2d, int *row_arr, int num_of_rows)
{
    for (int i = 0; i < num_of_rows; i++)
    {
        for (int j = 0, count = 0; j < row_arr[i]; j++, count++)
        {
            printf("%6d", arr_2d[i][j]);
            if (count == row_arr[i] - 1)
                printf("\n\n");
        }
    }
}

void print_for_array_input(int a)
{
    printf("Enter element %d \n", a);
}

void print_for_array_input_2d(int a, int b)
{
    printf("Enter element %d:%d \n", a, b);
}

void fill_2d_array(int **array, int *row_array, int num_of_rows, int num_of_columns)
{
    for (int i = 0; i < num_of_rows; i++)
    {
        row_array[i] = num_of_columns;
        array[i] = allocate_memory_1d(num_of_rows);
        for (int j = 0; j < num_of_columns; j++)
        {
            print_for_array_input_2d(i,j);
            check(&array[i][j]);
        }
    }
}

void fill_2d_array_different_rows(int **array, int *row_array, int num_of_rows, int num_of_columns)
{
    for (int i = 0; i < num_of_rows; i++)
    {
        row_array[i] = num_of_columns;
        array[i] = allocate_memory_1d(num_of_rows);
        for (int j = 0; j < num_of_columns; j++)
        {
            print_for_array_input_2d(i,j);
            check(&array[i][j]);
        }
    }
}

void delete_min (int **array, int *row_array, int num_of_rows)
{
    for (int i = 1, count = 0, one = -1; i < num_of_rows; i = i + 2)
    {
        int min = array[i][0], mi;
        for (int j = 0; j < row_array[i] - 1; j++)
        {
            if (min > array[i][j])
            {
                min = array[i][j];
            }
        }
        for (int j = 0, q = 1, e; j < row_array[i] - 1; j++)
        {
            if (min == array[i][j])
            {
                e = j;
                mi = array[i][j];
                for (; q < e; --e)
                {
                    array[i][e] = array[i][e - 1];
                }
                array[i][count] = mi;
                count++;
            }
        }
        for (int j = 0; count < row_array[i]; count++, j++)
        {
            array[i][j] = array[i][count];
        }
        for (int j = 0; j < row_array[i]; j++)
        {
            if (array[i][j] == 0)
            {
                one = j;
                break;
            }
        }
        row_array[i] = one + 1;
        array[i] = reallocate_memory_1d(array[i], row_array[i]);
    }
}
