#include "utils.h"

// Funciton that gets a string and strips each word and sets a pointer to it
// input - str: the string. argv: the pointers
// Ouput - ammount of words
int split_line(char* str, char** argv, int max_args)
{
    if (!str || !argv) return 0;

    char* context = NULL;
    int argc = 0;

    char* token = strtok_s(str, " \t\n", &context);
    while (token && argc < max_args - 1) {
        argv[argc++] = token;
        token = strtok_s(NULL, " \t\n", &context);
    }

    argv[argc] = NULL;
    return argc;
}