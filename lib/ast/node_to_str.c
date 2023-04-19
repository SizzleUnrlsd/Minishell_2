/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** node_to_str
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

char *node_to_string(node_t *node, all_struct_t *all)
{
    if (node == NULL || node->type != NODE_ARGUMENT) {
        return NULL;
    }
    return my_str_dup(node->value, all);
}
