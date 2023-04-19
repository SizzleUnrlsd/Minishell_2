/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct set_env_s {
        char **env_array;
        char **path_env;
    }set_env_t;

    typedef struct garbage_really_s {
        uint8_t *pointer;
        int32_t a;
        char padded[4];
    }garbage_really_t;

    typedef struct garbage_collector_s {
        uint8_t *pointer;
        u_int32_t index;
        char padded[4];
    }garbage_collector_t;

    typedef struct all_struct_s {
        set_env_t *set_env;
        garbage_collector_t **garbage;
        char *cd_old_path;
        char *get_line;
        char *cd_new_path;
        int *several_arg_builtin;
        int32_t binary;
        int32_t command_not_found;
        int32_t built_all_type_env;
        int32_t built_exit;
        int32_t built_nothing;
        int32_t len_arg;
        int32_t mode;
        int32_t status;
        uint32_t io;
        bool print;
        char padded[3];
    }all_struct_t;

    typedef struct bultin_list_s {
        char *index;
        int(*function)(all_struct_t *all, char *str);
    }bultin_list_t;

    typedef struct sig_error_s {
        uint8_t(*function)(all_struct_t *all, int32_t status);
        uint32_t index;
        char padded[4];
    }sig_error_t;

    typedef enum {
        NODE_SEMICOLON,
        NODE_PIPE,
        NODE_REDIRECT_IN,
        NODE_REDIRECT_OUT,
        NODE_REDIRECT_APPEND,
        NODE_REDIRECT_DUP_IN,
        NODE_ARGUMENT,
    }nodetype;

    typedef struct node_s {
        char *value;
        struct node_s *left;
        struct node_s *right;
        nodetype type;
        char padded[4];
    }node_t;

#endif /* !STRUCT_H_ */
