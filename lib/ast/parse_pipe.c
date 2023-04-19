/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** parse_pipe
*/
#include "../../my.h"

node_t *parse_pipe(char **input)
{
    node_t *left = parse_redirect(input);
    if (**input == '|') {
        (*input)++;
        node_t *right = parse_pipe(input);
        return create_node(NODE_PIPE, NULL, left, right);
    }
    return left;
}
