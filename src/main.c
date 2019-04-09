/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/runner.h"

void free_struct(chara_t *chara, vege_t *vege, back_t *back, ground_t *ground)
{
    chara = malloc(sizeof(chara_t));
    vege = malloc(sizeof(vege_t));
    back = malloc(sizeof(back_t));
    ground = malloc(sizeof(ground_t));
    menu(back, chara, vege, ground);
    sfRenderWindow_destroy(back->window);
    free(chara);
    free(vege);
    free(back);
    free(ground);
}

int else_condition(int ac, int fd)
{
    chara_t *chara = NULL;
    vege_t *vege = NULL;
    back_t *back = NULL;
    ground_t *ground = NULL;

    if (ac != 2 || fd < 0) {
        write(2, "./my_runner: bad arguments 0 given but 1 is", 43);
        write(2, " required\n", 10);
        write(2, "retry with -h\n", 14);
        return (84);
    }
    if (ac == 2) {
        free_struct(chara, vege, back, ground);
        return (0);
    }
    return (0);
}

int condition(int ac, char **av, char **env, int fd)
{
    if (!env[0])
        return (84);
    else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (0);
    }
    else {
        else_condition(ac, fd);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    back_t *back = malloc(sizeof(back_t));
    int fd = open(av[1], O_RDONLY);

    back->map = malloc(sizeof(char) * READ_SIZE);
    read(fd, back->map, 1000);
    if (condition(ac, av, env, fd) == 84)
        return (84);
    free(back->map);
    free(back);
    return (0);
}
