/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** cd
*/
#include "../../../my.h"

void set_new_old_pwd(all_struct_t *all, char *path, char *mess_env)
{
    free(all->get_line);
    int fmall = my_strlen(path);
    char *concat = concat_char_str(' ', mess_env, fmall, 1);
    garbage_collector(concat, all);
    char *final = my_strcat(concat, path);
    final = concat_char_str('\n', final, 1, 1);
    all->get_line = final;

    char **diff = my_str_to_word_array_custom(all, mess_env, ' ');

    if (pwd_already_ini_env(all, diff[1]) == 1)
        add_line_to_array(all, 3, 0);
    else
        add_line_to_array(all, 3, -3);

    return;
}

int build_cd_foo_extend(all_struct_t *all, char **arg, char *home, int len_arg)
{
    if (check_perm_dir(all, home) == 1)
        return 1;
    if ((home != NULL && len_arg == 1) ||
    ((my_strcmp(arg[1], "~") == 0) && home != NULL)) {
        all->cd_old_path = getcwd(NULL, 4096);
        garbage_collector(all->cd_old_path, all);
        chdir(home);
        all->cd_new_path = home;
        set_new_old_pwd(all, all->cd_old_path, "setenv OLDPWD");
        set_new_old_pwd(all, home, "setenv PWD");
        return 1;
    }
    return 0;
}

int build_cd_foo(all_struct_t *all, char *home, char **arg, int len_arg)
{
    struct stat st;
    home = find_home(all, home);
    if (stat(home, &st) == -1 && len_arg == 1) {
        EXIT_W_ECHO_ERROR_("cd: Can't change to home directory.", 1);
    }
    if ((home == NULL && len_arg == 2 && my_strcmp(arg[1], "~") == 0)) {
        EXIT_W_ECHO_ERROR_("No $home variable set.", 1);
    }
    if (stat(home, &st) == -1 && len_arg == 2 && my_strcmp(arg[1], "~") == 0) {
        print_str(home, 0, true, 2);
        EXIT_W_ECHO_ERROR_(": No such file or directory.", 1);
    }
    if ((home == NULL && len_arg == 1)) {
        EXIT_W_ECHO_ERROR_("cd: No home directory.", 1);
    }
    if (build_cd_foo_extend(all, arg, home, len_arg) == 1)
        return 1;
    return 0;
}

int build_cd_bar(all_struct_t *all, char **arg)
{
    if (my_strcmp(arg[1], "-") == 0) {
        if (all->cd_old_path == NULL && all->cd_new_path == NULL) {
            EXIT_W_ECHO_ERROR_(": No such file or directory.", 1);
        } else {
            char *path = getcwd(NULL, 4096);
            garbage_collector(path, all);
            set_new_old_pwd(all, path, "setenv OLDPWD");
            chdir(all->cd_old_path);
            all->cd_old_path = all->cd_new_path;
            all->cd_new_path = getcwd(NULL, 4096);
            garbage_collector(all->cd_new_path, all);
            set_new_old_pwd(all, all->cd_new_path, "setenv PWD");
        }
        return 1;
    }
    return 0;
}

int build_cd_foobar(all_struct_t *all, char **arg, int len_arg)
{
    if (len_arg == 2 && check_perm_dir(all, arg[1]) == 0) {
        all->cd_old_path = getcwd(NULL, 4096);
        garbage_collector(all->cd_old_path, all);
        set_new_old_pwd(all, all->cd_old_path, "setenv OLDPWD");
        int result = chdir(arg[1]);
        all->cd_new_path = getcwd(NULL, 4096);
        garbage_collector(all->cd_new_path, all);
        set_new_old_pwd(all, all->cd_new_path, "setenv PWD");
        if (is_dir(arg[1]) == 1) {
            print_str(arg[1], 0, true, 2);
            EXIT_W_ECHO_ERROR_(": Not a directory.", 1);
        }
        if (result == -1) {
            print_str(arg[1], 0, true, 2);
            EXIT_W_ECHO_ERROR_(": No such file or directory.", 1);
        }
        return 1;
    }
    return 0;
}
