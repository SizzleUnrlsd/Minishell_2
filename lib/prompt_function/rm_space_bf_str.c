/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** rm_space_bf_str
*/
#include "../../my.h"

static char *my_str_dup(char const *src, all_struct_t *all)
{
    int a = 0;
    char *dest = NULL;

    dest = (char*)malloc_attribut(sizeof(char) * (my_strlen(src) + 1), all);
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char *remove_space_before_string(const char *str, all_struct_t *all)
{
    if (str == NULL) {
        return NULL;
    }
    while (*str != '\0' && (*str == ' ' || *str == '\t')) {
        str++;
    }
    return my_str_dup(str, all);
}
