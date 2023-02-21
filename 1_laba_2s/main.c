#include "structure.h"


//////////////////////////////ПРОВЕРКИ НАДО СДЕЛАТЬ
int main()
{
    int size;
    struct film *da;
    init_struct(&da, &size);
    arr_struct_create(da, size);
    double_sort(da, size);
    arr_structure_print(da, size);
    //menu(da, size);
    return 0;
}
