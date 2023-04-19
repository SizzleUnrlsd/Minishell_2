/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** init_struct_all
*/
#include "../../my.h"

all_struct_t *init_all(void)
{
    all_struct_t *all = malloc(sizeof(all_struct_t));
    if (all == NULL)
        exit(84);
    bool print = isatty(0);
    *all = (all_struct_t){
        .several_arg_builtin = NULL,
        .built_all_type_env = 0,
        .command_not_found = 0,
        .built_nothing = 0,
        .set_env = NULL,
        .built_exit = 0,
        .print = print,
        .get_line = 0,
        .len_arg = 0,
        .binary = 0,
        .status = 0,
        .mode = -1,
        .io = 0
    };
    return all;
}
