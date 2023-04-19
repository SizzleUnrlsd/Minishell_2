/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** remove_last_char
*/
#include "../../my.h"

char *del_one_char(all_struct_t *all, char **src, char *dest)
{
    dest = (char*)malloc_attribut(sizeof(char) * (my_strlen(src[0])), all);
    dest = my_strncpy(dest, src[0], 2);

    return dest;
}

char *remove_back_n(char *src)
{
    int len = my_strlen(src);
    if (src[len - 1] != '\n')
        return src;
    if (len > 0)
        src[len - 1] = '\0';
    return src;
}
