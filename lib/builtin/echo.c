/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** echo
*/
#include "../../my.h"

int echo(all_struct_t *all, char *str)
{
    (void) str;
    all->command_not_found++;
    all->built_all_type_env++;
    char **arg = parse_stdin(all->get_line, all);
    int len_arg = len_array(parse_stdin(all->get_line, all));
    if (len_arg == 1) {
        print_str("\n", 0, RD_TTY, 1);
        return 0;
    }
    if (my_strcmp(arg[1], "$?") == 0) {
        my_put_nbr(all->status);
        my_putchar('\n', 1);
    }
    all->status = 0;
    return 0;
}
