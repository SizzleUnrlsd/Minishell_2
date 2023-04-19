/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** free_attribut
*/
#include "../my.h"

void free_attribut(void *p, all_struct_t *all)
{
    unsigned int i = 0;
    for (; all->garbage[i]; i++)
        if (i > 0 && all->garbage[i - 1]->index < all->garbage[i]->index)
            continue;
        else
            break;
    for (unsigned int index = 0; index != i; index++)
        if (all->garbage[index]->pointer == p)
                garbage_uncollector(all->garbage[index]);
    return;
}
