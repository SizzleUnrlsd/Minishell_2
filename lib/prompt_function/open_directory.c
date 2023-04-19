/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** open_directory
*/
#include "../../my.h"

static char *arg_formater(char **arg, char *without_n)
{
    for (int32_t i = 0; arg[i] != NULL; i++)
        if (arg[i][0] == '\0')
            arg[i] = NULL;
    if (arg[0][my_strlen(arg[0]) - 1] == '\n') {
        remove_back_n(arg[0]);
    } else
        without_n = arg[0];

    return without_n;
}

int32_t open_directory(all_struct_t *all, char **path, char **arg, char **env)
{
    char *without_n = NULL;
    char *concat_first_step = NULL;
    char *concat_second_step = NULL;
    int32_t fmall = 0;
    without_n = arg_formater(arg, without_n);

    if (path == NULL)
        return 1;
    for (int32_t i = 0; path[i]; i++) {
        fmall = my_strlen(without_n);
        concat_first_step = concat_char_str('/', path[i], fmall, 1);
        concat_second_step = (char *)malloc_attribut(sizeof(char)
        * (my_strlen(concat_first_step) + 1), all);
        concat_second_step = my_strcat(concat_first_step, without_n);
        execve(concat_second_step, arg, env);
        free(concat_second_step);
    }
    return 0;
}
