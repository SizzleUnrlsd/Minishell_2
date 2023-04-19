/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** access_file
*/
#include "../../my.h"

int32_t find_wrong_exe(char *path)
{
    for (; *path; path++)
        if (my_strncmp(path, "exe", 3) == 0)
            return 0;
    return -1;
}

int32_t access_file_extend(all_struct_t *all, char **path)
{
    if (is_dir(path[0]) == 0) {
        my_putstr(path[0], 2);
        EXIT_W_ECHO_ERROR_(": Permission denied.", 1)
    }
    if (access(path[0], F_OK) == 0 && access(path[0], X_OK) == 0
            && is_bin(path[0]) == 0 && find_wrong_exe(path[0]) == 0) {
        my_putstr(path[0], 2);
        my_putstr(": ", 2);
        my_putstr(path[0], 2);
        EXIT_W_ECHO_ERROR_(": Exec format error. Wrong Architecture.", 1);
    }
    return 0;
}

int32_t access_file(all_struct_t *all, char **path, char **env)
{
    format_arg(path);
    if (access_file_extend(all, path) == 1)
        return 1;
    if (access(path[0], F_OK) == 0 && access(path[0], X_OK) == 0
                                    && is_same_char(path[0]) == 0)
        exit(0);
    if (access(path[0], F_OK) == -1) {
        print_str(path[0], 0, true, 2);
        EXIT_W_ECHO_ERROR_(": Command not found.", 1)
    } else if (access(path[0], X_OK) == -1) {
        my_putstr(path[0], 2);
        EXIT_W_ECHO_ERROR_(": Permission denied.", 1);
    } else {
        execve(path[0], path, env);
    }
    return 0;
}
