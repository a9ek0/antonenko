#ifndef LABA5_ARRAYS_H
#define LABA5_ARRAYS_H
#endif
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
//STRING ROFLANI
void lower(char *c);
void rus_lower(char *c);
void upper(char *c);
void first_low(int size, char *str);
int strlen1(const char *str);
char* fillstr(char *string);
char* normalizestr(char *string);
char* delvoid(char *string);
void cpycmd(char **string, int argc, char **argv);
void putsarr(char **string, int num_of_str);
void maxword(int argc1, char **argv1, int *lentharr);
void onlyspace (char *string);
char* prekol(int argc1, char**str);
void switchstr(char** str, char** argv1, int argc1, const int *switch_arr1, int *switch_arr2);
//CHECKS
void check_more_0(int *value);
void check(int *value);
void check2(int * value);
//FILL/OUTPUT ARRAY
void fill_1d_array (int elem_num, int *array);
void fill_2d_array(int **array, int *row_array, int num_of_rows, int num_of_columns);
void matrix_output(int **arr_2d, const int *row_arr, int num_of_rows);
void output_1d_array(const int *array, int size);
void print_for_array_input_2d(int a, int b);
void print_for_array_input(int a);
void rand_fill_1d_array(int elem_num, int *array);
void fill_array(int *array, int num_of_elem);
void fill_array_2d(int **array, int rows, int columns, int *column_array);
void rand_fill_2d_array(int **array, int *column_array, int rows, int columns);
void print (int *array, int size);
void indent();
//WORKING WITH MEMORY
char** allocstr_arr(int num_of_elem, int size_of_elem);
char* allocstr(int num_of_elem, int size_of_elem);
char* reallocstr(int size, char *mem);
int** allocate_memory_2d(int size);
int* allocate_memory_1d(int size);
int* reallocate_memory_1d(int * array, int size);
int** reallocate_memory_2d(int ** array, int size);
void copy(int **main_arr, int **copy_arr, int columns, int rows);
void free_2d(int **array, int size);
//SORTING
void insertion_sort(int *array, int first_border, int last_border);
void hoar_sorting(int **array, int columns, int rows);
void quick_sort(int *arr, int left, int right);
void merge_sort(int *arr, int l, int r);
void bubble_sort(int* arr, int size);
void shell_sort(int* arr, int size);

//DELETING/INSERTING AN ELEMENT
void delete_element(int **array, int element, int *row_array, int size);
void delete_min (int **array, int *row_array, int num_of_rows);
void delete_element_1d(int *array, int element, int *size);

//TRESH
void min_last(int *array, int size, int *min);
void min_first(int *array, int size, int *min);
void sum_numbers(int **sum_array, int **array, int rows, int columns);
void switch_columns(int **array, int **sum_array123, int rows, int columns);
void compare(int columns, int rows, int **sum_array, int **array);
