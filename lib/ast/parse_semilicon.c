/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** parse_semilicon
*/
#include "../../my.h"

node_t *parse_semicolon(char **input)
{
    node_t *left = parse_pipe(input);
    if (**input == ';') {
        (*input)++;
        node_t *right = parse_semicolon(input);
        return create_node(NODE_SEMICOLON, NULL, left, right);
    }
    return left;
}
