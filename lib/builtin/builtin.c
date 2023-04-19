/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** builtin
*/
#include "../../my.h"

bultin_list_t builtin_list[] = {
    {"echo", &echo},
    {"cd", &builtin_cd},
    {"env", &builtin_env},
    {"exit", &builtin_exit},
    {"setenv", &builtin_setenv},
    {"unsetenv", &builtin_unsetenv},
    {0, NULL},
};

int32_t builtin(all_struct_t *all, char **path, int32_t *rd_builtin)
{
    if (path[0][0] == 0) {
        all->built_nothing++;
        *rd_builtin = 3;
        return 0;
    } else {
        *rd_builtin = 0;
    }
    for (int32_t i = 0; builtin_list[i].index; i++) {
        if (my_strcmp(path[0], builtin_list[i].index) == 0) {
            builtin_list[i].function(all, path[0]);
        }
    }
    return 0;
}
