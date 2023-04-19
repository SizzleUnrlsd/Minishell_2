/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** ast_final
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../../my.h"

void evaluate_ast(node_t *node, all_struct_t *all, char **env)
{
    char **arg = NULL;
    if (node == NULL) return;
    switch (node->type) {
        case NODE_SEMICOLON:
            evaluate_ast(node->left, all, env);
            evaluate_ast(node->right, all, env); break;
        case NODE_PIPE:
            execute_pipeline(node->left, node->right, all, env); break;
        case NODE_REDIRECT_IN:
        case NODE_REDIRECT_OUT:
        case NODE_REDIRECT_APPEND:
            redirection_append(node, all, env); break;
        case NODE_ARGUMENT:
                arg = parse_stdin(my_strdup(node->value, all), all);
                execute_command(arg, env, all); break;
        default:
            bye(all);
    }
}

int ast_final(char *command, all_struct_t *all, char **env)
{
    node_t *root = parse_semicolon(&command);
    garbage_collector(root, all);
    evaluate_ast(root, all, env);
    return 0;
}
