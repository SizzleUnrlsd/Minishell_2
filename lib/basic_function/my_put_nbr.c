/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** my_put_nbr
*/
#include "../../my.h"

int my_put_nbr(long nb)
{
    long max = 1;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-', 1);
    }
    while (nb / max >= 10) {
        max = max * 10;
    }
    while (max != 0) {
        my_putchar((nb / max + 48), 1);
        nb = nb % max;
        max /= 10;
    }
    return nb;
}
