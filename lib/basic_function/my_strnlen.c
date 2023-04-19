/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** my_strnlen
*/
#include "../../my.h"

size_t my_strnlen(const char *s, size_t maxlen)
{
    size_t len = 0;

    while (len < maxlen && s[len] != '\0') {
        len++;
    }

    return len;
}
