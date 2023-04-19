/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** create_node
*/
#include "../../my.h"

node_t *create_node(nodetype type, char *value, node_t *left, node_t *right)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
        exit(84);

    *node = (node_t){
        .type = type,
        .value = value,
        .left = left,
        .right = right
    };
    return node;
}
