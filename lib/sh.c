/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** my_sh
*/
#include "../my.h"

int32_t main(int32_t ac, char **av, char **env)
{
    (void) av;
    if (ac != 1)
        return 84;
    all_struct_t *all = init_all();
    all->garbage = malloc(sizeof(garbage_collector_t *) * LEN_ARRAY_STRUCT);
    set_env_t *env_set = set_env(all, env);
    all->set_env = env_set;
    ENV_PATH = cut_path_env(all, ENV_SET_ARRAY);
    while (true) {
        reset_var_shell(all);
        if (prompt_shell(all))
            break;
        if (format_getline(all, all->get_line))
            continue;
        if (my_strcmp(all->get_line, "\n") == 0)
            continue;
        ast_final(all->get_line, all, env);
    }
    return 0;
}
