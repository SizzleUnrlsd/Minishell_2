/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** builtin_setenv_ext
*/
#include "../../../my.h"

void builtin_setenv_ext(all_struct_t *all, int len_arg,
                        int in_env, int mode_builtin)
{
    int count = 0;
    for (int i = 0; i != len_arg; i++)
        if (all->several_arg_builtin[i] == -1)
            count++;

    if (mode_builtin == 0)
        if (count == len_array(parse_stdin(all->get_line, all)) - 1)
            in_env = -3;
    if (mode_builtin == 1)
        if (count == len_array(parse_stdin(all->get_line, all)))
            in_env = -3;
    add_line_to_array(all, len_arg, in_env);
    return;
}
