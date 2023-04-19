/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** my_get_key
*/
#include "../../my.h"

int my_get_key(int a, char *str)
{
    char buffer[a];
    int rd = read(STDIN_FILENO, buffer, a);
    buffer[rd - 1] = '\0';
    if (my_strcmp(buffer, str) == 0) {
        return 0;
    }
    return 1;
}
