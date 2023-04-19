/*
** EPITECH PROJECT, 2023
** B-MUL-100-RUN-1-1-myradar-hugo.payet
** File description:
** stat_copy
*/
#include "../../my.h"

int stat_copy(char const *str)
{
    int n = 0;
    int size = 0;
    int open_fd = open(str, O_RDONLY);

    if (open_fd == -1)
        return -1;
    char buffer[1];
    while ((n = read(open_fd, buffer, 1)) > 0)
        size += n;
    close(open_fd);
    return (size);
}
