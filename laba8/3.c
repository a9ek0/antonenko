#include <stdio.h>
#include <string.h>
#include "arrays.h"

//cd c://Users/Alexander/CLionProjects/laba7/cmake-build-debug ; "qwe" "qwert" "qw" "qwer" "qwerty"
int main(int argc, char **argv)
{
    char **s;
    int *arr1, *arr2;
    arr1 = allocate_memory_1d(argc);
    arr2 = allocate_memory_1d(argc);

    s = allocstr_arr(argc, 255);
    cpycmd(s, argc, argv);

    //////////////////////////////////////Tut vmesto chmohnih znakov probel
    /*for (int i = 0; i < argc; ++i)
    {
        for (int j = 0; j < strlen(s[i]); j++)
        {
            if (s[i][j] > 47 && s[i][j] < 58)
                continue;
            if ((int)s[i][j] == 32 || s[i][j] > 0 && s[i][j] < 65 || s[i][j] > 90 && s[i][j] < 97 || s[i][j] > 122 && s[i][j] < 127)
            {
                s[i][j] = ' ';
            }
        }
    }*/
    for (int i = 0; i < argc; ++i)
    {
        onlyspace(s[i]);
    }

    //////////////////////////////////////Delaet normalna
    for (int i = 0; i < argc; i++)
    {
        s[i] = normalizestr(s[i]);
    }
    //////////////////////////////////////Bukavi shitaet
    maxword(argc, s  , arr1);
    copy(&arr1, &arr2, argc, 1);

    quick_sort(arr1, 0, argc - 1);

    /*for (int i = 0, v = 1; i < (argc - 1); i++, v++)
    {
        for (int j = 0, z = 1; j < (argc - 1); j++, z++)
        {
            if(arr1[i] == arr2[j])
            {
                s[v] = argv[z];
                break;
            }
        }
    }*/

    switchstr(s, argv, argc, arr1, arr2);

    for (int i = 0; i < argc - 1; i++)
    {
        printf("\n%d - %d\n", i, arr1[i]);
    }
    putsarr(s + 1, argc - 1);
    return 0;
}