/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell2-hugo.payet
** File description:
** parse_argument
*/
#include "../../my.h"

node_t *parse_argument(char **input)
{
    char *start = *input;
    while (**input != '\0' && **input != '|'
        && **input != ';' && **input != '>' && **input != '<') {
            (*input)++;
    }
    char *value = my_strndup(start, *input - start);
    return create_node(NODE_ARGUMENT, value, NULL, NULL);
}
