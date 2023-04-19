/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** error_case_dollar_arg
*/
#include "../../../my.h"

int error_case_dollar_arg_extend_plus(all_struct_t *all, char **arg,
                                    int i, int e)
{
    if ((arg[e][i] > 32 && arg[e][i] < 47)
    || (arg[e][i] > 57 && arg[e][i] < 61)
    || (arg[e][i] > 61 && arg[e][i] < 65)
    || (arg[e][i] > 90 && arg[e][i] < 95)) {
        EXIT_W_ECHO_ERROR_(ERROR_SETENV_LAST_DOLLAR, 1);
    }
    return 0;
}

int error_case_dollar_arg_extend_s(all_struct_t *all, char **arg, int i, int e)
{
    int len_str_arg = my_strlen(arg[e]) - 1;
    if (char_isalpha(arg[e][len_str_arg]) == 0 &&
        char_isdigit(arg[e][len_str_arg]) == 0
        && arg[e][len_str_arg] != '_') {
        EXIT_W_ECHO_ERROR_(ERROR_SETENV_LAST_DOLLAR, 1);
    }
    if (arg[e][i] == '$') {
        for (; arg[e][i]; i++)
            my_putchar(arg[e][i + 1], 2);
        EXIT_W_ECHO_ERROR_(ERROR_SET_UNSET_DOLLAR, 1);
    }
    if (arg[1][i] == '=') {
        EXIT_W_ECHO_ERROR_(ERROR_SETENV_LAST_DOLLAR, 1);
    }
    error_case_dollar_arg_extend_plus(all, arg, i, e);
    return 0;
}

int error_case_no_str_is_alpha_extend(all_struct_t *all, char **arg,
                                    int e, int pass)
{
    for (int i = 0; arg[e][i]; i++) {
        (error_case_dollar_arg_extend_s(all, arg, i, e) == 1 ?
        pass = 1 : 0);
        if (pass == 1)
            break;
    }
    if (pass == 1)
        return 1;
    return 0;
}

int error_case_no_str_is_alpha(all_struct_t *all, int len_arg)
{
    int pass = 0; char **arg = parse_stdin(all->get_line, all);
    if (my_strcmp(arg[0], "unsetenv") == 0)
        return 0;
    if (arg[1][0] == '\'') {
        EXIT_W_ECHO_ERROR_("Unmatched '''.", 1);
    }
    if (char_isalpha(arg[1][0]) == 0) {
        if (my_strcmp(arg[0], "setenv") == 0
        && len_arg != 2 && arg[1][0] != '_') {
            EXIT_W_ECHO_ERROR_(ERROR_SETENV_FIRST_DOLLAR, 1)
        }
        if (my_strcmp(arg[0], "setenv") == 0
        && len_arg > 1 && arg[1][0] != '$' && arg[1][0] != '_') {
            EXIT_W_ECHO_ERROR_(ERROR_SETENV_FIRST_DOLLAR, 1)
        }
    }
    for (int e = 1; e != len_arg; e++)
        if (error_case_no_str_is_alpha_extend(all, arg, e, pass) == 1)
            return 1;
    return 0;
}
