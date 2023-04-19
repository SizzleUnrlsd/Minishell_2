/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** env
*/
#include "../../my.h"

set_env_t *set_env(all_struct_t *all, char **env)
{
    set_env_t *set_env = (set_env_t*)malloc_attribut(sizeof(set_env_t), all);
    int32_t full_size = len_array(env) + 1;
    set_env->env_array = (char**)
    malloc_attribut(sizeof(char *) * full_size, all);

    if ((full_size - 1) == 0)
        return (set_env);

    for (uint32_t i = 0; env[i] != NULL; i++)
        set_env->env_array[i] = my_strdup(env[i], all);

    set_env->env_array[full_size - 1] = NULL;
    return (set_env);
}
