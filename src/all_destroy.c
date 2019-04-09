/*
** EPITECH PROJECT, 2018
** all_destroy
** File description:
** Destroy all
*/

#include "../include/runner.h"

void des_sprite(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground)
{
    sfSprite_destroy(chara->chara_s);
    sfTexture_destroy(chara->chara);
    sfSprite_destroy(chara->wolf_s);
    sfTexture_destroy(chara->wolf);
    sfSprite_destroy(chara->bird_s);
    sfTexture_destroy(chara->bird);
    sfSprite_destroy(ground->ground_s);
    sfTexture_destroy(ground->ground);
    sfSprite_destroy(vege->mountain_s);
    sfTexture_destroy(vege->mountain);
    sfSprite_destroy(back->background_s);
    sfTexture_destroy(back->background);
    sfSprite_destroy(back->cloud_s);
    sfTexture_destroy(back->cloud);
    sfSprite_destroy(back->far_cloud_s);
    sfTexture_destroy(back->far_cloud);
    sfSprite_destroy(back->far_cloud2_s);
    sfTexture_destroy(back->far_cloud2);
    sfSprite_destroy(back->fog_s);
    sfTexture_destroy(back->fog);
}

void all_destroy(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground)
{
    des_sprite(back, chara, vege, ground);
    sfClock_destroy(chara->clock);
    sfClock_destroy(chara->clock_bird);
    sfClock_destroy(chara->clock_wolf);
    sfClock_destroy(back->cl_score);
    sfText_destroy(back->score);
}
