/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** task01
*/
#include <string.h>
#include "../../my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
