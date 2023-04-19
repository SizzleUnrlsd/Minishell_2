/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** add_line_to_array
*/
#include "../../../my.h"

char *set_unset_env_ext(int i, char **arg, char **env, char *second_step)
{
    int fmall = my_strlen(arg[2]);

    second_step = concat_char_str('=', arg[1], fmall, 1);
    env[i] = second_step;
    env[i] = my_strcat(env[i], arg[2]);
    return env[i];
}

void set_unset_in_env(all_struct_t *all, char **env, int len_arg)
{
    int i = 0;
    char *second_step = NULL; char **arg = parse_stdin(all->get_line, all);
    char **first_step =
    (char**)malloc_attribut(sizeof(char *) * len_array(env) + 2, all);
    i = function_set_param_env(i, env, first_step, all);
    for (int i = 0; env[i]; i++) {
        first_step = my_str_to_word_array_custom
        (all, all->set_env->env_array[i], '=');
        if ((my_strcmp(first_step[0], arg[1]) == 0) && len_arg == 3) {
            free_attribut(env[i], all);
            garbage_collector(set_unset_env_ext(i, arg, env, second_step), all);
        }
        if ((my_strcmp(first_step[0], arg[1]) == 0) && len_arg == 2) {
            arg[2] = " ";
            free_attribut(env[i], all);
            set_unset_env_ext(i, arg, env, second_step);
        }
    }
    return;
}

void set_in_env_full(all_struct_t *all, char **env, int len_arg, int in_env)
{
    int i = 0, fmall = 0;

    if (len_arg == 3 && in_env == -3) {
        char *second_step = NULL;
        char **arg = parse_stdin(all->get_line, all);
        char **first_step =
        (char**)malloc_attribut(sizeof(char *) * (len_array(env) + 2), all);
        fmall = my_strlen(arg[2]);

        i = function_set_param_env(i, env, first_step, all);

        second_step = concat_char_str('=', arg[1], fmall, 1);
        garbage_collector(second_step, all);
        first_step[i] = my_strcat(second_step, arg[2]);
        first_step[i + 1] = NULL;
        free_attribut(all->set_env->env_array, all);
        all->set_env->env_array = first_step;
    }
    return;
}

void set_in_env_empty(all_struct_t *all, char **env, int len_arg, int in_env)
{
    int i = 0;
    if (len_arg == 2 && in_env == -3) {
        char **arg = parse_stdin(all->get_line, all);
        char **first_step =
        (char**)malloc_attribut(sizeof(char *) * (len_array(env) + 3), all);

        i = function_set_param_env(i, env, first_step, all);
        first_step[i] = concat_char_str('=', arg[1], 0, 1);
        garbage_collector(first_step[i], all);
        first_step[i + 1] = NULL;
        all->set_env->env_array = first_step;
    }
    return;
}

void add_line_to_array(all_struct_t *all, int len_arg, int in_env)
{
    char **env = all->set_env->env_array;

    set_in_env_empty(all, env, len_arg, in_env);
    set_in_env_full(all, env, len_arg, in_env);
    if ((len_arg == 3 || len_arg == 2) && in_env != -3)
        set_unset_in_env(all, env, len_arg);
    return;
}
