#include "arrays.h"
//STRING ROFLANI

void switchstr(char** str, char** argv1, int argc1, const int *switch_arr1, int *switch_arr2)
{
    for (int i = 0, v = 1; i < (argc1 - 1); i++, v++)
    {
        for (int j = 0, z = 1; j < (argc1 - 1); j++, z++)
        {
            if(switch_arr1[i] == switch_arr2[j])
            {
                str[v] = argv1[z];
                switch_arr2[j] = 0;
                break;
            }
        }
    }
}
/*
char** prekol(int argc1, char**str)
{
    for (int i = 0; i < argc1; ++i)
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            if (str[i][j] > 47 && str[i][j] < 58)
                continue;
            if ((int)str[i][j] == 32 || str[i][j] > 0 && str[i][j] < 65 || str[i][j] > 90 && str[i][j] < 97 || str[i][j] > 122 && str[i][j] < 127)
            {
                str[i][j] = ' ';
            }
        }
    }
    return (char**) realloc(str, 255);
}*/



void onlyspace (char *string)
{
        for (int j = 0; j < strlen1(string); j++)
        {
            if (string[j] > 47 && string[j] < 58)
                continue;
            if ((int)string[j] == 32 || string[j] > 0 && string[j] < 65 || string[j] > 90 && string[j] < 97 || string[j] > 122 && string[j] < 127)
            {
                string[j] = ' ';
            }
        }
}
void maxword( const int argc1, char **argv1, int *lentharr)
{
    int *arr2 = NULL, count = 0;
    arr2 = allocate_memory_1d(255);
    for(int i = 1, k = 0, h = 0; i < argc1; i++)
    {
        for (int j = 0; j < (strlen1(argv1[i]) + 1) ; j++)
        {
            if(argv1[i][j] != ' ')
            {
                count++;
            }
            if(argv1[i][j] == ' ')
            {
                arr2[k] = count;
                k++;
                count = 0;
                continue;
            }
            if (argv1[i][j] == '\0')
            {
                count--;
                arr2[k] = count;
                k++;
                count = 0;
                continue;
            }
        }
        int max;
        max = arr2[0];
        for (int z = 1; z < k; z++)
        {
            if(arr2[z] > max)
                max = arr2[z];
        }
        lentharr[h] = max;
        h++;
        k = 0;
    }
}

void putsarr(char **string, int num_of_str)
{
    for (int i = 0; i < num_of_str; ++i)
    {
        puts(string[i]);
    }
}
void cpycmd(char **string, int argc1, char **argv1)
{
    for (int i = 0; i < argc1; i++)
    {
        string[i] = allocstr(strlen1(argv1[i]), sizeof(char));
        for (int j = 0; j < strlen1(argv1[i]); j++)
        {
            string[i][j] = argv1[i][j];
        }
    }
}
char* delvoid(char *string)
{
    int count = 0, n;
    n = strlen1(string);
    for(int i = 0; i < strlen1(string) + 1; i++)
    {
        if(string[i] == ' ')
        {
            for (int j = i; j < strlen1(string); j++)
            {
                string[j] = string[j + 1];
            }
            i--;
            count++;
        }
    }
    return reallocstr(n - count, string);
}

char* normalizestr(char *string)
{
    int n, count = 0;
    n = strlen1(string);
    if(n == 1)
        return reallocstr(n + 1, string);
    for(int i = -1; i < n; i++)
    {
        if(string[i] == ' ')
        {
            if(string[i + 1] == ' ')
            {
                for (int j = i + 1; j < n; j++)
                {
                    string[j] = string[j + 1];
                }
                i--;
                count++;
            }
        }
    }
    if(string[0] == ' ')
        for (int j = 0; j < n; j++)
        {
            string[j] = string[j + 1];
        }
    return reallocstr(n - count - 1, string);
}

void first_low(int size, char *str)
{
    for (int i = -1; i < size; i++)
    {
        if (((str[i] > 64 && str[i]< 91) || (str[i] > 96 && str[i]< 123)))
            continue;
        if ((str[i + 1] > 64 && str[i + 1]< 91)||(str[i + 1] > 96 && str[i + 1]< 123))
            lower(&str[i + 1]);

    }
}

void rus_lower(char *c)
{
    int k;
    k = (int)*c;
    if(k > 64 && k < 96)
    {
        k = k + 32;
        *c = (char)k;
    }
}

void lower(char *c)
{
    int k;
    k = (int)*c;
    if(k > 64 && k < 96)
    {
        k = k + 32;
        *c = (char)k;
    }
}
void upper(char *c)
{
    int k;
    k = (int)*c;
    if(k > 96 && k < 123)
    {
        k = k - 32;
        *c = (char)k;
    }
}

int strlen1(const char *str)
{
    int count = 0, i = 0;
    while(str[i] != '\0')
    {
        i++;
        count++;
    }
    return count;
}

