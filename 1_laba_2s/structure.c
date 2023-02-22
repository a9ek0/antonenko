#include "structure.h"

void free_struct(film_func *structure, int num_of_elements)
{
    for(int i = 0; i < num_of_elements; i++)
        free(structure[i].name);
    free(structure);
}

void menu(film_func *structure, int *num_of_elements)
{
    int a;
    int k = 0;
    while(k != 3)
    {
        printf("\n1.Initiate structure array.\n"
               "2.Enter structure array.\n"
               "3.Dual sort structures.\n"
               "4.Single sort structures\n"
               "5.Delete structure from array.\n"
               "6.Print structures.\n"
               "7.Exit.\n");
        fflush(stdin);
        scanf_s("%d", &a);
        switch (a)
        {
            case 1:
                init_struct(&structure, num_of_elements);
                k = 1;
                break;
            case 2:
                if(k != 1)
                {
                    printf("You didn't initialize the array.\n");
                    break;
                }
                arr_struct_create(structure, *num_of_elements);
                k = 2;
                break;
            case 3:
                if(k != 2)
                {
                    printf("You didn't fill/initialize the array.\n");
                    break;
                }
                double_sort(structure, *num_of_elements);
                break;
            case 4:
                if(k != 2)
                {
                    printf("You didn't fill/initialize the array.\n");
                    break;
                }
                single_sort(structure, *num_of_elements);
                break;
            case 5:
            {
                if(k != 2)
                {
                    printf("You didn't fill/initialize the array.\n");
                    break;
                }
                dell_struct(structure, num_of_elements);
                break;
            }
            case 6:
                if(k != 2)
                {
                    printf("You didn't fill/initialize the array.\n");
                    break;
                }
                arr_structure_print(structure, *num_of_elements);
                break;
            case 7:
            {
                k = 3;
                break;
            }
            default:
            {
                printf("Wrong input!");
                break;
            }
        }
    }
    free_struct(structure, *num_of_elements);
    exit(0);
}

void reallocate_structure(struct film **structure, const int* new_size)
{
    *structure = (film_func*)realloc(*structure, *new_size * sizeof (film_func));
}


void allocate_structure(struct film **structure, const int* new_size)
{
    *structure = (film_func*)malloc(*new_size * sizeof (film_func));
}

void init_struct(struct film **structure,int *num_of_elements)
{
    printf("Enter number of structures in array.\n");
    check_more_0(num_of_elements);
    *structure = (film_func*)malloc( *num_of_elements * sizeof (film_func));
}

void dell_struct(struct film *structure, int* num_of_elements)
{
    int film_name;
    printf("\nChoose film that you want to delete.\n");
    for (int k = 0; k < *num_of_elements; k++)
    {
        printf("%d: %s\n", k, structure[k].name);
    }
    *num_of_elements -= 1;
    check(&film_name);
    for (int i = film_name ; i < *num_of_elements; i++)
    {
        strcpy(structure[i].name, structure[i + 1].name);
        structure[i].length = structure[i + 1].length;
        structure[i].rating = structure[i+ 1].rating;
    }
    reallocate_structure(&structure, num_of_elements);
}

void set_text_color(int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

        switch (color)
    {
        case clrDefault:
            SetConsoleTextAttribute(handle, 7);
        break;
        case clrYellow:
            SetConsoleTextAttribute(handle, 14);
        break;
        case clrGreen:
            SetConsoleTextAttribute(handle, 2);
        break;
        case clrRed:
            SetConsoleTextAttribute(handle, 4);
        break;
        default:
            printf("Wrong input!");
    }

}

void single_sort(struct film *structure, int num_of_elements)
{
    int expression = 0;
    while(expression != -1) {
        printf("\nChoose sorting field.\n 1.Sort by name.\n 2.Sort by rating.\n 3.Sort by length\n 4.Exit\n");
        check_in_range(&expression, 0, 4);
        switch (expression) {
            case 1:
                name_sort(structure, num_of_elements);
                break;
            case 2:
                rating_sort(structure, num_of_elements);
                break;
            case 3:
                length_sort(structure, num_of_elements);
                break;
            case 4:
                expression = -1;
                break;
            default:
                printf("Wrong input\n");
                break;
        }
    }
}

