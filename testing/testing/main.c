#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "commands.h"


#define MAX_SIZE 1024
#define EXIT_CMD "exit"
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
			else
			{
				
			}
			
		}
	}
	return 0;
}