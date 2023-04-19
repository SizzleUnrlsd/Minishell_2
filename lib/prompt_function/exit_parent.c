/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** exit_parent
*/
#include "../../my.h"

void parent_exit(all_struct_t *all, int wstatus)
{
    if (RD_TTY == 0 && wstatus == 256)
        exit(1);
    if (RD_TTY == 0 && wstatus != 0)
        exit(wstatus);
    return;
}
