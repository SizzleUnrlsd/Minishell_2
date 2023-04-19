/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** realloc
*/
#include "../../my.h"

static void *my_memcpy(void *dest, const void *src, size_t n)
{
    if (dest == NULL || src == NULL)
        return NULL;
    char *d = dest;
    const char *s = src;
    size_t i = 0;
    do {
        d[i] = s[i];
        i++;
    } while (i < n);

    return dest;
}

void *my_realloc(void* ptr, size_t size)
{
    uint8_t* nouveau_ptr = NULL;
    if (size <= 0)
        return NULL;
    nouveau_ptr = malloc(size);
    if (nouveau_ptr != NULL && ptr != NULL) {
        my_memcpy(nouveau_ptr, ptr, size);
        free(ptr);
    }
    return nouveau_ptr;
}
