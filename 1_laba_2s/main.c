#include "structure.h"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    char name[42] = "E://GITrepos//antonenko//1_laba_2s//1.txt";
    char str[30] = "div class=\"nameRus\"><a href=\"";
    char str1[40];
    char c;
    FILE *f;
    f = fopen(name, "rt+");
    while(!(feof(f)))
    {
        c = fgetc(f);
        if(c == '<')
        {
            fgets(str1, 40, f);
            if(strstr(str1 , str) != NULL)
                fprintf(stdout, "%s", str1);
        }
        else
            continue;
    }




    /*int size = 0;
    struct film *da;
    menu(&da, &size);
    printf("1"); */
    return 0;
}

/*
void get_str(char *buff, int size)
{
    int i = 0;
    char c;
    while(i < size)
    {
        i++;
        c = fgetc(f);
    }
}*/