char* fillstr(char *string)
{
    int n;
    string = allocstr(255, sizeof(char));
    printf("Enter string\n");
    fgets(string, 255, stdin);
    string = normalizestr(string);
    n = strlen1(string);
    return realloc(string, n);
}

char* allocstr(int num_of_elem, int size_of_elem)
{
    return calloc(num_of_elem, size_of_elem);
}

char** allocstr_arr(int num_of_elem, int size_of_elem)
{
    return calloc(num_of_elem, size_of_elem);
}

char* reallocstr(int size, char *mem)
{
    return realloc(mem, size);
}

//CHECKS
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

void check2(int * value)
{
    while (scanf("%d", value) == 0 || *value < 0 || *value > 1 || getchar() !='\n')
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
}

//WORKING WITH MEMORY
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

void free_2d(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }
}


//FILL/OUTPUT ARRAY
void matrix_output(int **arr_2d, const int *row_arr, int num_of_rows)
{
    for (int i = 0; i < num_of_rows; i++)
    {
        for (int j = 0, count = 0; j < row_arr[i]; j++, count++)
        {
            printf("%4d", arr_2d[i][j]);
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
void output_1d_array(const int *array, int size)
{
    for (int i = 0; i < size ; ++i)
        printf("%4d ", *(array + i));
}

void fill_1d_array (int elem_num, int *array)
{
    for (int i = 0; i < elem_num; ++i)
    {
        print_for_array_input(i);
        scanf("%d", (array + i));
        //check((array + i));
    }
}

void fill_array(int *array, int num_of_elem)
{
    int choose;
    printf("Do you want to fill array with random values? 1 - Yes; 2 - No\n");
    while (scanf("%d", &choose) == 0 || choose < 1 || choose > 2 || getchar() !='\n')
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
    switch (choose)
    {
        case 1:
            rand_fill_1d_array(num_of_elem, array);
            break;
        case 2:
            fill_1d_array(num_of_elem, array);
    }
}

void fill_array_2d(int **array, int rows, int columns, int *column_array)
{
    int choose;
    printf("Do you want to fill array with random values? 1 - Yes; 2 - No\n");
    while (scanf("%d", &choose) == 0 || choose < 1 || choose > 2 || getchar() !='\n')
    {
        printf("Wrong input\n");
        rewind(stdin);
    }
    switch (choose)
    {
        case 1:
            rand_fill_2d_array(array, column_array, rows, columns);
            break;
        case 2:
            fill_2d_array(array, column_array, rows, columns);
    }
}

void rand_fill_2d_array(int **array, int *column_array, int rows, int columns)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        column_array[i] = columns;
        array[i] = allocate_memory_1d(column_array[i]);
    for (int j = 0; j < column_array[i]; j++)
    {
        array[i][j] = -100 + rand() % (100 + 100 + 1) ;
    }
    }
}

void rand_fill_1d_array(int num_of_elem, int *array)
{
    srand(time(NULL));
    for (int j = 0; j < num_of_elem; j++)
    {
        array[j] = -100 + rand() % (100 + 100 + 1) ;
    }
}

void print (int *array, int size)
{
    for (int j = 0; j < size; j++)
    {
        printf(" %2d ", array[j]);
    }
}

void indent()
{
    printf("\n\n");
}

//DELETING/INSERTING AN ELEMENT
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
void delete_element_2d(int **array, int element, int *row_array, int size)
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

void delete_element_1d(int *array, int element, int *size)
{
    int  count = 0;
    for (int i = 0; i < *size; i++)
    {
        if (array[i] == element)
        {
            for (int k = i; k < *size; k++)
                array[k] = array[k + 1];
            count++;
            i--;
        }
    }
    *size = *size - count;
}

//SORTING
void insertion_sort(int *array, int first_border, int last_border)
{
    clock_t fTimeStart,fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    for (int i = first_border + 2, max; i < last_border; i++)
    {
        for (int j = first_border + 1, l = i; j < l; j++)
        {
            if(array[i] <= array[j])
            {
                max = array[i];
                for (int m = i, z = j; z < m; m--)
                {
                    array[m] = array[m - 1];
                }
                array[j] = max;
                continue;
            }
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nTime for sorting %i(ms)\n", fTimeStop - fTimeStart);
}

void hoar_sorting(int **array, int columns, int rows)
{
    int o, l = columns - 1, k = rows, first, last;
    o = array[rows][columns - 1];
    for (int i = 0, s; i < l; i++)
    {
        if(array[rows][i] <= o)
        {
            s = array[rows][i];
            array[rows][i] = array[rows][l - 1];
            array[rows][l - 1] = array[rows][l];
            array[rows][l] = s;
            l--;
            k = l - 1;
        }
    }
}

void shell_sort(int* arr, int size)
{
    clock_t fTimeStart,fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    int flag, swap;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        do
        {
            flag = 0;
            for (int i = 0, j = gap; j < size; i++, j++)
            {
                if (arr[i] > arr[j])
                {
                    swap = arr[j];
                    arr[j] = arr[i];
                    arr[i] = swap;
                    flag = 1;
                }
            }
        } while (flag);
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nTime for sorting %i(ms)\n", fTimeStop - fTimeStart);
}

void bubble_sort(int* arr, int size) {
    clock_t fTimeStart,fTimeStop;
    int z, no_swap = 0;

    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                z = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = z;
                no_swap = 1;
            }
        }
        if (no_swap == 0)
        {
            break;
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nTime for sorting %i(ms)\n", fTimeStop - fTimeStart);
}

void merge_sort(int *arr, int l, int r)
{
    clock_t fTimeStart,fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    if (l == r) return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int i = l;
    int j = mid + 1;
    int *tmp = (int*)malloc(r * sizeof(int));
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= mid) && (arr[i] < arr[j])))
        {
            tmp[step] = arr[i];
            i++;
        }
        else
        {
            tmp[step] = arr[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++)
        arr[l + step] = tmp[step];
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nTime for sorting %i(ms)\n", fTimeStop - fTimeStart);
}

