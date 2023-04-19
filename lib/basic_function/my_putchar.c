/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** putchar
*/
#include <unistd.h>
#include "../../my.h"

char my_putchar(char c, int fd)
{
    write(fd, &c, 1);
    return 0;
}
