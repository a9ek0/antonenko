#include <stdio.h>
#include "structure.h"
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <windows.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }
#define SWAP_FLT(A, B) { float t = A; A = B; B = t; }
#define SWAP_STR(A, B) { char t[50]; strcpy(t, A); strcpy(A, B); strcpy(B, t); }


/*typedef struct film
{
    char name[50];
    float rating;
    int length;
    enum {clrDefault = 0, clrYellow, clrGreen, clrRed};
}film_func;

void arr_structure_print(struct film structure[], int num_of_elements);
void arr_struct_create(struct film structure[], int num_of_elements);
void init_struct_exam(struct film structure);
void name_sort(struct film structure[], int num_of_elements);
void rating_sort(struct film structure[], int num_of_elements);
void length_sort(struct film structure[], int num_of_elements);
void double_sort(struct film structure[], int num_of_elements);
void set_text_color(int color);
void dell_struct(struct film structure[], int film_name, int* num_of_elements);
void init_struct_arr(struct film *structure, int *num_of_elements);
film_func* init_struct(int *num_of_elements);
void menu(film_func *structure, int num_of_elements);*/

//////////////////////////////ПРОВЕРКИ НАДО СДЕЛАТЬ///////ДИНАМИЧЕСКОЕ НАЗВАНИЕ ЧЕРЕЗ СТРЛЕН + 1
int main()
{

    int x = 0;
    struct film *da;
    menu(da, x);
    return 0;
}

/*
void menu(film_func *structure, int num_of_elements)
{
    int a, k = 0;
    char stop[10];
    while(k != 3)
    {
        if(strcmp("Stop", stop) == 0)
            break;
    printf("1.Initiate structure array.\n"
           "2.Enter structure array.\n"
           "3.Sort structure.\n"
           "4.Print structures.\n");
    scanf_s("%d", &a);
    switch (a)
    {
        case 1:
            structure = init_struct(&num_of_elements);
            k = 1;
            break;
        case 2:
            if(k != 1)
            {
                printf("You didn't initialize the array.\n");
                break;
            }
            arr_struct_create(structure, num_of_elements);
            k = 2;
            break;
        case 3:
            if(k != 2)
            {
                printf("You didn't fill/initialize the array.\n");
                break;
            }
            double_sort(structure, num_of_elements);
            break;
        case 4:
            arr_structure_print(structure, num_of_elements);
            break;
    }
        printf("Enter <Stop> if you want to start sorting or <Continue> to add sorting fields.\n");
        fflush(stdin);
        gets(stop);
        while(strcmp("Stop", stop) != 0 || strcmp("Continue", stop) != 0)
        {
            if(strcmp("Stop", stop) == 0 || strcmp("Continue", stop) == 0)
                break;
            printf("Wrong input. Enter <Stop> if you want to start sorting or <Continue> to add sorting fields.\n");
            fflush(stdin);
            gets(stop);
        }
    }
}

film_func* init_struct(int *num_of_elements)
{
    int size;
    printf("Enter number of structures in array.\n");
    scanf_s("%d", &size);
    film_func *films = (film_func *) calloc(size, sizeof(film_func));
    *num_of_elements = size;
    return films;
}

void dell_struct(struct film structure[], int film_name, int* num_of_elements)
{
    int i = film_name;
    *num_of_elements -= 1;
    for (; i < *num_of_elements; i++)
    {
        strcpy(structure[i].name, structure[i + 1].name);
        structure[i].length = structure[i + 1].length;
        structure[i].rating = structure[i+ 1].rating;
    }
    structure = realloc(structure, *num_of_elements * sizeof (struct film));
}

void set_text_color(int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color)
	{
        case clrDefault:
            SetConsoleTextAttribute(handle, 7);
            break;
        case clrYellow:
            SetConsoleTextAttribute(handle, 14);
            break;
        case clrGreen:
            SetConsoleTextAttribute(handle, 2);
            break;
        case clrRed:
            SetConsoleTextAttribute(handle, 4);
            break;
	}
}

void double_sort(struct film structure[], int num_of_elements)
{
    char stop[10];
    int k = 0;
    int first = 0;
    int second = 0;
    while(k != 2)
    {
        if(strcmp("Stop", stop) == 0)
            break;
        printf("Choose sorting field.\n 1.Sort by name.\n 2.Sort by rating.\n 3.Sort bu length");
        if(k == 0)
        {
            scanf_s( "%d", &first);
            printf("Enter <Stop> if you want to start sorting or <Continue> to add sorting fields.\n");
            fflush(stdin);
            gets(stop);
            while(strcmp("Stop", stop) != 0 || strcmp("Continue", stop) != 0)
            {
                if(strcmp("Stop", stop) == 0 || strcmp("Continue", stop) == 0)
                    break;
                printf("Wrong input. Enter <Stop> if you want to start sorting or <Continue> to add sorting fields.\n");
                fflush(stdin);
                gets(stop);
            }
        }
        if(k == 1)
        {
            scanf_s("%d", &second);
        }
        k++;
    }
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(strcmp(structure[j].name, structure[j + 1].name) >= 0 && (first == 1 || second == 1) && (structure[j].rating <= structure[j + 1].rating && (first == 2 || second == 2))
            ||(strcmp(structure[j].name, structure[j + 1].name) >= 0 && (first == 1 || second == 1) && structure[j].length <= structure[j + 1].length && (first == 3 || second == 3))
            ||(structure[j].rating <= structure[j + 1].rating && (first == 2 || second == 2) && (structure[j].length <= structure[j + 1].length && (first == 3 || second == 3))))
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP(structure[j].length, structure[j + 1].length);
                SWAP_FLT(structure[j].rating, structure[j + 1].rating);
            }
        }
    }
}

void name_sort(struct film structure[], int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(strcmp(structure[j].name, structure[j + 1].name) > 0)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP(structure[j].length, structure[j + 1].length);
                SWAP_FLT(structure[j].rating, structure[j + 1].rating);
            }
        }
    }
}

void rating_sort(struct film structure[], int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(structure[j].rating < structure[j + 1].rating)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP(structure[j].length, structure[j + 1].length);
                SWAP_FLT(structure[j].rating, structure[j + 1].rating);
            }
        }
    }
}

void length_sort(struct film structure[], int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(structure[j].length < structure[j + 1].length)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP(structure[j].length, structure[j + 1].length);
                SWAP_FLT(structure[j].rating, structure[j + 1].rating);
            }
        }
    }
}

void arr_structure_print(struct film structure[], int num_of_elements)
{
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nName is: %s", structure[i].name);
        printf("\nLength is: %d", structure[i].length);
        printf("\nRating is: ");
        if(structure[i].rating >= 8.5 && structure[i].rating <= 10)
            set_text_color(clrGreen);
        if (structure[i].rating >= 7 && structure[i].rating < 8.5)
            set_text_color(clrYellow);
        if(structure[i].rating >= 0 && structure[i].rating < 7)
            set_text_color(clrRed);
        printf("%1.3f\n", structure[i].rating);
        set_text_color(clrDefault);
    }
}


void arr_struct_create(struct film structure[], int num_of_elements)
{
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nEnter Name\n");
        scanf_s("%s", structure[i].name);
        fflush(stdin);
        printf("\nEnter Length\n");
        scanf_s("%d", &structure[i].length);
        printf("\nEnter Rating\n");
        scanf_s("%f", &structure[i].rating);
    }
}
*/
