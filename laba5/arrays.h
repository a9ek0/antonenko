#ifndef LABA5_ARRAYS_H
#define LABA5_ARRAYS_H
#endif //LABA5_ARRAYS_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

//CHECK
void check_more_0(int *value);
void check(int *value);
//WORKING WITH MEMORY
int* allocate_memory_1d(int size);
int** allocate_memory_2d(int size);
int* reallocate_memory_1d(int * array, int size);
int** reallocate_memory_2d(int ** array, int size);
//INPUT/OUTPUT ARRAY
void matrix_output(int **arr_2d, int *row_arr, int num_of_rows);
void fill_2d_array(int **array, int *row_array, int num_of_rows, int num_of_columns);
void fill_1d_array (int elem_num, int *array);
void print_for_array_input_2d(int a, int b);
void print_for_array_input(int a);
void output_1d_array(const int *array, int size);
//DELETING/ENTERING AN ELEMENT
void delete_element(int **array, int element, int *row_array, int size);
void delete_min (int **array, int *row_array, int num_of_rows);
void delete_element_1d(int *array, int element, int *size);