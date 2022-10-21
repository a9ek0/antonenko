#include "stdio.h"
#include "mass_functions.h"

int main() {
    int a[100][100], b[100], columns, lines, count = 0;
    columns = columns_1();
    lines = lines_1();
    array_input_2d(a, columns, lines);
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (a[i][j] < 0)
                count++;
        }
        if (count == columns) {
            b[0] = a[i][0];
            break;
        }
        count = 0;
        b[0] = 0;
    }
    if (b[0] == 0)
        printf("No lines with negative elements");
    else{
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++)
                a[i][j] = a[i][j] + b[0];
        }
        printf("\n\n");
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++)
                printf("%4d   ", a[i][j]);
            printf("\n\n");
        }
    }
    return 0;
}
