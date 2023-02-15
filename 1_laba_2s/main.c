#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }
#define SWAP_FLT(A, B) { float t = A; A = B; B = t; }
#define SWAP_STR(A, B) { char t[50]; strcpy(t, A); strcpy(A, B); strcpy(B, t); }


struct film
{
    char name[50];
    float rating;
    int length;
}a;
void arr_structure_print(struct film structure[], int num_of_elements);
void arr_struct_create(struct film structure[], int num_of_elements);
void init_struct_exam(struct film structure);
void name_sort(struct film structure[], int num_of_elements);
void rating_sort(struct film structure[], int num_of_elements);
void length_sort(struct film structure[], int num_of_elements);

int main()
{

    int x = 3;

    struct film no[x];
    struct film *da = &no;



    arr_struct_create(da, x);

    arr_structure_print(da, x);

    printf("\n");

    name_sort(da, x);

    printf("\n");
    arr_structure_print(da, x);

    rating_sort(da, x);

    printf("\n");
    arr_structure_print(da, x);

    length_sort(da, x);

    printf("\n");
    arr_structure_print(da, x);


    return 0;
}

void name_sort(struct film structure[], int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements; ++j)
        {
            if(strcmp(structure[j].name, structure[j + 1].name) > 0)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP(structure[j].length, structure[j + 1].length);
                SWAP(structure[j].rating, structure[j + 1].rating);
            }
        }
    }
}

void rating_sort(struct film structure[], int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements; ++j)
        {
            if(structure[j].rating < structure[j + 1].rating)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP_FLT(structure[j].length, structure[j + 1].length);
                SWAP_FLT(structure[j].rating, structure[j + 1].rating);
            }
        }
    }
}

void length_sort(struct film structure[], int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements; ++j)
        {
            if(structure[j].length < structure[j + 1].length)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name);
                SWAP(structure[j].length, structure[j + 1].length);
                SWAP(structure[j].rating, structure[j + 1].rating);
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
        printf("\nN is: %s", structure[i].name);
        printf("\nW is: %d", structure[i].length);
        printf("\nT is: %1.3f", structure[i].rating);
    }
}


void arr_struct_create(struct film structure[], int num_of_elements)
{
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nEnter n\n");
        scanf_s("%s", structure[i].name);
        fflush(stdin);
        printf("\nEnter w\n");
        scanf_s("%d", &structure[i].length);
        printf("\nEnter t\n");
        scanf_s("%f", &structure[i].rating);
    }

}
