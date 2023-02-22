#ifndef INC_1_LABA_2S_STRUCTURE_H
#define INC_1_LABA_2S_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <windows.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }
#define SWAP_FLT(A, B) { float t = A; A = B; B = t; }
#define SWAP_STR(A, B) { char t[50]; strcpy(t, A); strcpy(A, B); strcpy(B, t); }
#define COMPARE(A, B, C) {if(A > B) C = 1; else C = 0;}

enum {clrDefault = 0, clrYellow, clrGreen, clrRed};

typedef struct film
{
    char *name;
    float rating;
    int length;

}film_func;

void param_sort(struct film *structure, int num_of_elements, int first, int second);
void arr_structure_print(struct film *structure, int num_of_elements);
void arr_struct_create(struct film *structure, int num_of_elements);
void init_struct_exam(struct film *structure);
void name_sort(struct film *structure, int num_of_elements);
void rating_sort(struct film *structure, int num_of_elements);
void length_sort(struct film *structure, int num_of_elements);

void double_sort(struct film *structure, int num_of_elements);
void single_sort(struct film *structure, int num_of_elements);


void set_text_color(int color);
void dell_struct(struct film *structure, int* num_of_elements);
void init_struct_arr(struct film *structure, int *num_of_elements);

void init_struct(struct film **structure,int *num_of_elements);
void allocate_structure(struct film **structure, const int* new_size);
void reallocate_structure(struct film **structure, const int* new_size);

void free_struct(film_func *structure, int num_of_elements);
void check_more_0(int *value);
void check(int *value);
void check_l4(int *value);
void check_in_range(int *value, int left_boarder, int right_boarder);
void check_same(int *first_number, int *second_number);



void menu(film_func *structure, int *num_of_elements);





#endif //INC_1_LABA_2S_STRUCTURE_H
