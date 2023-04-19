/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** char_isspace
*/
#include "../../my.h"

int char_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' ||
        c == '\r' || c == '\f' || c == '\v')
        return 1;
    else
        return 0;
}
