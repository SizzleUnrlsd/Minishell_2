/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** format_getline
*/
#include "../../my.h"

uint32_t find_last(char *command, unsigned char *last_char)
{
    uint32_t spe_count = 0;
    for (uint32_t j = 0; command[j]; j++) {
        if (command[j] == '|') {
            spe_count = j;
            (*last_char) = '|';
        }
        if (command[j] == '>') {
            spe_count = j;
            (*last_char) = '>';
        }
        if (command[j] == '<') {
            spe_count = j;
            (*last_char) = '<';
        }
    }
    return spe_count;
}

bool format_getline(all_struct_t *all, char *command)
{
    unsigned char last_char = 0;
    uint32_t len_command = my_strlen(command);
    uint32_t index_spe_cmmd = find_last(command, &last_char);
    if (command[len_command - 1] == '\n') {
        command[len_command - 1] = '\0';
        len_command = len_command - 2;
    }
    if (len_command == index_spe_cmmd && last_char == '|') {
        EXIT_W_ECHO_ERROR_("Invalid null command.", 1);
    }
    if (len_command == index_spe_cmmd &&
        (last_char == '>'|| last_char == '<')) {
        EXIT_W_ECHO_ERROR_("Missing name for redirect.", 1);
    }
    return false;
}
