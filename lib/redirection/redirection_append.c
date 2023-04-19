/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** redirection_append
*/
#include "../../my.h"

void redirection_append_extend(node_t *node, ...)
{
    va_list ap;
    va_start(ap, node);
    all_struct_t *all = va_arg(ap, all_struct_t *);
    char **env = va_arg(ap, char **);
    int fd = va_arg(ap, int);
    char **args = va_arg(ap, char **);

    if (node->type == NODE_REDIRECT_IN) {
        dup2(fd, STDIN_FILENO);
    } else {
        dup2(fd, STDOUT_FILENO);
    }
    close(fd);
    execute_command(args, env, all);
    exit(0);
    va_end(ap);
    return;
}

void del_space_end_str(char *str)
{
    int i = strlen(str) - 1;
    while (i >= 0 && (str[i] == ' ' || str[i] == '\t')) {
        str[i] = '\0';
        i--;
    }
}

void redirection_append_extend_extend(node_t *node, char *file, int32_t *fd)
{
    if (node->type == NODE_REDIRECT_OUT) {
        *fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    } else if (node->type == NODE_REDIRECT_APPEND) {
        *fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    } else {
        *fd = open(file, O_RDONLY);
    }
    if (*fd < 0) {
        exit(0);
    }
    return;
}

void redirection_append(node_t *node, all_struct_t *all, char **env)
{
    pid_t pid = fork();
    if (pid < 0) {
        return;
    }
    if (pid == 0) {
        int32_t fd = 0; char *args[128] = {0};
        char *cmd = node_to_string(node->left, all);
        char *file = node_to_string(node->right, all);
        file = remove_space_before_string(file, all);
        remove_back_n(file);
        remove_newline(cmd);
        del_space_end_str(file);
        parse_command(cmd, args);
        redirection_append_extend_extend(node, file, &fd);
        redirection_append_extend(node, all, env, fd, args);
    } else {
        int32_t status = 0;
        waitpid(pid, &status, 0);
    }
    return;
}