void double_sort(struct film *structure, int num_of_elements)
{
    int first;
    int second;
    int cnt = 0;
    while(cnt != 2) {
    printf("\nChoose sorting field.\n 1.Sort by name.\n 2.Sort by rating.\n 3.Sort by length\n");
        if(cnt == 1)
        {
            check_l4(&second);
            check_same(&second, &first);
        }
        else
            check_l4(&first);

        switch (first) {
            case 1:
                name_sort(structure, num_of_elements);
                break;
            case 2:
                rating_sort(structure, num_of_elements);
                break;
            case 3:
                length_sort(structure, num_of_elements);
                break;
            default:
                break;
        }
        cnt++;
    }
    param_sort(structure, num_of_elements, first, second);
}

void param_sort(struct film *structure, int num_of_elements, int first, int const second)
{
    int arr[5];
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            COMPARE(structure[j].length, structure[j + 1].length, arr[3])
            COMPARE(structure[j].rating, structure[j + 1].rating, arr[2])
            arr[1] = strcmp(structure[j].name, structure[j + 1].name);
            if(arr[first] > 0 && arr[second] > 0)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name)
                SWAP(structure[j].length, structure[j + 1].length)
                SWAP_FLT(structure[j].rating, structure[j + 1].rating)
            }
        }
    }
}

void name_sort(struct film *structure, int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(strcmp(structure[j].name, structure[j + 1].name) > 0)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name)
                SWAP(structure[j].length, structure[j + 1].length)
                SWAP_FLT(structure[j].rating, structure[j + 1].rating)
            }
        }
    }
}

void rating_sort(struct film *structure, int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(structure[j].rating < structure[j + 1].rating)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name)
                SWAP(structure[j].length, structure[j + 1].length)
                SWAP_FLT(structure[j].rating, structure[j + 1].rating)
            }
        }
    }
}

void length_sort(struct film *structure, int num_of_elements)
{
    for (int i = 1; i < num_of_elements; ++i)
    {
        for (int j = 0; j < num_of_elements - 1; ++j)
        {
            if(structure[j].length < structure[j + 1].length)
            {
                SWAP_STR(structure[j].name, structure[j + 1].name)
                SWAP(structure[j].length, structure[j + 1].length)
                SWAP_FLT(structure[j].rating, structure[j + 1].rating)
            }
        }
    }
}

void arr_structure_print(struct film *structure, int num_of_elements)
{
    rewind(stdin);
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nName is: %s", structure[i].name);
        printf("\nLength is: %d", structure[i].length);
        printf("\nRating is: ");
        if(structure[i].rating >= 8.5 && structure[i].rating <= 10)
            set_text_color(clrGreen);
        if (structure[i].rating >= 7 && structure[i].rating < 8.5)
            set_text_color(clrYellow);
        if(structure[i].rating >= 0 && structure[i].rating < 7)
            set_text_color(clrRed);
        printf("%1.3f\n", structure[i].rating);
        set_text_color(clrDefault);
        printf("\n");
    }
}


void arr_struct_create(struct film *structure, int num_of_elements)
{
    char buffer[100];
    for (int i = 0; i < num_of_elements; ++i)
    {
        printf("\nEnter Name\n");
        scanf_s("%s", buffer);
        structure[i].name = (char *) calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(structure[i].name, buffer);
        fflush(stdin);
        printf("\nEnter Length\n");
        scanf_s("%d", &structure[i].length);
        printf("\nEnter Rating\n");
        scanf_s("%f", &structure[i].rating);
    }
}

void check_more_0(int *value)
{
    while (scanf_s("%d", value) == 0 || *value < 0 || getchar() !='\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void check_in_range(int *value, int left_boarder, int right_boarder)
{
    while (scanf_s("%d", value) == 0 || getchar() !='\n' || *value > right_boarder || *value < left_boarder)
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void check_l4(int *value)
{
    while (scanf_s("%d", value) == 0 || getchar() !='\n' || *value > 3)
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void check(int *value)
{
    while (scanf_s("%d", value) == 0 || getchar() !='\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void check_same(int *first_number, int *second_number) {
    if(*first_number == *second_number)
    {
        printf("You have chosen the same options! Please choose another option");
    while (scanf_s("%d", first_number) == 0 || getchar() != '\n' || *first_number > 3 || *first_number == *second_number) {
        printf("You have chosen the same options! Please choose another option");
        rewind(stdin);
    }
    }
}
