/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** reset_var_shell
*/
#include "../../my.h"

void reset_var_shell(all_struct_t *all)
{
    all->command_not_found = 0;
    all->binary = 0;
    all->built_all_type_env = 0;
    all->built_exit = 0;
    free(all->get_line);
    all->get_line = NULL;
    all->len_arg = 0;
}
