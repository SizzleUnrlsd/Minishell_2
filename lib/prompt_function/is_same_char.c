/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** is_same_char
*/
#include "../../my.h"

int is_same_char(char const *path)
{
    char c = '\0';
    char h = ' ';
    char a = '\t';
    char r = '\n';
    int count = 0;
    struct stat st;
    int fd = open(path, O_RDONLY);
    int len_file = stat_copy(path);
    if (len_file == 0)
        return 0;
    if (fd == -1 || fstat(fd, &st) == -1)
        return 1;
    while (read(fd, &c, 1) == 1) {
        if (c == h || c == a || c == r)
            count++;
    }
    if (count == len_file)
        return 0;
    close(fd);
    return -1;
}
