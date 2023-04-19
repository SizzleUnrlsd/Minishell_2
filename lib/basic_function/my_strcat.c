/*
** EPITECH PROJECT, 2022
** str
** File description:
** cat
*/
#include <stdio.h>
#include "../../my.h"

char *my_strcat(char *dest, char const *src)
{
    int cmpt = 0;
    int size = my_strlen(dest);

    while (src != NULL && src[cmpt] != '\0') {
        dest[size] = src[cmpt];
        cmpt++;
        size++;
    }
    dest[size] = '\0';
    return dest;
}
