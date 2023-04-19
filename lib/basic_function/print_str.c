/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** print_str
*/
#include "../../my.h"

void print_str(char const *str, char c, bool print, int fd)
{
    if (print == true) {
        my_putstr(str, fd);
        if (c != 0)
            my_putchar(c, fd);
    }
    return;
}
