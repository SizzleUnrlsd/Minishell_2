/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** auto_completion
*/
#include "../my.h"

char **get_files(all_struct_t *all, const char *partial_name)
{
    DIR *dir;
    struct dirent *dirent;
    uint32_t count = 0;
    char **files = NULL;

    dir = opendir(".");
    if (dir == NULL)
        return NULL;
    while ((dirent = readdir(dir)) != NULL) {
        if (my_strncmp(partial_name, dirent->d_name, my_strlen(partial_name)) == 0) {
            count++;
            files = my_realloc(files, (count * sizeof(char *)));
            files[count - 1] = my_strdup(dirent->d_name, all);
        }
    }
    closedir(dir);
    files = my_realloc(files, ((count + 1) * sizeof(char *)));
    files[count] = NULL;
    return files;
}

int32_t auto_completion(all_struct_t *all, const char *partial_name)
{
    int i = 0;
    char **files = NULL;

    files = get_files(all, partial_name);
    if (files == NULL || files[0] == NULL)
        return 1;

    for (i = 0; files[i] != NULL; i++) {
        print_str(files[i], '\t', true, 1);
    }
    my_putchar('\n', 1);
    return 0;
}

void wait_key(all_struct_t *all, int read, char *line)
{
    char *tmp = my_strdup(line, all);
    tmp[read - 1] = '\0';

    if (line[0] == '\n') {
        return;
    }
    if (auto_completion(all, tmp) == 0) {
        all->command_not_found++;
        all->built_all_type_env++;
    }
    return;
}
