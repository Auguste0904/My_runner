/*
** EPITECH PROJECT, 2018
** move_mario
** File description:
** Anim the sprite
*/

#include "../include/runner.h"

void move_rect(chara_t *chara, int offset, int max_value)
{
    static int left = -27;
    sfIntRect rectangle = {left, 578, 150, 245};
    float seconde;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconde = chara->time.microseconds / 1000000.0;
    if (seconde > 0.125) {
        left = left + offset;
        sfClock_restart(chara->clock);
    }
    if (left >= max_value)
        left = -27;
    sfSprite_setTextureRect(chara->chara_s, rectangle);
}

void move_rect_down(chara_t *chara, int offset, int max_value)
{
    static int left = -27;
    sfIntRect rectangle = {left, 1230, 230, 170};
    float seconde;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconde = chara->time.microseconds / 1000000.0;
    if (seconde > 0.125) {
        left = left + offset;
        sfClock_restart(chara->clock);
    }
    if (left >= max_value)
        left = -27;
    sfSprite_setTextureRect(chara->chara_s, rectangle);
}

void move_rect_jump(chara_t *chara, float offset, int max_value)
{
    static int left = -27;
    sfIntRect rectangle = {left, 980, 149, 200};
    float seconde;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconde = chara->time.microseconds / 1000000.0;
    if (seconde > 0.125) {
        left = left + offset;
        sfClock_restart(chara->clock);
    }
    if (left >= max_value)
        left = -27;
    sfSprite_setTextureRect(chara->chara_s, rectangle);
}

void move_rect_bird(chara_t *chara, int offset, int max_value)
{
    static int left = 0;
    sfIntRect rectangle = {left, 0, 170, 100};
    float seconde;

    chara->time = sfClock_getElapsedTime(chara->clock_bird);
    seconde = chara->time.microseconds / 1000000.0;
    if (seconde > 0.125) {
        left = left + offset;
        sfClock_restart(chara->clock_bird);
    }
    if (left >= max_value)
        left = 0;
    sfSprite_setTextureRect(chara->bird_s, rectangle);
}

void move_rect_wolf(chara_t *chara, int offset, int max_value)
{
    static int left = 0;
    sfIntRect rectangle = {left, 0, 102, 56};
    float seconde;

    chara->time = sfClock_getElapsedTime(chara->clock_wolf);
    seconde = chara->time.microseconds / 1000000.0;
    if (seconde > 0.145) {
        left = left + offset;
        sfClock_restart(chara->clock_wolf);
    }
    if (left >= max_value)
        left = 0;
    sfSprite_setTextureRect(chara->wolf_s, rectangle);
}
