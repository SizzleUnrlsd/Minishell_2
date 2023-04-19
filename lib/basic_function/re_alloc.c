/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-pushswap-hugo.payet
** File description:
** re_alloc
*/
#include "../../my.h"

char **re_alloc(all_struct_t *all, char **src, int len_src, int len_dest)
{
    int i = 0, e = 0;
    char **nouveau = (char**)
    malloc_attribut(sizeof(char*) * (len_src + len_dest + 2), all);
    while (i != len_src) {
        nouveau[i] = my_strdup(src[i], all);
        i++;
    }
    while (e != len_dest) {
        nouveau[i] = "\0";
        i++;
        e++;
    }
    nouveau[i + 1] = NULL;
    for (int i = 0; i != len_src; i++)
        free(src[i]);
    free(src);
    return nouveau;
}
