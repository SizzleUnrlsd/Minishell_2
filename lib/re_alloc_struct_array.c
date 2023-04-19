/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** re_alloc_struct_array
*/
#include "../my.h"

garbage_collector_t **realloc_struct(garbage_collector_t **p,
                                size_t size, unsigned int len)
{
    unsigned int i = 0;
    garbage_collector_t **p_nouveau =
    malloc(sizeof(garbage_collector_t *) * (size));
    for (; p[i]; i++) {
        if (i == LEN_ARRAY_STRUCT)
            break;
        p_nouveau[i] = malloc(sizeof(garbage_collector_t));
        p_nouveau[i]->index = p[i]->index;
        p_nouveau[i]->pointer = p[i]->pointer;
        free(p[i]);
    }
    i++;
    for (; i != len; i++) {
        p_nouveau[i] = malloc(sizeof(garbage_collector_t));
        p_nouveau[i]->index = 0;
        p_nouveau[i]->pointer = NULL;
    }
    free(p);
    return p_nouveau;
}
