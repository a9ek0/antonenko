#ifndef LABA3_FUNCTIONS_H
#define LABA3_FUNCTIONS_H
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int min_num_miss_in_second (int x[], int y[], int z);
int array_input_1d(int mass_name[], int num_of_elements);
int array_input_2d(int mass[100][100], int columns, int lines);
int first_zero_in_mass(int mass[],int num_of_elem);
int last_zero_in_mass(int mass[],int num_of_elem);
int zeros_after_even(int mass_name[], int num_of_elements);
int saddle_points_Lp_Jm(int lines, int columns, int main_mass[100][100], int count);
int saddle_points_Lm_Jp(int lines, int columns, int main_mass[100][100], int count);
int columns_1 ();
int lines_1 ();

#endif
