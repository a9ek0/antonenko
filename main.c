#include <stdio.h>
struct qwe
{
    char name[20];
    int weight;
    float trunk_size;
};
void arr_structure_print(struct qwe structure[], int num_of_elements);
void arr_struct_create(struct qwe structure[], int num_of_elements);

int main() {
    int x = 2;
    struct qwe no[x];
            //[5] = {{}, {}, {}, {}, {}};
    struct qwe *da = &no;
    arr_struct_create(da, x);
    arr_structure_print(da, x);
    return 0;
}

void arr_structure_print(struct qwe structure[], int num_of_elements)
{
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nN is: %s", structure[i].name);
        printf("\nW is: %d", structure[i].weight);
        printf("\nT is: %1.3f", structure[i].trunk_size);
    }
}


void arr_struct_create(struct qwe structure[], int num_of_elements)
{
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nEnter n\n");
        scanf_s("%s", structure[i].name);
        fflush(stdin);
        printf("\nEnter w\n");
        scanf_s("%d", &structure[i].weight);
        printf("\nEnter t\n");
        scanf_s("%f", &structure[i].trunk_size);
    }

}
