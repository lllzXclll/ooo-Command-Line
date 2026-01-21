#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "commands.h"
#include "utils.h"


#define EXIT_CMD "exit"
#define MAX_ARGS 10
const char* welcome_msg = "Welcome to OOO Command-Line\nCreated by zXc to prove he is worth something still :)\n";


int main() {
	char cmd[MAX_SIZE];
	printf(welcome_msg);
	while (true)
	{
		printf("OOO> ");
		if (fgets(cmd, MAX_SIZE, stdin) != NULL) // got input
		{
			cmd[strcspn(cmd, "\n")] = '\0';// terminate \n at the end of the command
			if (strcmp(cmd, EXIT_CMD) == 0)
			{
				printf("I hople I proven my worth :) bye...");
				return 0;
			}
			/* just to prove it works
			int cmd_id = get_command_id(sizeof(cmd), cmd);
			commands[cmd_id].func(0, NULL);
			*/
			char* argv[MAX_ARGS];
			int argc = split_line(cmd, argv, MAX_ARGS);
			cmd_general_runner(get_command_id(argv[0]), argc, argv);
		}
	}
	return 0;
}