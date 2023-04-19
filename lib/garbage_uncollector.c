/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** garbage_uncollector
*/
#include "../my.h"

void garbage_uncollector(garbage_collector_t *garbage)
{
    if (garbage->pointer == NULL)
        return;
    else {
        free(garbage->pointer);
        garbage->pointer = NULL;
    }
    return;
}
