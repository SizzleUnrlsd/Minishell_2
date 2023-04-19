/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** perm_dir
*/
#include "../../../my.h"

int check_perm_dir(all_struct_t *all, char *path)
{
    if (path == NULL) {
        EXIT_W_ECHO_ERROR_(": No such file or directory.", 1);
    }
    if (access(path, F_OK) != 0) {
        print_str(path, 0, true, 2);
        EXIT_W_ECHO_ERROR_(": No such file or directory.", 1);
    }
    if (access(path, R_OK) != 0 && access(path, X_OK) != 0) {
        print_str(path, 0, true, 2);
        EXIT_W_ECHO_ERROR_(": Permission denied.", 1);
        return 1;
    }
    return 0;
}
