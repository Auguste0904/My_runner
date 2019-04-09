/*
** EPITECH PROJECT, 2019
** cereate_all
** File description:
** Create all
*/

#include "../include/runner.h"

void create_flag(chara_t *chara)
{
    chara->flag_s = sfSprite_create();
    chara->flag = sfTexture_createFromFile("img/flag.png", NULL);
    sfSprite_setTexture(chara->flag_s, chara->flag, sfTrue);
    sfSprite_setPosition(chara->flag_s, (sfVector2f){5180, 770});
    sfSprite_setScale(chara->flag_s, (sfVector2f){0.3, 0.3});
}

void create_all(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground)
{
    chara->clock = sfClock_create();
    chara->clock_bird = sfClock_create();
    chara->clock_wolf = sfClock_create();
    back->music = sfMusic_createFromFile("sound/kirikou.ogg");
    sfMusic_play(back->music);
    sfMusic_setLoop(back->music, sfTrue);
    score(back);
    background(back);
    chara_sprite(chara);
    create_flag(chara);
    sol(ground, vege);
}
