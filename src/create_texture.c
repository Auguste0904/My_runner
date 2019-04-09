/*
** EPITECH PROJECT, 2018
** create_texture
** File description:
** Create the textures
*/

#include "../include/runner.h"

void score(back_t *back)
{
    back->i = 1;
    sfVector2f pos_init = {40, 20};
    sfVector2f pos_init_score = {260, 18};

    back->cl_score = sfClock_create();
    back->score = sfText_create();
    back->score_nb = sfText_create();
    back->font = sfFont_createFromFile("text/mario_font.ttf");
    sfText_setCharacterSize(back->score, 50);
    sfText_setCharacterSize(back->score_nb, 50);
    sfText_setFont(back->score, back->font);
    sfText_setFont(back->score_nb, back->font);
    sfText_setString(back->score, "Score :");
    sfText_setPosition(back->score, pos_init);
    sfText_setPosition(back->score_nb, pos_init_score);
}

void clock_score(back_t *back)
{
    if (sfClock_getElapsedTime(back->cl_score).microseconds >= 80000) {
        back->i += 1;
        sfClock_restart(back->cl_score);
    }
    if (back->i == 100) {
        back->win_sound = sfMusic_createFromFile("sound/win.wav");
        sfMusic_play(back->win_sound);
        sfMusic_stop(back->music);
        sfMusic_setVolume(back->win_sound, 100);
        end_menu_win(back);
    }
    sfText_setString(back->score_nb, my_itoa(back->i));
    sfRenderWindow_drawText(back->window, back->score_nb, NULL);
}

void background(back_t *back)
{
    back->background_s = sfSprite_create();
    back->background = sfTexture_createFromFile("img/sky.png", NULL);
    sfSprite_setTexture(back->background_s, back->background, sfTrue);
    back->cloud_s = sfSprite_create();
    back->cloud = sfTexture_createFromFile("img/clouds.png", NULL);
    sfSprite_setTexture(back->cloud_s, back->cloud, sfTrue);
    back->far_cloud_s = sfSprite_create();
    back->far_cloud = sfTexture_createFromFile("img/far_clouds.png", NULL);
    sfSprite_setTexture(back->far_cloud_s, back->far_cloud, sfTrue);
    back->far_cloud2_s = sfSprite_create();
    back->far_cloud2 = sfTexture_createFromFile("img/far_clouds2.png", NULL);
    sfSprite_setTexture(back->far_cloud2_s, back->far_cloud2, sfTrue);
    back->fog_s = sfSprite_create();
    back->fog = sfTexture_createFromFile("img/fog.png", NULL);
    sfSprite_setTexture(back->fog_s, back->fog, sfTrue);
}

void chara_sprite(chara_t *chara)
{
    chara->chara_s = sfSprite_create();
    chara->chara = sfTexture_createFromFile("img/chara.png", NULL);
    sfSprite_setTexture(chara->chara_s, chara->chara, sfTrue);
    sfSprite_setScale(chara->chara_s, (sfVector2f){0.8, 0.8});
    chara->wolf_s = sfSprite_create();
    chara->wolf = sfTexture_createFromFile("img/wolf_cut.png", NULL);
    sfSprite_setTexture(chara->wolf_s, chara->wolf, sfTrue);
    sfSprite_setScale(chara->wolf_s, (sfVector2f){2, 2});
    chara->bird_s = sfSprite_create();
    chara->bird = sfTexture_createFromFile("img/bird.png", NULL);
    sfSprite_setTexture(chara->bird_s, chara->bird, sfTrue);
}

void sol(ground_t *ground, vege_t *vege)
{
    ground->ground_s = sfSprite_create();
    ground->ground = sfTexture_createFromFile("img/ground.png", NULL);
    sfSprite_setTexture(ground->ground_s, ground->ground, sfTrue);
    vege->mountain_s = sfSprite_create();
    vege->mountain = sfTexture_createFromFile("img/forest.png", NULL);
    sfSprite_setTexture(vege->mountain_s, vege->mountain, sfTrue);
}
