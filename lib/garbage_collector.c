/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** garbage_collector
*/
#include "../my.h"

static unsigned int index_int(void)
{
    static u_int32_t a = 0;
    a++;
    return a;
}

void init_struct(garbage_collector_t *garbage)
{
    garbage->index = 0;
    garbage->pointer = NULL;
    return;
}

void garbage_collector_extend(void *p, int index_, all_struct_t *all)
{
    garbage_collector_t *garbage = malloc(sizeof(garbage_collector_t));
    init_struct(garbage);
    garbage->index = index_ - 1;
    all->io++;
    if (p == NULL)
        return;
    garbage->pointer = p;
    all->garbage[index_ - 1] = garbage;
    return;
}

void garbage_collector(void *p, all_struct_t *all)
{
    static size_t acceptance_limit = LEN_ARRAY_STRUCT - 500;
    u_int32_t index_ = index_int();
    if (index_ >= acceptance_limit) {
        acceptance_limit = acceptance_limit + 5000;
        all->garbage = realloc_struct(all->garbage, acceptance_limit, index_);
    }
    garbage_collector_extend(p, index_, all);
    return;
}
