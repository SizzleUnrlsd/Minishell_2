/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** is_bin
*/
#include "../../my.h"

int is_bin(char const *path)
{
    char c = '\0';
    int count = 0;
    int seuil = 5;
    struct stat st;
    int fd = open(path, O_RDONLY);
    int len_file = stat_copy(path);

    if (fd == -1 || fstat(fd, &st) == -1)
        return 1;
    while (read(fd, &c, 1) == 1) {
        if (!char_isalpha(c) && !char_isdigit(c) && !char_isspace(c))
            count++;
    }
    if (count > (seuil * len_file / 100))
        return 0;
    else
        return 1;
    close(fd);
    return -1;
}