void quick_sort(int *arr, int left, int right)
{
    for(int p = 0; p < 3; p++) {
        int ref_point, l_hold = left, r_hold = right;
        ref_point = arr[left];
        while (left < right)
        {
            while ((arr[right] >= ref_point) && (left < right))
                right--;
            if (left != right)
            {
                arr[left] = arr[right];
                left++;
            }
            while ((arr[left] <= ref_point) && (left < right))
                left++;
            if (left != right)
            {
                arr[right] = arr[left];
                right--;
            }
        }
        arr[left] = ref_point;
        ref_point = left;
        left = l_hold;
        right = r_hold;
        if (left < ref_point)
            quick_sort(arr, left, ref_point - 1);
        if (right > ref_point)
            quick_sort(arr, ref_point + 1, right);
    }
}

/*
void select_sorting()
{
    int num;
    char *sort[5] = {"Merge sort - 1", "Insertion sort - 2", "Bubble Sort - 3", "Shell sort - 4", "Quick sort - 5" };
    printf("Select sorting ");
    for(int i = 0; i < 5; i++)
        printf("%s",sort[i]);
    scanf_s("%d", num);
    switch (num) 
    {
        case 1:
            merge_sort(int *arr, int l, int r);
        case 2:
            insertion_sort(int *array, int first_border, int last_border);
        case 3:
            bubble_sort(int* arr, int size);
        case 4:
            shell_sort(int* arr, int size);
        case 5:
            quick_sort(int *arr, int left, int right);
    }
}*/

//TRESH

void min_last(int *array, int size, int *min)
{
    *min = 0;
    for (int i = 0; i < size; i++)
    {
        if(array[i] <= array[*min])
            *min = i;
    }
}

void min_first(int *array, int size, int *min)
{
    *min = 0;
    for (int i = 0; i < size; i++)
    {
        if(array[i] < array[*min])
            *min = i;
    }
}

void switch_columns(int **array, int **sum_array123, int rows, int columns)
{
    int rat[rows][columns];
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            rat[j][i] = array[j][sum_array123[0][i]];
        }
    }
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            array[i][j] = rat[i][j];
        }
    }
}

/*void switch_columns(int **array, int **sum_array123, int rows, int columns)
{
    int find = 0, temp;
    for (; find < columns; )
    {
        for (int i = 0; i < columns; i++)
        {
            if (sum_array123[0][i] == find)
            {
                for (int j = 0; j < rows; j++)
                {
                    temp = array[j][find];
                    array[j][find] = array[j][i];
                    array[j][i] = temp;
                }
                temp = sum_array123[0][find];
                sum_array123[0][find] = sum_array123[0][i];
                sum_array123[0][i] = temp;
                find++;
                break;
            }
        }
    }
}*/

void sum_numbers(int **sum_array, int **array, int rows, int columns)
{
    int sum = 0;
    sum_array[0] = allocate_memory_1d(columns);
    sum_array[1] = allocate_memory_1d(columns);
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            sum = sum + array[i][j];
        }
        sum_array[0][j] = j;
        sum_array[1][j] = sum;
        sum = 0;
    }
}

void copy(int **main_arr, int **copy_arr, int columns, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        copy_arr[i] = allocate_memory_1d(columns);
        for (int j = 0; j < columns; j++)
        {
            copy_arr[i][j] = main_arr[i][j];
        }
    }
}

void compare(int columns, int rows, int **sum_array, int **array)
{
    int **sum_array2 = NULL;
    sum_array2 = allocate_memory_2d(2);
    sum_numbers(sum_array2, array, rows, columns);
    indent();
    print(sum_array2[1], columns);
    indent();
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if(sum_array[1][i] == sum_array2[1][j])
            {
                printf("%d", sum_array[0][i]);
                indent();
                sum_array[0][i] = sum_array2[0][j];
                printf("%d", sum_array[0][i]);
                indent();
                break;
            }
        }
    }
}