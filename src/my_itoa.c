/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** my_itoa
*/

#include "../include/runner.h"

char *my_itoa(int nb)
{
    char *result;
    int size = -1;
    int size2 = 0;
    int i = nb;

    while (i != 0) {
        i /= 10;
        size += 1;
        size2 = size;
    }
    i = nb;
    result = malloc(sizeof(char) * (size + 4));
    while (size != -1) {
        result[size] = (i % 10) + 48;
        i /= 10;
        size -= 1;
    }
    result[size2 + 1] = '\0';
    return (result);
}
