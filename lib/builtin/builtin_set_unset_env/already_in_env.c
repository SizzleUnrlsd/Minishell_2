/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** already_in_env
*/
#include "../../../my.h"

int already_in_inv_mode_zero(all_struct_t *all, int *a, int count, int e)
{
    char **first_step = NULL;
    char **arg = parse_stdin(all->get_line, all);
    format_arg(arg);
    char **env = all->set_env->env_array;

    if (arg[1][0] == '\0')
        count = -100000;
    for (int i = 0; env[i]; i++) {
        first_step = my_str_to_word_array_custom
        (all, env[i], '=');
        if (my_strcmp(first_step[0], arg[e]) == 0 && my_strlen(arg[e]) > 0) {
            a[e - 1] = i;
            continue;
        } else {
            count++;
        }
    }
    return count;
}

void already_in_env_mode_one(all_struct_t *all, int *a, int i, int count)
{
    int e = 1;
    char **first_step = NULL;
    char **arg = parse_stdin(all->get_line, all);
    format_arg(arg);
    first_step = my_str_to_word_array_custom
    (all, all->set_env->env_array[i], '=');
    if (my_strcmp(first_step[0], arg[1]) == 0) {
        a[e - 1] = i;
    } else {
        count++;
    }
    return;
}

int already_in_env(all_struct_t *all, int mode)
{
    int e = 1; int count = 0; char **arg = parse_stdin(all->get_line, all);
    char **env = all->set_env->env_array; format_arg(arg);
    all->several_arg_builtin =
    (int*)malloc_attribut(sizeof(int) * len_array(arg), all);
    int *a = all->several_arg_builtin;
    for (int i = 0; i != len_array(arg); i++)
        a[i] = -1;
    if (mode == 0) {
        for (; arg[e]; e++)
            count = already_in_inv_mode_zero(all, a, count, e);
        a[e - 1] = -1;
        sort_in_int_array(a, len_array(arg) - 1);
        return count;
    }
    if (mode == 1) {
        for (int i = 0; env[i]; i++)
            already_in_env_mode_one(all, a, i, count);
        a[e] = -1;
    }
    return 0;
}
