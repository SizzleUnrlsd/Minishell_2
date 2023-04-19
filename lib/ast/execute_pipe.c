/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** execute_pipe
*/
#include "../../my.h"

void finish_pipi(int32_t pipefd[2], pid_t pid1, pid_t pid2)
{
    close(pipefd[0]);
    close(pipefd[1]);

    int32_t status = 0;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
}

pid_t pid_one(int32_t pipefd[2], all_struct_t *all,
            char **env, node_t *cmd1_node)
{
    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        evaluate_ast(cmd1_node, all, env);
        exit(EXIT_FAILURE);
    } else if (pid1 < 0) {
        exit(1);
    }
    return pid1;
}

pid_t pid_two(int32_t pipefd[2], all_struct_t *all,
            char **env, node_t *cmd2_node)
{
    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        evaluate_ast(cmd2_node, all, env);
        exit(EXIT_FAILURE);
    } else if (pid2 < 0) {
        exit(1);
    }
    return pid2;
}

void execute_pipeline(node_t *cmd1_node, node_t *cmd2_node,
                        all_struct_t *all, char **env)
{
    int32_t pipefd[2] = {0};
    if (pipe(pipefd) < 0) {
        return;
    }
    pid_t pid1 = pid_one(pipefd, all, env, cmd1_node);
    pid_t pid2 = pid_two(pipefd, all, env, cmd2_node);
    finish_pipi(pipefd, pid1, pid2);
}
