#include "commands.h"

const Command_Id get_command_id(const char* str)
{
    if (str == NULL) { // empty string
        printf("No command found!");
        return UNKNOWN_CMD;
    }
    //check which command
    for (size_t i = 0; i < sizeof(commands); i++) {
        if (strcmp(str, commands[i].name) == 0) {
            return commands[i].id;
        }
    }
    return UNKNOWN_CMD; // no real command found
}

int cmd_help(int argc, char** argv)
{
    printf("%s", help_msg);
    return 0;
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
