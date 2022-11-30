#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main(void)
{
    char *S1 = NULL, *S2 = NULL, *S3 = NULL;
    int N1, N2;

    printf("Enter N1 value\n");
    check_more_0(&N1);
    printf("Enter N2 value\n");
    check_more_0(&N2);

    S1 = fillstr(S1);
    S2 = fillstr(S2);

    S3 = allocstr(N1 + N2 + 1, sizeof(char));
    /////////////////////////////
    for (int i = 0, k = 0; i < N1; i++)
    {
        if (S1[i] == 'q')
        {
            i++;
            continue;
        }
        S3[i] = S1[i];
        k++;
    }
    free(S1);
    for (int k = N1, l = strlen1(S2) - 2, z = 0;  -1 < l; l--) {
        if (S2[l] == ' ')
        {
            l--;
        continue;
        }
        if(z == N2)
            break;
        S3[k] = S2[l];
        k++;
        z++;
    }
    /////////////////////////////
    free(S2);
    puts(S3);
    free(S3);
    return 0;
}
