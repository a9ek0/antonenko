#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int first_task(void);
int second_task(void);
int main(void)
{
    int choose;
    int(*task[])(void) = {&first_task, &second_task};
    printf("Choose task \n0. First Task\n1. Second Task\n");
    check2(&choose);
    return task[choose]();
}

int first_task(void)
{
    char *c = NULL;
    c = fillstr(c);
    first_low(strlen1(c), c);
    puts(c);
    free(c);
    return 0;
}

int second_task(void)
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
    S1 = delvoid(S1);
    for (int i = 0; i < N1; i++)
    {
        S3[i] = S1[i];
    }
    free(S1);
    S2 = delvoid(S2);
    for (int k = N1, l = strlen1(S2) - 2, z = 0;  -1 < l; l--, k++, z++)
    {
        if(z == N2)
            break;
        S3[k] = S2[l];
    }
    /////////////////////////////
    free(S2);
    puts(S3);
    free(S3);
    return 0;
}
