/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** exit_error_case
*/
#include  "../../../my.h"

int exit_error_extend(all_struct_t *all, char **arg,
                    int count, int expected_value)
{
    if (count == my_strlen(arg[1]) && count > 0) {
        expected_value = my_get_nbr(arg[1]);
        ENDING_PROCESS_("exit", expected_value)
    } else if (count > 0 && (arg[1][0] > 47 && arg[1][0] < 58)) {
        EXIT_W_ECHO_ERROR_("exit: Badly formed number.", 1);
    }
    return 0;
}

int exit_error(all_struct_t *all, char **arg, int len_arg)
{
    if (len_arg == 2) {
        int count = 0;
        int expected_value = 0;
        for (int i = 0; arg[1][i]; i++)
            (arg[1][i] > 47 && arg[1][i] < 58 ? count++ : 0);
        if (exit_error_extend(all, arg, count, expected_value) == 1)
            return 1;
    }
    if (len_arg != 1) {
        EXIT_W_ECHO_ERROR_("exit: Expression Syntax.", 1);
    } else if (len_arg == 1) {
        ENDING_PROCESS_("exit", 0)
    }
    return 0;
}
