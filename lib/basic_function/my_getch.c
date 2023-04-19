/*
** EPITECH PROJECT, 2023
** B-PSU-100-RUN-1-1-navy-hugo.payet
** File description:
** my_getch
*/
#include "../../my.h"

char *my_getch(int a)
{
    char buffer[a];
    int rd = read(STDIN_FILENO, buffer, a);
    buffer[rd - 1] = '\0';
    char *str = malloc(sizeof(char) * (rd));
    my_strcpy(str, buffer);
    return (str);
}
