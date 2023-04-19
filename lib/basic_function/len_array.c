/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** len_array
*/
#include "../../my.h"

int len_array(char **array)
{
    size_t len = 0;
    int i = 0;
    if (array == NULL)
        return 1;
    for (; array[i] != NULL; i++) {
        len++;
    }
    return len;
}
