/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** library with prototypes
*/

#ifndef MY_H_
    #define MY_H_
    #define BUILT_IN_NB (0)
    #define RD_TTY (all->print)
    #define BINARY  (all->binary)
    #define LEN_ARRAY_STRUCT (100000)
    #define ENV_PATH (env_set->path_env)
    #define BUILT_INT_EXIT (all->built_exit)
    #define ALL_ENV (all->built_all_type_env)
    #define ENV_SET_ARRAY (env_set->env_array)
    #define FULL_ARRAY_ENV (all->set_env->env_array)

    #define ERROR_SET_UNSET_FIRST_DOLLAR "unsetenv: \
Variable name must begin with a letter."
    #define ERROR_SET_UNSET_LAST_DOLLAR  "unsetenv: \
Variable name must contain alphanumeric characters."
    #define ERROR_SETENV_FIRST_DOLLAR "setenv: \
Variable name must begin with a letter."
    #define ERROR_SETENV_LAST_DOLLAR  "setenv: \
Variable name must contain alphanumeric characters."
    #define ERROR_SET_UNSET_DOLLAR ": Undefined variable."


    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>

    #include <dirent.h>
    #include <string.h>
    #include <errno.h>
    #include <stdarg.h>
    #include <stdint.h>

    #include <fcntl.h>
    #include <sys/stat.h>

    #include "struct.h"

#endif /* MY_H_ */

#ifndef COMMAND_FOUND
    #define COMMAND_FOUND \
    all->command_not_found++;  \
    all->built_all_type_env++;
#endif

#ifndef ERROR_MESSAGE_
    #define ERROR_MESSAGE_
    #define SWITCH_ERROR_(mode, var2, var3)\
    if (mode == 0) print_str(var2, '\n', RD_TTY, 2);

#endif

#ifndef RETURN_VALUE_NO_VOID_
    #define RETURN_VALUE_NO_VOID_
    #define EXIT_W_ECHO_ERROR_(str, return_value)\
    if (return_value == 1 && RD_TTY == 1) { \
        print_str(str, '\n', true, 2); \
        all->status = return_value; \
        return return_value; \
    } \
    if (return_value == 1 && RD_TTY == 0) { \
        print_str(str, '\n', true, 2); \
        all->status = return_value; \
        bye(all); \
        exit(return_value); \
    }

#endif

#ifndef EXPECTED_EXIT_
    #define EXPECTED_EXIT_
    #define ENDING_PROCESS_(const_char, int_expected) \
    print_str(const_char, '\n', RD_TTY, 1); \
    bye(all); \
    exit(int_expected); \

#endif

char *my_getch(int a);
int my_put_nbr(long nb);
int char_isalpha(char c);
int char_isdigit(char c);
int char_isspace(char c);
void format_arg(char **arg);
int my_strlen(char const *str);
int stat_copy(char const *str);
int my_get_nbr(char const *str);
char my_putchar(char c, int fd);
int my_get_key(int a, char *str);
int my_putstr(char const *str, int fd);
size_t my_strnlen(const char *s, size_t maxlen);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
void free_attribut(void *p, all_struct_t *all);
char *my_strdup(char const *src, all_struct_t *all);
char *my_strncpy(char *dest, char const *src, int n);
void *malloc_attribut(size_t size, all_struct_t *all);
int my_strncmp(char const *s1, char const *s2, int n);
void wait_key(all_struct_t *all, int read, char *line);
char **my_str_to_word_array_custom(all_struct_t *all, char *str, char c);
char **re_alloc(all_struct_t *all, char **src, int len_src, int len_dest);
void *my_realloc(void* ptr, size_t size);
char **my_str_to_word_array_custom_double(all_struct_t *all, char *str,
char c, char x);

int len_array(char **array);
all_struct_t *init_all(void);
char *remove_back_n(char *src);
void print_array(char **array, char c);
set_env_t *set_env(all_struct_t *all, char **env);
bool format_getline(all_struct_t *all, char *command);
char **cut_path_env(all_struct_t *all, char **array);
char **parse_stdin(char *command, all_struct_t *all);
void print_str(char const *str, char c, bool print, int fd);
char *del_one_char(all_struct_t *all, char **src, char *dest);
char *concat_char_str(char concat, char *str, int futur, int a);

void reset_var_shell(all_struct_t *all);
int builtin_cd(all_struct_t *all, char *str);
int builtin_env(all_struct_t *all, char *str);
char *find_home(all_struct_t *all, char *home);
int build_cd_bar(all_struct_t *all, char **arg);
int builtin_exit(all_struct_t *all, char *str);
int builtin_setenv(all_struct_t *all, char *str);
int check_perm_dir(all_struct_t *all, char *path);
int builtin_unsetenv(all_struct_t *all, char *str);
int pwd_already_ini_env(all_struct_t *all, char *str);
int exit_error(all_struct_t *all, char **arg, int len_arg);
int access_file(all_struct_t *all, char **path, char **env);
int builtin(all_struct_t *all, char **path, int *rd_builtin);
int error_case_no_str_is_alpha(all_struct_t *all, int len_arg);
int build_cd_foobar(all_struct_t *all, char **arg, int len_arg);
int build_cd_foo(all_struct_t *all, char *home, char **arg, int len_arg);
int open_directory(all_struct_t *all, char **path, char **arg, char **env);

int is_bin(char const *path);
int is_dir(char const *path);
int is_same_char(char const *path);
bool prompt_shell(all_struct_t *all);
int echo(all_struct_t *all, char *str);
void sort_in_int_array(int *a, int len);
int already_in_env(all_struct_t *all, int mode);
void parent_exit(all_struct_t *all, int wstatus);
void wait_key(all_struct_t *all, int read, char *line);
void builtin_unsetenv_ext(all_struct_t *all, int in_env, int len_arg);
void add_line_to_array(all_struct_t *all, int len_arg, int in_env);
int32_t prompt_function(all_struct_t *all, set_env_t *env_set,
char **env, char **arg);
void builtin_setenv_ext(all_struct_t *all, int len_arg,
int in_env, int mode_builtin);
int function_set_param_env(int i, char **env,
char **first_step,  all_struct_t *all);

void bye(all_struct_t *all);
void garbage_collector(void *p, all_struct_t *all);
void garbage_uncollector(garbage_collector_t *garbage);
garbage_collector_t **realloc_struct(garbage_collector_t **p,
size_t size, unsigned int len);
int ast_final(char *command, all_struct_t *all, char **env);
void redirection_append(node_t *node, all_struct_t *all, char **env);
char *node_to_string(node_t *node, all_struct_t *all);
void execute_command(char **arg, char **env, all_struct_t *all);
char *remove_space_before_string(const char *str, all_struct_t *all);
void remove_newline(char *str);
void parse_command(char *cmd, char **args);

node_t *create_node(nodetype type, char *value, node_t *left, node_t *right);
node_t *parse_pipe(char **input);
node_t *parse_redirect(char **input);
node_t *parse_argument(char **input);
void execute_pipeline(node_t *cmd1_node, node_t *cmd2_node,
all_struct_t *all, char **env);
void evaluate_ast(node_t *node, all_struct_t *all, char **env);
node_t *parse_semicolon(char **input);
char *my_strndup(const char *s, size_t n);
char *my_strstr(const char *haystack, const char *needle);
