/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** my_strndup
*/
#include "../../my.h"

static void *my_memcpy(void *dest, const void *src, size_t n)
{
    if (dest == NULL || src == NULL)
        return NULL;
    char *d = dest;
    const char *s = src;

    size_t i = 0;
    do {
        d[i] = s[i];
        i++;
    } while (i < n);

    return dest;
}

char *my_strndup(const char *s, size_t n)
{
    size_t len = my_strnlen(s, n);
    char *new_str = (char *) malloc(len + 1);

    if (new_str == NULL) {
        return NULL;
    }

    my_memcpy(new_str, s, len);
    new_str[len] = '\0';

    return new_str;
}
