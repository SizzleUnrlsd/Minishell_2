/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** format_arg
*/
#include "../../my.h"

void format_arg(char **arg)
{
    for (int i = 0; arg[i] != NULL; i++)
        if (arg[i][0] == '\0')
            arg[i] = NULL;
    if (arg[0][my_strlen(arg[0]) - 1] == '\n')
        remove_back_n(arg[0]);
    return;
}
