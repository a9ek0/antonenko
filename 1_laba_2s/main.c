#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <windows.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }
#define SWAP_FLT(A, B) { float t = A; A = B; B = t; }
#define SWAP_STR(A, B) { char t[50]; strcpy(t, A); strcpy(A, B); strcpy(B, t); }


struct film
{
    char name[50];
    float rating;
    int length;
    enum {clrDefault = 0, clrYellow, clrGreen, clrRed};
}a;

void arr_structure_print(struct film structure[], int num_of_elements);
void arr_struct_create(struct film structure[], int num_of_elements);
void init_struct_exam(struct film structure);
void name_sort(struct film structure[], int num_of_elements);
void rating_sort(struct film structure[], int num_of_elements);
void length_sort(struct film structure[], int num_of_elements);
void double_sort(struct film structure[], int num_of_elements);
void set_text_color(int color);

//////////////////////////////ПРОВЕРКИ НАДО СДЕЛАТЬ
int main()
{

    int x = 3;
    struct film *da = (struct film *)malloc(x * sizeof(struct film));

    arr_struct_create(da, x);

    double_sort(da, x);

    arr_structure_print(da, x);


    return 0;
}

void set_text_color(int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color)
	{
        case clrDefault:
            SetConsoleTextAttribute(handle, 7);;
            break;
        case clrYellow:
            SetConsoleTextAttribute(handle, 14);;
            break;
        case clrGreen:
            SetConsoleTextAttribute(handle, 2);;
            break;
        case clrRed:
            SetConsoleTextAttribute(handle, 4);;
            break;
	}
}

void double_sort(struct film structure[], int num_of_elements)
{
    char z[10];
    int k = 0;
    int first = 0;
    int second = 0;
    while(k != 2)
    {
        if(strcmp("Stop", z) == 0)
            break;
        printf("Choose sorting field.\n 1.Sort by name.\n 2.Sort by rating.\n 3.Sort bu length");
        if(k == 0)
        {
            scanf_s( "%d", &first);
            printf("Enter <Stop> if you want to start sorting or <Continue> to add sorting fields.\n");
            fflush(stdin);
            gets(z);
            while(strcmp("Stop", z) != 0 || strcmp("Continue", z) != 0)
            {
                if(strcmp("Stop", z) == 0 || strcmp("Continue", z) == 0)
                    break;
                printf("Wrong input. Enter <Stop> if you want to start sorting or <Continue> to add sorting fields.\n");
                fflush(stdin);
                gets(z);
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

void init_struct_exam(struct film structure)
{
    struct qwe{
    }exam_name;
}

void arr_structure_print(struct film structure[], int num_of_elements)
{
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nName is: %s", structure[i].name);
        printf("\nLength is: %d", structure[i].length);
        if(structure[i].rating >= 8.5 && structure[i].rating <= 10)
            set_text_color(clrGreen);
        if (structure[i].rating >= 7 && structure[i].rating < 8.5)
            set_text_color(clrYellow);
        if(structure[i].rating >= 0 && structure[i].rating < 7)
            set_text_color(clrRed);
        printf("\nRating is: %1.3f", structure[i].rating);
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
