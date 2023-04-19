/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** malloc_attribut
*/
#include "../../my.h"

void *malloc_attribut(size_t size, all_struct_t *all)
{
    void *p = malloc(size);
    if (p == NULL)
        exit(84);
    (void) all;
    garbage_collector(p, all);
    return p;
}
