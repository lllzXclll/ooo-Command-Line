#include "commands.h"

const Command_Id get_command_id(const char** first_word)
{
    if (first_word == NULL) { // empty string
        printf("No command found!");
        return UNKNOWN_CMD;
    }
    //check which command
    for (size_t i = 0; i < sizeof(commands); i++) {
        if (strcmp(first_word, commands[i].name) == 0) {
            return commands[i].id;
        }
    }
    return UNKNOWN_CMD; // no real command found
}
// running the function of the wanted command
// input: Command_Id - the wanted command id
// ouput: 1 - mannaged to run command. 0 - error in running the command
int cmd_general_runner(Command_Id id, int argc, char** argv)
{
    Command cmd = commands[id];
    if (cmd.func(argc, argv))
        return 1;
    return 0;
}

int cmd_help(int argc, char** argv)
{
    printf("%s", help_msg);
    return 1;
}

int cmd_copy(int argc, char** argv)
{
    return 0;
}

int cmd_count(int argc, char** argv)
{
    return 0;
}

int cmd_search(int argc, char** argv)
{
    return 0;
}

int cmd_cf(int argc, char** argv)
{
    return 0;
}

int cmd_cdir(int argc, char** argv)
{
    return 0;
}

int cmd_rf(int argc, char** argv)
{
    return 0;
}

int cmd_rdir(int argc, char** argv)
{
    return 0;
}
