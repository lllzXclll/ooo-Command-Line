#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

typedef enum {
	HELP_CMD,
	COPY_CMD,
	COUNT_CMD,
	SEARCH_CMD,
	CF_CMD,
	CDIR_CMD,
	RF_CMD,
	RDIR_CMD,
	CLEAR_CMD,
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
int cmd_clear(int argc, char** argv);

const Command_Id get_command_id(const char** first_word);



static const Command commands[] = {// all existing commands
	{"help", HELP_CMD, cmd_help},
	{"copy", COPY_CMD, cmd_copy},
	{"count", COUNT_CMD, cmd_count},
	{"search", SEARCH_CMD, cmd_search},
	{"cf", CF_CMD, cmd_cf},
	{"cdir", CDIR_CMD, cmd_cdir},
	{"rf", RF_CMD, cmd_rf},
	{"rdir", RDIR_CMD, cmd_rdir},
	{"clear", CLEAR_CMD, cmd_clear}
};



int cmd_general_runner(Command_Id id, int argc, char** argv);