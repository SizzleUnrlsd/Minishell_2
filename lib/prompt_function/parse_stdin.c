/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** parse_stdin
*/
#include "../../my.h"

void free_ptr(char **arg)
{
    for (int32_t i = 0; arg[i]; i++) {
        free(arg[i]);
        arg[i] = NULL;
    }
    return;
}

char **parse_stdin(char *command, all_struct_t *all)
{
    int32_t a = 0, count = 0;
    char **clean_arg = NULL;
    char **arg = my_str_to_word_array_custom_double(all, command, ' ', '\t');

    for (int32_t i = 0; arg[i]; i++)
        if ((my_strcmp(arg[i], " ") != 0) || (my_strcmp(arg[i], "\t") != 0))
            a++;
    clean_arg = (char **)malloc_attribut(sizeof(char *) * (a + 1), all);
    for (int32_t i = 0; arg[i]; i++) {
        if ((my_strcmp(arg[i], " ") != 0) || (my_strcmp(arg[i], "\t") != 0)) {
            clean_arg[count] = my_strdup(arg[i], all);
            count++;
        }
    }
    remove_back_n(clean_arg[a - 1]);
    clean_arg[a] = NULL;
    free_ptr(arg);
    arg = NULL;
    return clean_arg;
}
