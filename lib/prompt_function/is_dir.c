/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** is_dir
*/
#include "../../my.h"

int is_dir(char const *path)
{
    struct stat dir;
    if (stat(path, &dir) == 0) {
        if (S_ISDIR(dir.st_mode))
            return 0;
        else
            return 1;
    }
    return -1;
}
