/*
** EPITECH PROJECT, 2018
** draw
** File description:
** Draw textures
*/

#include "../include/runner.h"

void draw_back(back_t *back)
{
    sfRenderWindow_drawSprite(back->window, back->background_s, NULL);
    sfRenderWindow_drawSprite(back->window, back->fog_s, NULL);
    sfRenderWindow_drawSprite(back->window, back->far_cloud_s, NULL);
}

void move_vege(vege_t *vege, back_t *back, ground_t *ground)
{
    sfVector2f move_forward = {1920, 0};
    sfVector2f move_backward = {-1920, 0};

    sfRenderWindow_drawSprite(back->window, vege->mountain_s, NULL);
    sfSprite_move(vege->mountain_s, move_forward);
    sfRenderWindow_drawSprite(back->window, vege->mountain_s, NULL);
    sfSprite_move(vege->mountain_s, move_backward);
    sfRenderWindow_drawSprite(back->window, ground->ground_s, NULL);
    sfSprite_move(ground->ground_s, move_forward);
    sfRenderWindow_drawSprite(back->window, ground->ground_s, NULL);
    sfSprite_move(ground->ground_s, move_backward);
}

void move_back(back_t *back)
{
    sfVector2f move_forward = {1920, 0};
    sfVector2f move_backward = {-1920, 0};

    sfRenderWindow_drawSprite(back->window, back->cloud_s, NULL);
    sfSprite_move(back->cloud_s, move_forward);
    sfRenderWindow_drawSprite(back->window, back->cloud_s, NULL);
    sfSprite_move(back->cloud_s, move_backward);
    sfRenderWindow_drawSprite(back->window, back->far_cloud2_s, NULL);
    sfSprite_move(back->far_cloud2_s, move_forward);
    sfRenderWindow_drawSprite(back->window, back->far_cloud2_s, NULL);
    sfSprite_move(back->far_cloud2_s, move_backward);
}

void draw_para(back_t *back, vege_t *vege, ground_t *ground)
{
    move_vege(vege, back, ground);
    move_back(back);
}
