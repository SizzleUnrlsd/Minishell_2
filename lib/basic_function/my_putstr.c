/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** display a string
*/
#include "../../my.h"
#include <unistd.h>

int my_putstr(char const *str, int fd)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i], fd);
        i = i + 1;
    }
    return 0;
}
