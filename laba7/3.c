#include <stdio.h>
#include <string.h>
#include "arrays.h"

//cd c://Users/Alexander/CLionProjects/laba7/cmake-build-debug
int main(int argc, char **argv)
{
    int *arr1, *arr2;
    arr1 = allocate_memory_1d(argc);
    arr2 = allocate_memory_1d(255);

    int first_symbol = 0, last_symbol, count = 0, lenth123 = 0;
    //////////////////////////////////////Tut vmesto chmohnih znakov probel
    for (int i = 0; i < argc; ++i)
    {
        for (int j = 0; j < strlen(argv[i]); j++)
        {
            if ((int)argv[i][j] == 32 || argv[i][j] > 0 && argv[i][j] < 65 || argv[i][j] > 90 && argv[i][j] < 97 || argv[i][j] > 122 && argv[i][j] < 127)
            {
                argv[i][j] = ' ';
            }
        }
    }
    //////////////////////////////////////Delaet normalna
    for (int i = 1; i < argc; i++)
    {
        argv[i] = normalizestr(argv[i]);
        argv[i][strlen1(argv[i])] = '\0';
    }
    //////////////////////////////////////Bukavi shitaet
    /*for(int i = 1, k = 0, h = 0; i < argc; i++)
    {
        for (int j = 0; j < (strlen(argv[i]) + 1) ; j++)
        {
            if(argv[i][j] != ' ')
            {
                count++;
            }
            if(argv[i][j] == ' ')
            {
                arr2[k] = count;
                k++;
                count = 0;
                continue;
            }
            if (argv[i][j] == '\0')
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
        arr1[h] = max;
        h++;
        k = 0;
    }*/
    maxword(argc, argv, arr1);
    //////////////////////////////////////
    quick_sort(arr1, 0, argc - 1);
    for (int i = 0; i < argc - 1; i++)
    {
        printf("\n%d\n", arr1[i]);
    }
    //output_1d_array(arr, argc);

    putsarr(argv + 1, argc - 1);

    return 0;
}