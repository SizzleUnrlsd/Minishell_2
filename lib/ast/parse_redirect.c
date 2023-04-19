/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** parse_redirect
*/
#include "../../my.h"

void parse_redirect_extend(char **input, nodetype *type)
{
    if (**input == '>') {
        *type = NODE_REDIRECT_APPEND;
        (*input)++;
    } else {
        *type = NODE_REDIRECT_OUT;
    }
    return;
}

void parse_redirect_extend_extend(char **input, nodetype *type)
{
    if (**input == '<') {
        *type = NODE_REDIRECT_DUP_IN;
        (*input)++;
    } else {
        *type = NODE_REDIRECT_IN;
    }
    return;
}

node_t *parse_redirect(char **input)
{
    node_t *left = parse_argument(input);
    nodetype type;
    if (**input == '>') {
        (*input)++;
        parse_redirect_extend(input, &type);
    } else if (**input == '<') {
        (*input)++;
        parse_redirect_extend_extend(input, &type);
    } else
        return left;
    node_t *right = parse_redirect(input);
    return create_node(type, NULL, left, right);
}
