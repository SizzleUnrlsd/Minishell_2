/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** function_set_param_env
*/
#include "../../../my.h"

int function_set_param_env(int i, char **env,
        char **first_step,  all_struct_t *all)
{
    for (; env[i]; i++)
        first_step[i] = my_strdup(env[i], all);
    return i;
}
