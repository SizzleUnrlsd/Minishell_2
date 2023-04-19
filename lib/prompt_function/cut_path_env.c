/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** cut_path_env
*/
#include "../../my.h"

void free_wh_garbage(char **full_env)
{
    for (int i = 0; full_env[i]; i++) {
        free(full_env[i]);
        full_env[i] = NULL;
    }
    free(full_env);

    return;
}

void free_w_garbage(all_struct_t *all, char **path)
{
    for (int i = 0; path[i]; i++)
        garbage_collector(path[i], all);
    garbage_collector(path, all);
    return;
}

void free_specific(all_struct_t *all, char **full_env)
{
    for (int i = 0; full_env[i]; i++) {
        free_attribut(full_env[i], all);
        full_env[i] = NULL;
    }
    free_attribut(full_env, all);
}

char **cut_path_env(all_struct_t *all, char **array)
{
    char **path = NULL;
    char **full_env = NULL;
    int len_arr = len_array(array);
    if (len_arr == 0)
        return NULL;
    int integer_path = 0;
    for (int i = 0; array[i] != NULL; i++) {
        full_env = my_str_to_word_array_custom(all, array[i], '=');
        if (my_strcmp(full_env[0], "PATH") == 0) {
            integer_path = 1;
            break;
        }
        free_specific(all, full_env);
    }
    if (integer_path == 0)
        return full_env;
    path = my_str_to_word_array_custom(all, full_env[1], ':');
    full_env = NULL;
    return path;
}
