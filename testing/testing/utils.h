#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 8192
#define MAX_SIZE 1024

typedef char Buffer[BUFFER_SIZE];

static const char unknown_cmd_msg[] = "FIX YOUR COMMAND! NO SUCH COMMAND BUDDY '_'\nUse help command if you lost :)\n";

static const char help_msg[] = "You asked for HELP!\n \n\
help - this message\n\
clear - cleans the screen(uses ANSI Escape Codes)\n\
copy [src] [dst] - copies src content into dst. if dst doesn't exists creates it\n\
count [file] - line, word, char count\n\
search [file] [content] - returns lines with 'content' in them\n\
cf [file] [content] - creates file with 'content'\n\
cdir [directory] - creates directory\n\
rf [file] - removes file\n\
rdir [directory] - removes directory. asks to confirm if found content inside\n";


int split_line(char* str, char** argv, int max_args);

