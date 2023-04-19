/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** pwd_oldpwd_in_env
*/
#include "../../../my.h"

int pwd_already_ini_env(all_struct_t *all, char *str)
{
    int len_word = my_strlen(str);
    char **env = all->set_env->env_array;

    for (int i = 0; env[i]; i++)
        if (my_strncmp(str, env[i], len_word) == 0)
            return 1;
    return 0;
}
