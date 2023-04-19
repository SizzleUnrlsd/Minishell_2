/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** char_isdigit
*/
#include "../../my.h"

int char_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}
