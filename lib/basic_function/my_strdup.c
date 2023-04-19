/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup
*/
#include <stdio.h>
#include <stdlib.h>
#include "../../my.h"

char *my_strdup(char const *src,  all_struct_t *all)
{
    int32_t a = 0;
    char *dest = NULL;

    dest = (char*)malloc_attribut(sizeof(char) * (my_strlen(src) + 1), all);
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
