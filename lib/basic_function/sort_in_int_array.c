/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** sort_in_int_array
*/
#include "../../my.h"

void sort_in_int_array_extend(int *a, int i, int j, int temp)
{
    if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return;
}

void sort_in_int_array(int *a, int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            sort_in_int_array_extend(a, i, j, temp);
        }
    }
    return;
}
