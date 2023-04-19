/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-hugo.payet
** File description:
** my_get_nbr
*/
#include "../../my.h"

int sign(char const *str)
{
    int b = 1;
    int a = 0;

    while (str[a] == '-' || str[a] == '+') {
        if (str[a] == '-') {
            b = b * (- 1);
        } else {
            b = b * 1;
        }
    a++;
    }
    return (b);
}

int my_get_nbr(char const *str)
{
    int a = 0;
    int result = 0;

    while ((str[a] >= '0' && str[a] <= '9')
    || (str[a] == '-' || str[a] == '+')) {
        if (str[a] >= 48 && str[a] <= 57) {
            result = result + (str[a] - 48);
            result = result * 10;
        }
        a++;
    }
    result = result * sign(str);
    result = result / 10;
    return (result);
}
