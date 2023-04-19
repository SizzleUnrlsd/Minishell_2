/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** builtin_unsetenv_ext
*/
#include "../../../my.h"

int unset_env(all_struct_t *all, int in_env, int *a, int index)
{
    (void) in_env;
    int i = 0, j = 0;
    char **env = all->set_env->env_array;
    for (; i < len_array(env); i++) {
        if (a[index] == -1) {
            return 1;
        }
        if (my_strcmp(env[i], env[a[index]]) != 0)
            env[j++] = env[i];
    }
    env[j] = NULL;
    return 0;
}

int builtin_unsetenv_loop(all_struct_t *all, int *a, int in_env, int len_arg)
{
    for (int e = 0; e != len_arg - 1; e++) {
        if (unset_env(all, in_env, a, e) == 1)
            continue;
        for (int i = 0; i != len_arg; i++)
            a[i] = a[i] - 1;
    }
    return 0;
}

void builtin_unsetenv_ext(all_struct_t *all, int in_env, int len_arg)
{
    int count = 0;

    for (int i = 0; all->several_arg_builtin[i] != -1; i++)
        if (all->several_arg_builtin[i] == -1)
            count++;
    if (count == len_arg - 1)
        in_env = -3;
    if (in_env == -3)
        return;

    if (in_env != -3) {
        int *a = all->several_arg_builtin;
        if (builtin_unsetenv_loop(all, a, in_env, len_arg) == 1)
            return;
    }
    return;
}
