#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_SIZE 1024

int split_line(char* str, char** argv, int max_args);

