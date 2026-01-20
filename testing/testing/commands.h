#pragma once
#include <stdio.h>
#include <string.h>


static const char help_msg[] = "You asked for HELP!\n\
help - this message\n\
copy [src] [dst] - copies src content into dst. if dst doesn't exists creates it\n\
count [file] - line, word, char count\n\
search [file] [content] - returns lines with 'content' in them\n\
cf [file] [content] - creates file with 'content'\n\
cdir [directory] - creates directory\n\
rf [file] - removes file\n\
rdir [directory] - removes directory. asks to confirm if found content inside\n";

typedef enum {
	HELP_CMD,
	COPY_CMD,
	COUNT_CMD,
	SEARCH_CMD,
	CF_CMD,
	CDIR_CMD,
	RF_CMD,
	RDIR_CMD,
	UNKNOWN_CMD
} Command_Id;

typedef int (*Command_Func)(int argc, char** argv); // pointer to functions "int name(int argc, char** argv)"

typedef struct {
	const char* name;
	Command_Id id;
	Command_Func func;
} Command;



int cmd_help(int argc, char** argv);
int cmd_copy(int argc, char** argv);
int cmd_count(int argc, char** argv);
int cmd_search(int argc, char** argv);
int cmd_cf(int argc, char** argv);
int cmd_cdir(int argc, char** argv);
int cmd_rf(int argc, char** argv);
int cmd_rdir(int argc, char** argv);

const Command_Id get_command_id(const char* str);



static const Command commands[] = {// all existing commands
	{"help", HELP_CMD, cmd_help},
	{"copy", COPY_CMD, cmd_copy},
	{"count", COUNT_CMD, cmd_count},
	{"search", SEARCH_CMD, cmd_search},
	{"cf", CF_CMD, cmd_cf},
	{"cdir", CDIR_CMD, cmd_cdir},
	{"rf", RF_CMD, cmd_rf},
	{"rdir", RDIR_CMD, cmd_rdir}
};