/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** exec_cmd
*/
#include "../../my.h"

void execute_command(char **arg, char **env, all_struct_t *all)
{
    int32_t rd_builtin = 0;
    builtin(all, arg, &rd_builtin);
    if (BUILT_INT_EXIT != 0)
        exit(0);
    if (ALL_ENV == 0 && rd_builtin == 0 && BINARY == 0)
        prompt_function(all, all->set_env, env, arg);
}
