/*
** EPITECH PROJECT, 2018
** move_para
** File description:
** Infinity map
*/

#include "../include/runner.h"

void move_para(back_t *back, vege_t *vege, ground_t *ground)
{
    sfVector2f move = {-2.5, 0};

    sfSprite_move(vege->mountain_s, (sfVector2f){move.x / 5, 0});
    sfSprite_move(ground->ground_s, (sfVector2f){move.x / 0.9, 0});
    sfSprite_move(back->cloud_s, (sfVector2f){move.x / 2, 0});
    sfSprite_move(back->far_cloud2_s, (sfVector2f){move.x / 4, 0});
    if (sfSprite_getPosition(vege->mountain_s).x <= -1920)
        sfSprite_setPosition(vege->mountain_s, (sfVector2f){0, 0});
    if (sfSprite_getPosition(ground->ground_s).x <= -1920)
        sfSprite_setPosition(ground->ground_s, (sfVector2f){0, 0});
    if (sfSprite_getPosition(back->cloud_s).x <= -1920)
        sfSprite_setPosition(back->cloud_s, (sfVector2f){0, 0});
    if (sfSprite_getPosition(back->far_cloud2_s).x <= -1920)
        sfSprite_setPosition(back->far_cloud2_s, (sfVector2f){0, 0});
}
