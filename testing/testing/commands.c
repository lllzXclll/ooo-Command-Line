#include "commands.h"

const Command_Id get_command_id(const char** first_word)
{
    if (first_word == NULL) { // empty string
        printf("No command found!");
        return UNKNOWN_CMD;
    }
    //check which command
    for (size_t i = 0; i < (sizeof(commands) / sizeof(commands[0])); i++) {
        if (strcmp(first_word, commands[i].name) == 0) {
            return commands[i].id;
        }
    }
    return UNKNOWN_CMD; // no real command found
}

int cmd_general_runner(Command_Id id, int argc, char** argv)
{
    // running the function of the wanted command
    // input: Command_Id - the wanted command id
    // ouput: 1 - mannaged to run command. 0 - error in running the command

    if (id == UNKNOWN_CMD) {
        printf("%s", unknown_cmd_msg);
        return 0;
    }

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
    // copies source file to destenatnion file
    // input: arguments
    // output: 0 - unable to finish command. 1 - finished successfuly

    if (argc != 3) {
        printf("Wrong use of copy. Type help for more information!\n");
        return 0;
    }
    char* src_file_name = argv[1];
    char* dst_file_name = argv[2];

    FILE* src = fopen(src_file_name, "rb");
    if (!src) {
        printf("Error opening source file! Try again :(\n");
        return 0;
    }

    FILE* dst = fopen(dst_file_name, "wb");
    if (!dst) {
        printf("Error opening destenetion file! Try again :(\n");
        return 0;
    }

    Buffer bfr;
    size_t bytes_read = 0;

    while ((bytes_read = fread(bfr, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(bfr, 1, bytes_read, dst);
    }

    printf("source file '%s' copied successfuly to destenation '%s'\n", src_file_name, dst_file_name);

    fclose(src);
    fclose(dst);

    return 1;
}

int cmd_count(int argc, char** argv)
{
    if (argc != 2) {
        printf("Wrong usage of the command count!\n\n");
        return 0;
    }
    const char* file_name = argv[1];
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Couldn't open file '%s'\n", file_name);
        return 0;
    }

    int char_cnt = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        char_cnt++;
    }

    int word_cnt = 0;
    int in_word = 0; // 0 - outside a word. 1 - in a word

    rewind(file); // reset the file pointer to the beginning
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            in_word = 0;
        }
        else {
            if (!in_word)
                word_cnt++; // count only if we weren't inside a word before hand
            in_word = 1;
        }
    }

    int line_cnt = 0;
    int first_counted = 0; // 0 - note counted. 1 - counted

    rewind(file); // reset the file pointer to the beginning
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            line_cnt++;
        }
        else {
            if (!first_counted) {
                line_cnt++;
                first_counted = 1;
            }
        }
    }

    printf("Here is your requested count:\n\n");
    printf("Lines: %d | Words: %d | Characters: %d\n\n", line_cnt, word_cnt, char_cnt);

    fclose(file);

    return 1;
}

int cmd_search(int argc, char** argv)
{
    return 0;
}

int cmd_cf(int argc, char** argv)
{
    if (argc < 2) {
        printf("Wrong usage of CF command! try again :)\n");
        return 0;
    }
    const char* file_name = argv[1];
    // check if file already exists
    FILE* f = fopen(file_name, "r");
    if (f != NULL) {
        printf("File '%s' already exists. We don't like doubles around here '_'\nUse 'help' command for any help!\n", file_name);
        fclose(f);
        return 0;
    }



    FILE* file_created = fopen(file_name, "w");
    if (file_created == NULL) {
        printf("Couldn't create file '%s'. Use 'help' command for any help!\n", file_name);
        return 0;
    }

    if (argv[2] != NULL) { // there is also content to add to the file
        Buffer bfr;
        for (size_t i = 2; i < argc; i++)
        {
            fprintf(file_created, "%s", argv[i]);
            if (i + 1 != argc)
                fprintf(file_created, " "); // add space if its not the last word
        }
        fprintf(file_created, "\n"); // add new line at the end for cleaner look and usage for later
        printf("File '%s' created successfuly!\nI also place the content inside it as you requested\n", file_name);
    }
    else {
        printf("File '%s' created successfuly!\nGo put some stuff into it. Its lonely :)\n", file_name);
    }
    fclose(file_created);

    return 1;
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

int cmd_clear(int argc, char** argv)
{
    // clears terminal using ANSI Escape Codes
    printf("\033[2J\033[H");
    return 1;
}
