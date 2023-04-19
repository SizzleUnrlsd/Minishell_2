/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** builtin_list
*/
#include "../../my.h"

int builtin_exit(all_struct_t *all, char *str)
{
    (void) str;
    COMMAND_FOUND;
    char **arg = parse_stdin(all->get_line, all);
    int len_arg = len_array(parse_stdin(all->get_line, all));
    if (len_arg == 2 && my_strlen(arg[1]) == 1)
        if (arg[1][0] > 47 && arg[1][0] < 58) {
            int a = my_get_nbr(arg[1]);
            ENDING_PROCESS_("exit", a)
        }
    exit_error(all, arg, len_arg);
    return 1;
}

int builtin_cd(all_struct_t *all, char *str)
{
    (void) str;
    char *home = NULL;
    COMMAND_FOUND;
    char **arg = parse_stdin(all->get_line, all);
    int len_arg = len_array(parse_stdin(all->get_line, all));

    if (build_cd_foo(all, home, arg, len_arg) == 1)
        return 0;

    if (build_cd_bar(all, arg) == 1)
        return 0;

    if (build_cd_foobar(all, arg, len_arg) == 1)
        return 0;
    return 0;
}

int builtin_setenv(all_struct_t *all, char *str)
{
    (void) str;
    int in_env = 0;
    int mode_builtin = 1;
    COMMAND_FOUND;
    char **arg = parse_stdin(all->get_line, all);
    format_arg(arg);
    int len_arg = len_array(arg);
    if (len_arg == 1) {
        print_array(all->set_env->env_array, '\n');
        return 0;
    }
    if (error_case_no_str_is_alpha(all, len_arg) == 1)
        return 0;
    if (len_arg != 1)
        already_in_env(all, mode_builtin);
    if (len_arg > 3) {
        EXIT_W_ECHO_ERROR_("setenv: Too many arguments.", 1)
    }
    builtin_setenv_ext(all, len_arg, in_env, mode_builtin);
    return 0;
}

int builtin_unsetenv(all_struct_t *all, char *str)
{
    (void) str;
    int count = 0; int in_env = 0; all->mode = 0;
    int mode_builtin = 0;
    COMMAND_FOUND;
    char **arg = parse_stdin(all->get_line, all);
    format_arg(arg);
    int len_arg = len_array(arg);
    int len_env = len_array(all->set_env->env_array);
    if (error_case_no_str_is_alpha(all, len_arg) == 3)
        return 0;
    count = already_in_env(all, mode_builtin);
    if (len_env == count)
        return 0;
    if (len_arg == 1) {
        EXIT_W_ECHO_ERROR_("unsetenv: Too few arguments.", 1);
    }
    builtin_unsetenv_ext(all, in_env, len_arg);
    return 0;
}

int builtin_env(all_struct_t *all, char *str)
{
    (void) str;
    COMMAND_FOUND;
    print_array(all->set_env->env_array, '\n');
    return 0;
}
