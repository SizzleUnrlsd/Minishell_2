/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** find_home
*/
#include "../../../my.h"

static char *my_strdup_bool(char const *src,  all_struct_t *all, bool stat)
{
    int a = 0;
    char *dest = NULL;

    if (stat == true)
        dest = (char*)malloc_attribut(sizeof(char) * (my_strlen(src) + 1), all);
    else
        dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char *find_home(all_struct_t *all, char *home)
{
    char **first_step = NULL;
    char **env = all->set_env->env_array;

    for (int i = 0; env[i]; i++) {
        first_step = my_str_to_word_array_custom(all, env[i], '=');
        if (my_strcmp(first_step[0], "HOME") == 0) {
            home = my_strdup_bool(first_step[1], all, true);
            return home;
        }
    }
    return NULL;
}
