/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** my_strcmp
*/

#include <stdio.h>
#include "../../my.h"

int32_t cmp_string(char s1, char s2)
{
    if (s1 < s2) {
        return (-1);
    }
    return (1);
}

int32_t my_strcmp(char const *s1, char const *s2)
{
    int32_t n = 0;
    int32_t len_s1 = my_strlen(s1);
    int32_t len_s2 = my_strlen(s2);

    if (s1[0] == '\0')
        len_s1 = 1;
    else if (s2[0] == '\0')
        len_s2 = 1;

    if (len_s1 != len_s2)
        return (-1);

    while (s1[n] != '\0' && (s2[n]) != '\0') {
        if (s1[n] != s2[n])
            return cmp_string(s1[n], s2[n]);
        n++;
    }
    return (0);
}
