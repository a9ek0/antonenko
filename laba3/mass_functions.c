#include "mass_functions.h"

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

int array_input(int mass_name[], int num_of_elements)
{
    printf("Enter the number of array elements: ");
    while (scanf("%d", &num_of_elements) == 0)
    {
        printf("Wrong input\n");
        scanf("%d", &num_of_elements);
        rewind(stdin);
    }
    while (num_of_elements > 100 || num_of_elements < 0)
    {
        printf("Wrong input\n");
        scanf("%d", &num_of_elements);
        rewind(stdin);
    }
    int o, l = 0;
    srand(time(NULL));
    printf("Do you want to fill an array with random values?(1 - Yes/2 - No)\n");
        while (scanf("%d", &o) == 0 || o < 1 || o > 2)
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
    for(int i = 0, j = num_of_elem;i < j - 1;i++)
    {
        if (mass[i] == 0)
            zero = i;
    }
    return zero;
}

int zeros_after_even(int mass_name[], int num_of_elements)
{
    printf("Enter the number of array elements: ");
    while (scanf("%d", &num_of_elements) == 0)
    {
        printf("Wrong input\n");
        scanf("%d", &num_of_elements);
        rewind(stdin);
    }
    while (num_of_elements > 100)
    {
        printf("Wrong input\n");
        scanf("%d", &num_of_elements);
        rewind(stdin);
    }
    while (num_of_elements < 0)
    {
        printf("Wrong input\n");
        scanf("%d", &num_of_elements);
        rewind(stdin);
    }
    int o;
    srand(time(NULL));
    printf("Do you want to fill an array with random values?(1 - Yes/2 - No)\n");
    while (scanf("%d", &o) == 0 || o < 1 || o > 2)
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