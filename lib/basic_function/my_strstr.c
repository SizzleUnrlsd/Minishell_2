/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** strstr
*/
#include "../../my.h"

char *my_strstr(const char *haystack, const char *needle)
{
    char *p = (char *) haystack;
    size_t needle_len = my_strlen(needle);

    while (*p) {
        if (strncmp(p, needle, needle_len) == 0)
            return p;
        p++;
    }
    return NULL;
}
