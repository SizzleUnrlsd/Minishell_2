/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** concat_char_str
*/
#include "../../my.h"

char *concat_char_str(char concat, char *str, int futur, int a)
{
    uint32_t len_str = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len_str + futur + 2));

    if (a == 0) {
        dest[0] = concat;
        for (uint32_t i = 1; i != len_str + 1; i++)
            dest[i] = str[i - 1];
    }
    if (a == 1) {
        for (uint32_t i = 0; i != len_str + 1; i++)
            dest[i] = str[i];
        dest[len_str] = concat;
    }
    dest[len_str + 1] = '\0';
    return dest;
}
