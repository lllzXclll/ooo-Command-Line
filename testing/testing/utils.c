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

int* find_pattern_line(const char* data, const char* pattern, size_t* out_count)
{
    size_t cap = 4;
    size_t count = 0;
    int line = 1;
    size_t pattern_len = strlen(pattern);

    int* result = malloc(cap * sizeof(int));
    if (!result) return NULL;

    const char* line_start = data;
    
    while (*data) {
        if (*data == '\n' || *(data + 1) == '\0') {
            size_t len = (data - line_start) + (*(data + 1) == '\0' ? 1 : 0);
            if (len >= pattern_len) { // if the line is long enough to hold the pattern value
                for (size_t i = 0; i <= len - pattern_len; i++) { // go over pattern_len chunks while addvancing by 1 each time
                    if (strncmp(line_start + i, pattern, pattern_len) == 0) {
                        if (count >= cap) { // end of the dynamic array
                            cap *= 2;
                            int* tmp = realloc(result, cap * sizeof(int));
                            if (!tmp) {
                                free(result);
                                return NULL;
                            }
                            result = tmp;
                        }
                        result[count] = line;
                        count++;
                        break;
                    }
                }
            }
            // new line
            line++;
            line_start = data + 1;
        }
        data++;

    }


    *out_count = count;
    return result;
}

size_t total_str_len(char** str)
{
    size_t len = 1; // include the length of '\0'
    size_t i = 2; // start at index 2 after the 'search' and 'filename' in the command
    while (str[i] != NULL) {
        len += strlen(str[i]);
        if (str[i + 1] != NULL) { // didn't reach the end
            len++; // add space count
        }
        i++;
    }

    return len;
}

