/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-hugo.payet
** File description:
** my_str_to_word_array_custom_puissance
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../my.h"

int funct_count_double(char *str, char c, char x)
{
    int i = 0, e = 0;

    while (str[i] != '\0') {
        if (str[i] == c || str[i] == x)
            e++;
        i++;
    }
    return (e);
}

char **funct_malloc_double(char *str, char c, char x, char **array)
{
    int i = 0, n = 0, a = 0;

    while (str[i] != '\0') {
        if (str[i] == c || str[i] == x) {
            array[a] = malloc(sizeof(char) * (n + 1));
            array[a][n] = '\0';
            a++;
            n = 0;
            i++;
        } else {
            n++;
            i++;
        }
    }
    array[a] = malloc(sizeof(char) * (n + 1));
    array[a][n] = '\0';
    return (array);
}

char **funct_add_char_double(char *str, char c, char x, char **array)
{
    int i = 0, n = 0, a = 0;

    while (str[i] != '\0') {
        if (str[i] == c || str[i] == x) {
            n = 0;
            a++;
            i++;
        } else {
            array[a][n] = str[i];
            n++;
            i++;
        }
    }
    array[a][n] = str[i];
    return (array);
}

char **my_str_to_word_array_custom_double(all_struct_t *all, char *str,
                                        char c, char x)
{
    (void) all;
    int stock = funct_count_double(str, c, x);
    char **array = (char**)malloc_attribut(sizeof(char*) * (stock + 2), all);
    array = funct_malloc_double(str, c, x, array);
    array = funct_add_char_double(str, c, x, array);
    array[stock + 1] = NULL;

    return (array);
}
