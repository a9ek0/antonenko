#include <stdint.h>

// size_t
// SIZE_MAX

#include <stdio.h>

// feof
// fflush
// fgets
// perror
// printf

#include <stdlib.h>

// NULL

#include <string.h>

// strtok
// strlen

enum { SIZE = 200 };

static const char delims[] = "\t\n\r ";

int main(int argc, char **argv)
{
    char s[SIZE];
    printf("enter a sentence: ");
    fflush(stdout);
    char *max_word = NULL;
    size_t max_len = 0;
    for (char *word = strtok(s, delims); word != NULL; word = strtok(NULL, delims))
    {
        size_t len = strlen(word);

        if (len > max_len) {
            max_len = len;
            max_word = word;
        }
    }

    printf("the longest word is: %s\n", max_word);

    return 0;
}